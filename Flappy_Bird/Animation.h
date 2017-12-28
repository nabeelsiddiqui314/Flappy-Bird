#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "templates.h"

class Animation
{
public:
	Animation(std::vector<std::string> filepaths);
	~Animation();
public:
	void Animate(sf::RectangleShape& sprite, float dt);
private:
	std::vector<const sf::Texture*> m_textures;
	Time m_DT;
	int m_index = 0;
};

