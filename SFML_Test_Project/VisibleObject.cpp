#include "VisibleObject.h"

VisibleObject::VisibleObject()
{
}

VisibleObject::~VisibleObject()
{
}

void VisibleObject::initObject(sf::RenderTarget* tar)
{
	window_target = tar;
	texture.loadFromFile("C:/Programming/Projects/GameDev/SFML_Test_Project/The_gamer_goblin_.png");
	object.setTexture(texture);
	//object.setTextureRect(sf::IntRect(0, 150, 850, 1000));
	object.setPosition(0.f, static_cast<float>(window_target->getSize().y / 2 + 100 - object.getGlobalBounds().height*2));
	object.scale(sf::Vector2f(2.0f, 2.0f));
	//object.setColor(sf::Color(0, 0, 255));
	//object.setRotation(90);
}

void VisibleObject::updateObject()
{
	std::cout << object.getPosition().x << "\n";
	;
	if (object.getPosition().x >= (window_target->getSize().x - object.getGlobalBounds().width))
	{
		x_velocity = -1.5f;
		
		//flip orientation
		//object.scale(-1.f, 1.f);
	}
	else if (object.getPosition().x <= (0.f + object.getGlobalBounds().width/4))
	{
		x_velocity = 1.5f;

		//flip orientation
		//object.scale(-1.f, 1.f);
	}
	object.move(x_velocity, 0.f);
}


void VisibleObject::renderObject()
{
	window_target->draw(object);
}
