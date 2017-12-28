#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include "Variables.h"

class Bird
{
public:
	Bird();
	~Bird();
public:
	void Update();
	void Render(sf::RenderWindow& window);
	const sf::RectangleShape& GetBird() const { return m_bird; }
private:
	sf::RectangleShape m_bird;
	Animation  m_animation;
};

