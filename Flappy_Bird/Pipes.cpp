#include "stdafx.h"
#include "Pipes.h"


Pipes::Pipes(int groundHeight) : m_groundHeight(groundHeight) {
	m_pipeTopTex.loadFromFile("./assets/objects/top_pipe.png");
	m_pipeBottomTex.loadFromFile("./assets/objects/bottom_pipe.png");
	srand(time(NULL));
	m_yOffset = random(PIPE_DISTANCE + 50, m_groundHeight - 50);
}

void Pipes::Update() {
	m_frequency.time = m_frequency.clock.getElapsedTime();
	if (m_frequency.time.asSeconds() > PIPES_FREQUENCY) {
		this->SpawnTop();
		this->SpawnBottom();
		this->SpawnScoring();
		this->RandomizeOffset();
		m_frequency.clock.restart();
	}
	this->Move();
	this->Delete();
}

void Pipes::Render(sf::RenderWindow& window) {
	for (unsigned short int i = 0; i < m_pipes.size(); i++) {
		window.draw(m_pipes[i]);
	}
}

void Pipes::Move() {
	for (unsigned short int i = 0; i < m_pipes.size(); i++) {
		m_pipes[i].move(-MOVE_SPEED, 0);
	}
	for (unsigned short int i = 0; i < m_scoringPipes.size(); i++) {
		m_scoringPipes[i].move(-MOVE_SPEED, 0);
	}
}

void Pipes::RandomizeOffset() {
	int difference = random(50, 200);
	if (m_yOffset + difference > m_groundHeight - 50) {
		m_yOffset -= difference;
	}
	else if (m_yOffset - difference < PIPE_DISTANCE + 50) {
		m_yOffset += difference;
	}
	else {
		m_yOffset = m_yOffset + random(-difference, difference);
	}
}

void Pipes::SpawnTop() {
	sf::RectangleShape sprite;
	sprite.setSize(sf::Vector2f(69, 800));
	sprite.setTexture(&m_pipeTopTex);
	sprite.setPosition(SCREEN_WIDTH, m_yOffset - sprite.getGlobalBounds().height - PIPE_DISTANCE);
	m_pipes.push_back(sprite);
}

void Pipes::SpawnBottom() {
	sf::RectangleShape sprite;
	sprite.setSize(sf::Vector2f(69, 800));
	sprite.setTexture(&m_pipeBottomTex);
	sprite.setPosition(SCREEN_WIDTH, m_yOffset);
	m_pipes.push_back(sprite);
}

void Pipes::SpawnScoring() {
	sf::RectangleShape sprite;
	sprite.setSize(sf::Vector2f(69, SCREEN_HEIGHT));
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setPosition(SCREEN_WIDTH, 0);
	m_scoringPipes.push_back(sprite);
}

void Pipes::Delete() {
	for (unsigned short int i = 0; i < m_pipes.size(); i++) {
		if (m_pipes[i].getPosition().x + m_pipes[i].getGlobalBounds().width < 0) {
			m_pipes.erase(m_pipes.begin() + i);
		}
	}
	for (unsigned short int i = 0; i < m_scoringPipes.size(); i++) {
		if (m_scoringPipes[i].getPosition().x + m_scoringPipes[i].getGlobalBounds().width < 0) {
			m_scoringPipes.erase(m_scoringPipes.begin() + i);
		}
	}
}

const std::vector<sf::RectangleShape> &Pipes::GetPipes() const {
	return m_pipes;
}

std::vector<sf::RectangleShape> &Pipes::GetScroringPipes() {
	return m_scoringPipes;
}


Pipes::~Pipes() {

}
