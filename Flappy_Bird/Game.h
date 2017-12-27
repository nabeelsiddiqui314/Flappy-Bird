#pragma once
#include "State.h"
#include "ScrollGround.h"

class Game : public State
{
public:
	Game();
	~Game();
public:
	void HandleInput(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);
private:
	inline void init_backrounds();
private:
	Rect m_sky;
	Rect m_ground;
	ScrollGround m_scrollGround;
};

