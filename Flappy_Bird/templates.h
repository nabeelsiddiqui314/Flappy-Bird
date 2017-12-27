#pragma once
#include <SFML/Graphics.hpp>

struct Rect : public sf::RectangleShape {
	sf::RectangleShape rect;
	sf::Texture tex;
};