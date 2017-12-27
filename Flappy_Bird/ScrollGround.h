#pragma once
#include <SFML/Graphics.hpp>
#include "templates.h"
#include "Interface.h"
#include <iostream>

class ScrollGround
{
public:
	 ScrollGround();
	~ScrollGround();
public:
	void Scroll();
	void Render(sf::RenderWindow& window);
private:
	void Move(float speed);
	void Repeat();
	int swap(int num);
public:
	Rect temp1;
	Rect temp2;
	std::vector<Rect> m_ground;
};

