#include "stdafx.h"
#include "Pipes.h"


Pipes::Pipes(int groundHeight) : m_groundHeight(groundHeight) {
	m_pipeTopTex.loadFromFile("./assets/objects/top_pipe.png");
	m_pipeBottomTex.loadFromFile("./assets/objects/bottom_pipe.png");
	srand(time(NULL));
}

void Pipes::Update() {
	m_frequency.time = m_frequency.clock.getElapsedTime();
	if (m_frequency.time.asSeconds() > PIPES_FREQUENCY) {
		this->RandomizeOffset();
		this->SpawnTop();
		this->SpawnBottom();
		m_frequency.clock.restart();
		std::cout << rand() % 10;
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
}

void Pipes::RandomizeOffset() {
	m_yOffset = (rand() % (m_groundHeight - 150)) + 150;
}

void Pipes::SpawnTop() {
	sf::Sprite sprite;
	sprite.setTexture(m_pipeTopTex);
	sprite.setPosition(SCREEN_WIDTH, m_yOffset - sprite.getGlobalBounds().height - PIPE_DISTANCE);
	m_pipes.push_back(sprite);
}

void Pipes::SpawnBottom() {
	sf::Sprite sprite;
	sprite.setTexture(m_pipeBottomTex);
	sprite.setPosition(SCREEN_WIDTH, m_yOffset);
	m_pipes.push_back(sprite);
}

void Pipes::Delete() {
	for (unsigned short int i = 0; i < m_pipes.size(); i++) {
		if (m_pipes[i].getPosition().x + m_pipes[i].getGlobalBounds().width < 0) {
			m_pipes.erase(m_pipes.begin() + i);
		}
	}
}

Pipes::~Pipes() {

}
