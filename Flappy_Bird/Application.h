#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Menu.h"

class Application
{
public:
	 Application();
	~Application();
public:
	void Run();
private:
	sf::RenderWindow m_mainWindow;
};

