#pragma once
#include "State.h"
#include "ScrollGround.h"
#include "Pipes.h"
#include "Bird.h"
#include "Collision.h"

enum GameState {
	NOT_READY,
	PLAYING,
	GAME_OVER
};

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
	Rect          m_sky;
	ScrollGround* m_ground;
	Pipes*        m_pipes;
	Bird*         m_bird;
	GameState     m_state = NOT_READY;
	bool          m_isPlaying = false;
	Time          m_start;
	Text*         m_scoreText;
	unsigned int  m_score = 0;
};

