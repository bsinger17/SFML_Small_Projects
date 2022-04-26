#pragma once
#include "includes.h"

class VisibleObject
{
private:

	// Attributes
	sf::Color color = sf::Color::Red;
	sf::Vector2<float> size = sf::Vector2(50.f, 50.f);
	sf::Vector2<float> start_position = sf::Vector2(30.f, 30.f);
	float outline_thickness = 1.f;

	//object logic
	//int move_state = 0;
	//float move_velocity_x = 3.f;
	//float move_velocity_y = 3.f;

	//VisibleObject objects
	sf::Texture texture;
	sf::Sprite object;
	sf::RenderTarget* window_target = nullptr; //render your object here

	//private member functions


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

