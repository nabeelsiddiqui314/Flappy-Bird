#pragma once
#include <SFML/Graphics.hpp>

struct Rect : public sf::RectangleShape {
	sf::Texture tex;
};

struct Sprite : public sf::Sprite{
	sf::Texture tex;
};

struct Time {
	sf::Clock clock;
	sf::Time time;
};