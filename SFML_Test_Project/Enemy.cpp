#include "Enemy.h"


void Enemy::initEnemy(sf::RenderTarget* tar)
{
	window_target = tar;
	enemy.setFillColor(color);
	enemy.setSize(size);
	enemy.setPosition(static_cast<float>(rand() % static_cast<int>(window_target->getSize().x - enemy.getSize().x)), 50.f);
	enemy.setOutlineThickness(outline_thickness);
	
}

bool Enemy::intersects(const sf::RectangleShape& rect)
{
	if (enemy.getGlobalBounds().intersects(rect.getGlobalBounds()))
	{
		enemy.move(0.f, -move_velocity_y); //move up so enemy does not stick to the floor
		return true;
	}
	else
	{
		return false;
	}
}

void Enemy::setPosition(sf::Vector2f pos)
{
	enemy.setPosition(pos);
}

sf::Vector2f Enemy::getPosition()
{
	return enemy.getPosition();
}

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::updateEnemy(Velocity velocity, const sf::RectangleShape& floor, bool input_released_x, bool input_released_y)
{
	//std::cout << "enemy pos: " << getPosition().y << "floor pos: " << floor.getPosition().y << "\n";

	if (enemy.getPosition().y < floor.getPosition().y - enemy.getSize().y) //in the air
	{
		std::cout << "in air" << "\n";
		move_velocity_y += 0.1f;
	}
	else if (enemy.getPosition().y > floor.getPosition().y - enemy.getSize().y) //on floor
	{
		std::cout << "on floor" << "\n";
		move_velocity_y = 0;	
		enemy.setPosition(enemy.getPosition().x , floor.getPosition().y - enemy.getSize().y);
	}
	else if (!input_released_y)
	{
		move_velocity_y -= 0.5f;
	}
	if (input_released_x && move_velocity_x > 0) //slow down +x
	{
		std::cout << "-x" << "\n";
		move_velocity_x -= 0.1f;
	}
	else if (input_released_x) //slow down -x
	{
		std::cout << "+x" << "\n";
		move_velocity_x += 0.1f;
	}
	enemy.move(move_velocity_x, move_velocity_y);
}

void Enemy::renderEnemy()
{
	window_target->draw(enemy);
}

std::pair<float, float> Enemy::getMaxVelocity()
{
	return std::pair<float, float>(move_velocity_x, move_velocity_y);
}
