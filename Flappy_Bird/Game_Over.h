#pragma once
#include <SFML/Graphics.hpp>
#include "templates.h"
#include "Variables.h"
#include "Interface.h"
#include <fstream>

class Game_Over
{
public:
	Game_Over(sf::RenderWindow& window, int score);
	~Game_Over();
public:
	void SplashScreen();
	void RenderGameOver();
	void RenderButton();
	int  GetBest();
	void WriteBest(int best);
	bool IsRestartClicked();
private:
	inline void init_sprites();
	inline void init_medal(int score);
	inline void init_text(int score);
private:
	sf::RenderWindow& m_window;
	Text*  m_score;
	Text*  m_best;
	Sprite m_gameOverTitle;
	Sprite m_gameOverBody;
	Time   m_splashTime;
	sf::RectangleShape m_splash;
	bool m_isSplashTimerStarted = false;
	Rect m_medal;
	Rect m_button_restart;

	std::ifstream m_readBest;
	std::ofstream  m_writeBest;
};

