#pragma once
#include <SFML/Graphics.hpp>

struct Rect : public sf::RectangleShape {
	sf::RectangleShape rect;
	sf::Texture tex;
};

struct Time {
	sf::Clock clock;
	sf::Time time;
};