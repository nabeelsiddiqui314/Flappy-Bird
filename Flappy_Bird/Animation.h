#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "templates.h"

class Animation
{
public:
	Animation(sf::RectangleShape& rect, std::vector<std::string> filepaths);
	~Animation();
public:
	void Animate(float dt);
private:
	sf::RectangleShape& m_rect;
	std::vector<const sf::Texture*> m_textures;
	Time m_DT;
	int m_index = 0;
};

