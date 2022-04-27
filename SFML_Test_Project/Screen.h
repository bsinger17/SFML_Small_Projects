#pragma once
#include "includes.h"
//make this a derived class of VisibleObject
class Screen
{
public:
	sf::Vector2<float> size = sf::Vector2(0.f, 0.f);
	sf::Vector2<float> start_position = sf::Vector2(0.f, 0.f);

	sf::Texture texture;
	sf::Sprite screen;
	sf::RenderTarget* window_target = nullptr; //render your object here


	Screen();
	~Screen();
	void initScreen(sf::RenderTarget* tar);
	void update();
	void render();
};

