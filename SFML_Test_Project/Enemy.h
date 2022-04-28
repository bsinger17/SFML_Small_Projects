#pragma once
#include "includes.h"

class Enemy
{
private:

	//Enemy Attributes
	sf::Color color = sf::Color::Black;
	sf::Vector2<float> size = sf::Vector2(50.f, 50.f);
	sf::Vector2<float> start_position = sf::Vector2(30.f,30.f);
	float outline_thickness = 1.f;

	//enemy logic
	int move_state = 0;
	float move_velocity_x = 1.f;
	float move_velocity_y = 1.f;


	//Enemy objects
	sf::RectangleShape enemy;
	sf::RenderTarget* window_target = nullptr; //render your Enemy here

	//private member functions


public:
	//constructors
	Enemy();
	~Enemy();


	//public functions
	void initEnemy(sf::RenderTarget* tar);
	bool intersects(const sf::RectangleShape& rect);
	void updateEnemy(Velocity velocity, const sf::RectangleShape& floor, bool input_released_x, bool input_released_y);
	void renderEnemy();
	std::pair<float, float> getMaxVelocity();
	void setPosition(sf::Vector2f);
	sf::Vector2f getPosition();


};

