#include "stdafx.h"
#include "Bird.h"


Bird::Bird() 
	: m_animation(m_bird, { "./assets/birds/yellowbird1.png",
		"./assets/birds/yellowbird2.png",
		"./assets/birds/yellowbird3.png",
		"./assets/birds/yellowbird4.png" }) {
	m_bird.setSize(sf::Vector2f(50, 35));
	m_bird.setOrigin(m_bird.getGlobalBounds().width / 2, m_bird.getGlobalBounds().height / 2);
	m_bird.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void Bird::Update() {
	if (m_bird_state == FLYING) {
		m_bird.move(0, -FLY_SPEED);
		m_rotation -= ROTATION_SPEED_UP;
		if (m_rotation < -25.0f) {
			m_rotation = -25.0f;
		}
		m_bird.setRotation(m_rotation);
	}
	else if (m_bird_state == FALLING) {
		m_bird.move(0, GRAVITY_SPEED);
		m_rotation += ROTATION_SPEED_DOWN;
		if (m_rotation > 50.0f) {
			m_rotation = 50.0f;
		}
		m_bird.setRotation(m_rotation);
	}
	m_flyTime.time = m_flyTime.clock.getElapsedTime();
	if (m_flyTime.time.asSeconds() > FLY_TIME) {
		m_flyTime.clock.restart();
		m_bird_state = FALLING;
	}
	m_animation.Animate(0.1);
}

void Bird::Render(sf::RenderWindow& window) {
	window.draw(m_bird);
}

void Bird::Tap() {
	m_bird_state = FLYING;
	m_flyTime.clock.restart();
}

Bird::~Bird()
{
}
