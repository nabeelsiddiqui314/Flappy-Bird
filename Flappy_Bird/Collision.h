#pragma once
#include<SFML/Graphics.hpp>

class Collision
{
public:
	Collision();
	~Collision();
public:
	static bool CheckCollision(sf::RectangleShape rect1, float scale1, sf::RectangleShape rect2, float scale2);
};

