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

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::updateEnemy(Velocity velocity)
{
	enemy.move(velocity.x, velocity.y);
}

void Enemy::renderEnemy()
{
	window_target->draw(enemy);
}

std::pair<float, float> Enemy::getMaxVelocity()
{
	return std::pair<float, float>(move_velocity_x, move_velocity_y);
}
