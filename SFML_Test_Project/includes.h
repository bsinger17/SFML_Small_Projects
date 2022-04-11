#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>
#include <map>

struct Velocity
{
	float x = 0.f;
	float y = 0.f;
};