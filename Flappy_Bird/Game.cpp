#include "stdafx.h"
#include "Game.h"

inline void Game::init_backrounds() {
	m_sky.setSize(sf::Vector2f(550, 700));
	m_sky.setPosition(0, 0);
	m_sky.tex.loadFromFile("./assets/backrounds/sky.png");
	m_sky.setTexture(&m_sky.tex);

	m_ground.setSize(sf::Vector2f(550, 100));
	m_ground.setPosition(0, 620);
	m_ground.tex.loadFromFile("./assets/backrounds/land.png");
	m_ground.setTexture(&m_ground.tex);
}

Game::Game() : m_scrollGround(m_ground) {
	init_backrounds();
}


void Game::HandleInput(sf::RenderWindow& window) {
	
}

void Game::Update(sf::RenderWindow& window) {
	
}

void Game::Render(sf::RenderWindow& window) {
	window.draw(m_sky);
	window.draw(m_ground);
}


Game::~Game() {
}
