#include "Screen.h"

Screen::Screen()
{
}

Screen::~Screen()
{
}

void Screen::initScreen(sf::RenderTarget* tar)
{
	window_target = tar;
	size = sf::Vector2<float>(tar->getSize().x, tar->getSize().y);
	texture.loadFromFile("C:/Programming/Projects/GameDev/SFML_Test_Project/Background_for_fighting_area_.png");
	screen.setTexture(texture);
	screen.setPosition(0.f, 0.f);
}

void Screen::update()
{
	//do nothing
}

void Screen::render()
{
	window_target->draw(screen);
}


