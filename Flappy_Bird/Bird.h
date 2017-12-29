#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include "Variables.h"

enum Bird_State {
	FLYING,
	FALLING
};

class Bird
{
public:
	Bird();
	~Bird();
public:
	void Update(bool fly);
	void Render(sf::RenderWindow& window);
	void Tap();
	const sf::RectangleShape& GetBird() const { return m_bird; }
private:
	sf::RectangleShape m_bird;
	Animation  m_animation;
	Time m_flyTime;
	Bird_State m_bird_state = FALLING;
	float m_rotation = 0;
};

