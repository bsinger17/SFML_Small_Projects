#pragma once
#ifndef GAME_H
#define GAME_H

/*
	Class for Game engine
*/



#include "includes.h"
#include "Enemy.h"
#include "VisibleObject.h"
#include "Screen.h"


//Window sizes
constexpr int WindowHeight = 600;
constexpr int WindowWidth = 800;

class Game
{
private:

	//private members
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;
	std::string GameTitle;
	bool input_key_released_x;
	bool input_key_released_y;

	//mouse positions
	sf::Vector2i mousePositionWindow;
	sf::Vector2i mousePositionScreen;
	sf::Vector2i mousePositionView;

	//Game Logic
	int enemy_move_state = 0;
	Velocity velocity{};

	//Game Objects
	Screen screen;
	Enemy enemy;
	VisibleObject sprite;
	sf::RectangleShape floor;


	//private member functions
	void initVariables();
	void initWindow();
	void initGameObjects();
	void pollEvents();


public:
	//constructors / destructors
	Game();
	~Game();

	//accessors
	const bool running() const;

	//public member functions
	void update();
	void renderEnemies(); 
	void render();
	void updateMousePositions();

};

#endif
