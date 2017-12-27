#include "stdafx.h"
#include "Game.h"

inline void Game::init_backrounds() {
	m_sky.setSize(sf::Vector2f(550, 700));
	m_sky.setPosition(0, 0);
	m_sky.tex.loadFromFile("./assets/backrounds/sky.png");
	m_sky.setTexture(&m_sky.tex);
}

Game::Game() {
	init_backrounds();
}


void Game::HandleInput(sf::RenderWindow& window) {
	
}

void Game::Update(sf::RenderWindow& window) {
	m_ground.Scroll();
}

void Game::Render(sf::RenderWindow& window) {
	window.draw(m_sky);
	m_ground.Render(window);
}


Game::~Game() {
}
