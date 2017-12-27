#pragma once
#include <SFML/Graphics.hpp>
#include "templates.h"
#include "Interface.h"
#include <iostream>

class ScrollGround
{
public:
	ScrollGround(Rect& ground);
	~ScrollGround();
private:
	
public:
	Rect& m_ground;
};

