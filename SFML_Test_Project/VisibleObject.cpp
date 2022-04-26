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
	texture.loadFromFile("C:/Programming/Projects/GameDev/SFML_Test_Project/sprite-2d-computer-graphics-orb-sphere-ball-orb-ce50834cd9a51d0ecfc28c6471984073.png");
	object.setTexture(texture);
	object.setTextureRect(sf::IntRect(0, 150, 850, 1000));
	object.setPosition(0.f, 0.f);
	object.scale(sf::Vector2f(0.1f, 0.1f));
	object.setColor(sf::Color(0, 0, 255));
	//object.setRotation(90);
}

void VisibleObject::updateObject()
{
	object.move(0.5f, 0.5f);
}

void VisibleObject::renderObject()
{
	window_target->draw(object);
}
