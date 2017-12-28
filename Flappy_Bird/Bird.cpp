#include "stdafx.h"
#include "Bird.h"


Bird::Bird() 
	: m_animation({ "./assets/birds/yellowbird1.png",
		"./assets/birds/yellowbird2.png",
		"./assets/birds/yellowbird3.png",
		"./assets/birds/yellowbird4.png" }) {
	m_bird.setSize(sf::Vector2f(50, 35));
	m_bird.setOrigin(m_bird.getGlobalBounds().width / 2, m_bird.getGlobalBounds().height / 2);
	m_bird.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}


void Bird::Update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		m_bird.move(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		m_bird.move(0, 1);
	}
}

void Bird::Render(sf::RenderWindow& window) {
	m_animation.Animate(m_bird, 0.1);
	window.draw(m_bird);
}


Bird::~Bird()
{
}
