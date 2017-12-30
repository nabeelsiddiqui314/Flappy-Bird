#include "stdafx.h"
#include "Game.h"

inline void Game::init_rects() {
	m_sky.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	m_sky.setPosition(0, 0);
	m_sky.tex.loadFromFile("./assets/backrounds/sky.png");
	m_sky.setTexture(&m_sky.tex);
}

inline void Game::init_scoreText() {
	m_scoreText->setCharacterSize(50u);
	m_scoreText->setOrigin(m_scoreText->getGlobalBounds().width / 2, m_scoreText->getGlobalBounds().height / 2);
	m_scoreText->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	m_scoreText->setString("0");
	m_scoreText->setOutlineColor(sf::Color::Black);
	m_scoreText->setOutlineThickness(4);
}

inline void Game::init_sounds() {
	m_hit.buffer.loadFromFile("./assets/sounds/hit.wav");
	m_point.buffer.loadFromFile("./assets/sounds/point.wav");
	m_hit.setBuffer(m_hit.buffer);
	m_point.setBuffer(m_point.buffer);
}

Game::Game() {
	init_rects();
	m_ground    = new ScrollGround();
	m_pipes     = new Pipes(m_ground->GroundHeight());
	m_bird      = new Bird();
	m_scoreText = new Text("./assets/fonts/FlappyFont.ttf");
	init_scoreText();
	init_sounds();
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
		m_bird->Update(false);
		break;
	case PLAYING:
		m_ground->Scroll();
		m_pipes->Update();
		m_bird->Update(true);
		for (unsigned short int i = 0; i < m_pipes->GetPipes().size(); i++) {
			if (Collision::CheckCollision(m_bird->GetBird(), 0.6, m_pipes->GetPipes()[i], 0.6)) {
				m_hit.play();
				m_gameOver = new Game_Over(window, m_score);
				m_state = GAME_OVER;
			}
		}
		for (unsigned short int i = 0; i < m_ground->GetGround().size(); i++) {
			if (Collision::CheckCollision(m_bird->GetBird(), 0.6, m_ground->GetGround()[i], 0.6)) {
				m_hit.play();
				m_gameOver = new Game_Over(window, m_score);
				m_state = GAME_OVER;
			}
		}
		if (m_state != GAME_OVER) {
			for (unsigned short int i = 0; i < m_pipes->GetScroringPipes().size(); i++) {
				if (Collision::CheckCollision(m_bird->GetBird(), 0.6, m_pipes->GetScroringPipes()[i], 0.6)) {
					m_pipes->GetScroringPipes().erase(m_pipes->GetScroringPipes().begin() + i);
					m_point.play();
					m_score++;
					m_scoreText->setString(std::to_string(m_score));
				}
			}
		}
		break;
	case GAME_OVER:	
		if (m_gameOver->IsRestartClicked()) {
			stateManager.SetState(new Game());
		}
		break;
	}
}

void Game::Render(sf::RenderWindow& window) {
	window.draw(m_sky);
	m_pipes->Render(window);
	m_ground->Render(window);
	m_bird->Render(window);
	switch (m_state) {
	case NOT_READY:
		break;
	case PLAYING:
		window.draw(*m_scoreText);
		break;
	case GAME_OVER:
		m_gameOver->RenderGameOver();
		m_gameOver->RenderButton();
		m_gameOver->SplashScreen();
		break;
	}
}


Game::~Game() {
	delete m_ground;
	delete m_pipes;
	delete m_bird;
	delete m_scoreText;
	if (m_gameOver != nullptr) {
		delete m_gameOver;
	}
}
