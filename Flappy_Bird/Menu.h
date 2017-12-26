#pragma once
#include "State.h"
#include <iostream>

class Menu : public State
{
public:
	 Menu();
	~Menu();
public:
	void HandleInput(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);
};

