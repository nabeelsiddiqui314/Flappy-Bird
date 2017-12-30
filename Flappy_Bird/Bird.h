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
	void Update(bool playing);
	void Render(sf::RenderWindow& window);
	void Tap();
	const sf::RectangleShape& GetBird() const { return m_bird; }
private:
	void PreReadyAnimate();
private:
	sf::RectangleShape m_bird;
	Animation  m_animation;
	Time m_flyTime;
	Time m_preReadyFlyTime;
	Bird_State m_bird_state = FALLING;
	float m_rotation = 0;
	float m_preReadyVelocity = -1;
	Sound m_flySound;
};

