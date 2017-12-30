#include "stdafx.h"
#include "Bird.h"


Bird::Bird() 
	: m_animation(m_bird, { "./assets/birds/yellowbird1.png",
		"./assets/birds/yellowbird2.png",
		"./assets/birds/yellowbird3.png",
		"./assets/birds/yellowbird4.png" }) {
	m_bird.setSize(sf::Vector2f(50, 35));
	m_bird.setOrigin(m_bird.getGlobalBounds().width / 2, m_bird.getGlobalBounds().height / 2);
	m_bird.setPosition(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2);
	m_flySound.buffer.loadFromFile("./assets/sounds/wing.wav");
	m_flySound.setBuffer(m_flySound.buffer);
}

void Bird::Update(bool playing) {
	m_animation.Animate(0.1);
	if (playing) {
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
	}
	else {
		this->PreReadyAnimate();
	}
}

void Bird::PreReadyAnimate() {
	m_preReadyFlyTime.time = m_preReadyFlyTime.clock.getElapsedTime();
	if (m_preReadyFlyTime.time.asSeconds() < 0.25) {
		m_bird.move(0, m_preReadyVelocity);
	}
	else {
		m_preReadyVelocity *= -1;
		m_preReadyFlyTime.clock.restart();
	}
}

void Bird::Render(sf::RenderWindow& window) {
	window.draw(m_bird);
}

void Bird::Tap() {
	m_flySound.play();
	m_bird_state = FLYING;
	m_flyTime.clock.restart();
}

Bird::~Bird()
{
}
