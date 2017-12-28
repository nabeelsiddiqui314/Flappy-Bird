#include "stdafx.h"
#include "Game.h"

inline void Game::init_backrounds() {
	m_sky.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	m_sky.setPosition(0, 0);
	m_sky.tex.loadFromFile("./assets/backrounds/sky.png");
	m_sky.setTexture(&m_sky.tex);
}

Game::Game() {
	init_backrounds();
	m_ground = new ScrollGround();
	m_pipes  = new Pipes(m_ground->GroundHeight());
	m_bird   = new Bird();
}


void Game::HandleInput(sf::RenderWindow& window) {
	m_start.time = m_start.clock.getElapsedTime();
	if (m_start.time.asSeconds() > 1) {
		if (!m_isPlaying) {
			if (Interface::isMouseInWindow(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				m_state = PLAYING;
				m_isPlaying = true;
			}
		}
	}
	if (m_state == PLAYING && Interface::isClicked(window, m_sky)) {
		m_bird->Tap();
	}
}

void Game::Update(sf::RenderWindow& window) {
	switch (m_state) {
	case NOT_READY:
		m_ground->Scroll();
		break;
	case PLAYING:
		m_ground->Scroll();
		m_pipes->Update();
		m_bird->Update();
		for (unsigned short int i = 0; i < m_pipes->GetPipes().size(); i++) {
			if (Collision::CheckCollision(m_bird->GetBird(), 0.6, m_pipes->GetPipes()[i], 0.6)) {
				m_state = GAME_OVER;
			}
		}
		break;
	case GAME_OVER:
		stateManager.SetState(new Game());
		break;
	}
}

void Game::Render(sf::RenderWindow& window) {
	window.draw(m_sky);
	m_pipes->Render(window);
	m_ground->Render(window);
	m_bird->Render(window);
}


Game::~Game() {
	delete m_ground;
	delete m_pipes;
}
