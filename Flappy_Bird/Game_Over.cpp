#include "stdafx.h"
#include "Game_Over.h"

inline void Game_Over::init_sprites() {
	m_splash.setPosition(0, 0);
	m_splash.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	m_splash.setFillColor(sf::Color::White);

	m_gameOverTitle.setPosition((SCREEN_WIDTH / 2) - 146, SCREEN_HEIGHT / 6);
	m_gameOverTitle.tex.loadFromFile("./assets/game_over/title.png");
	m_gameOverTitle.setTexture(m_gameOverTitle.tex);

	m_gameOverBody.setPosition((SCREEN_WIDTH / 2) - 220, m_gameOverTitle.getPosition().y + 100);
	m_gameOverBody.tex.loadFromFile("./assets/game_over/body.png");
	m_gameOverBody.setTexture(m_gameOverBody.tex);

	m_button_restart.setSize(sf::Vector2f(140, 90));
	m_button_restart.setPosition((SCREEN_WIDTH / 2) - (m_button_restart.getGlobalBounds().width / 2), m_gameOverBody.getPosition().y + 250);
	m_button_restart.tex.loadFromFile("./assets/buttons/play.png");
	m_button_restart.setTexture(&m_button_restart.tex);
}

inline void Game_Over::init_medal(int score) {
	m_medal.setSize(sf::Vector2f(85, 85));
	m_medal.setPosition(m_gameOverBody.getPosition().x + 58, m_gameOverBody.getPosition().y + 88);

	if (score >= MINIMUM_BRONZE_SCORE && score < MINIMUM_SILVER_SCORE) {
		m_medal.tex.loadFromFile("./assets/medals/bronze.png");
	}
	else if (score >= MINIMUM_SILVER_SCORE && score < MINIMUM_GOLD_SCORE) {
		m_medal.tex.loadFromFile("./assets/medals/silver.png");
	}
	else if (score >= MINIMUM_GOLD_SCORE) {
		m_medal.tex.loadFromFile("./assets/medals/gold.png");
	}
	m_medal.setTexture(&m_medal.tex);
}

inline void Game_Over::init_text(int score) {
	m_score->setCharacterSize(30u);
	m_score->setPosition(m_gameOverBody.getPosition().x + 345, m_gameOverBody.getPosition().y + 75);
	m_score->setString(std::to_string(score));
	m_score->setFillColor(sf::Color::White);
	m_score->setOutlineColor(sf::Color::Black);
	m_score->setOutlineThickness(2);

	m_best->setCharacterSize(30u);
	m_best->setPosition(m_gameOverBody.getPosition().x + 351, m_gameOverBody.getPosition().y + 154);
	m_best->setFillColor(sf::Color::White);
	m_best->setOutlineColor(sf::Color::Black);
	m_best->setOutlineThickness(2);

	if (score > this->GetBest()) {
		this->WriteBest(score);
		m_best->setString(std::to_string(score));
	}
	else {
		m_best->setString(std::to_string(this->GetBest()));
	}
}

Game_Over::Game_Over(sf::RenderWindow& window, int score) : m_window(window) {
	m_score = new Text("./assets/fonts/FlappyFont.ttf");
	m_best  = new Text("./assets/fonts/FlappyFont.ttf");

	init_sprites();
	init_medal(score);
	init_text(score);
}

void Game_Over::SplashScreen() {
	if (!m_isSplashTimerStarted) {
		m_splashTime.clock.restart();
	}
	m_isSplashTimerStarted = true;

	m_splashTime.time = m_splashTime.clock.getElapsedTime();
	if (m_splashTime.time.asSeconds() < 0.25) {
		m_window.draw(m_splash);
	}
}

void Game_Over::RenderGameOver() {
	m_window.draw(m_gameOverTitle);
	m_window.draw(m_gameOverBody);
	m_window.draw(*m_score);
	m_window.draw(*m_best);
	m_window.draw(m_medal);
}

void Game_Over::RenderButton() {
	m_window.draw(m_button_restart);
}

bool Game_Over::IsRestartClicked() {
	return Interface::isClicked(m_window, m_button_restart);
}

int Game_Over::GetBest() {
	m_readBest.open("./data/Best.txt");
	std::string best;
	std::getline(m_readBest, best);
	m_readBest.close();
	return std::stoi(best, nullptr);
}

void Game_Over::WriteBest(int best) {
	m_writeBest.open("./data/Best.txt");
	m_writeBest.clear();
	m_writeBest << best;
	m_writeBest.close();
}

Game_Over::~Game_Over() {
	delete m_score;
	delete m_best;
}
