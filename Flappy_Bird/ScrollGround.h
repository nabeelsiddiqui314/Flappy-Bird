#pragma once
#include <SFML/Graphics.hpp>
#include "templates.h"
#include "Variables.h"
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
	int GroundHeight() const { return m_ground[0].getPosition().y; }
private:
	void Move();
	void Repeat();
	int swap(int num);
public:
	Rect temp1;
	Rect temp2;
	std::vector<Rect> m_ground;
};

