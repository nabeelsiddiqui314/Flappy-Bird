#pragma once
#include "State.h"
#include "Game.h"

class Menu : public State
{
public:
	 Menu();
	~Menu();
public:
	void HandleInput(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);
private:
	inline void init_backround();
	inline void init_buttons();
private:
	Rect m_backroundImg;
	Rect m_title;
	Rect m_play_button;
};

