#pragma once
#include <SFML/Graphics.hpp>

class Interface
{
public:
	Interface();
	~Interface();
public:
	static bool isHovered(sf::RenderWindow& window, sf::RectangleShape& button);
	static void SetPointer(sf::RenderWindow& window, sf::RectangleShape& pointer, bool hideMouse);
	static bool isClicked(sf::RenderWindow& window, sf::RectangleShape& button);
	static bool isMouseInWindow(sf::RenderWindow& window);
};
