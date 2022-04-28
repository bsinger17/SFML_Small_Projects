#include "Game.h"


//private functions
void Game::initVariables()
{
	window = nullptr;
	videoMode.height = WindowHeight;
	videoMode.width = WindowWidth;
	GameTitle = "myGame";
	input_key_released_x = true;
	input_key_released_y = true;
}

void Game::initWindow()
{
	window = new sf::RenderWindow(videoMode, GameTitle, sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(60);
}

void Game::initGameObjects()
{
	enemy.initEnemy(window);
	sprite.initObject(window);
	screen.initScreen(window);
}



void Game::pollEvents()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) window->close();
			if (event.key.code == sf::Keyboard::Right) { velocity.x = enemy.getMaxVelocity().first; input_key_released_x = false; }
			if (event.key.code == sf::Keyboard::Left) { velocity.x = -enemy.getMaxVelocity().first; input_key_released_x = false;}
			if (event.key.code == sf::Keyboard::Down) { velocity.y = enemy.getMaxVelocity().second; input_key_released_y = false;}
			if (event.key.code == sf::Keyboard::Up) { velocity.y = -enemy.getMaxVelocity().second; input_key_released_y = false;}
			break;
		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::Right) { velocity.x -= 0.1f; input_key_released_x = true;}
			if (event.key.code == sf::Keyboard::Left) { velocity.x -= 0.f; input_key_released_x = true;}
			if (event.key.code == sf::Keyboard::Down) { velocity.y = 0.f; input_key_released_x = true;}
			if (event.key.code == sf::Keyboard::Up) { velocity.y = 0.f; input_key_released_x = true;}
			break;
		default:
			break;
		}
	}
}

//constructors and destructors
Game::Game()
{
	initVariables();
	initWindow();
	initGameObjects();
}

Game::~Game()
{
	delete window;
}

//accessors
const bool Game::running() const
{
	return window->isOpen();
}


//public functions
void Game::update()
{
	pollEvents();
	updateMousePositions();

	//"collision" with the floor
	//if (enemy.intersects(floor))  
	//{
	//	//velocity.x = 0;
	//	enemy.setPosition(sf::Vector2f(enemy.getPosition().x, floor.getPosition().y));
	//} 

	enemy.updateEnemy(velocity, floor, input_key_released_x, input_key_released_y);
	sprite.updateObject();
	//std::cout << "mouse position (x,y): " << sf::Mouse::getPosition(*window).x << "   " << sf::Mouse::getPosition(*window).y << "\n";
	//std::cout << "Number of Enemies: " << enemies.size() << "\n";
	//std::cout << "floor pos: " << floor.getPosition().y << "\n";
	//std::cout << "enemy pos: " << enemies[0].getPosition().y << "\n";

}

void Game::render()
{
	window->clear();
	screen.render();
	floor.setFillColor(sf::Color::White);
	floor.setSize(sf::Vector2(static_cast<float>(window->getSize().x), 3.f));
	floor.setPosition(sf::Vector2(0.f, static_cast<float>(window->getSize().y/2 + 100)));
	window->draw(floor);
	enemy.renderEnemy();
	sprite.renderObject();
	window->display();
}

void Game::updateMousePositions()
{
	//window mouse position
	mousePositionWindow = sf::Mouse::getPosition(*window);
}
