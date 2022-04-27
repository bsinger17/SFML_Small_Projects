#pragma once
#include "includes.h"

//make this a base class for future entities
class VisibleObject
{
private:

	//VisibleObject objects
	sf::Texture texture;
	sf::Sprite object;
	sf::RenderTarget* window_target = nullptr; //render your object here
	float x_velocity = 0.f;

public:
	//constructors
	VisibleObject();
	~VisibleObject();


	//public functions
	void initObject(sf::RenderTarget* tar);
	//bool intersects(const sf::RectangleShape& rect);
	void updateObject();
	void renderObject();



};

