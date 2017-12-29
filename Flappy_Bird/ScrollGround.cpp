#include "stdafx.h"
#include "ScrollGround.h"


ScrollGround::ScrollGround() {
	m_ground.push_back(temp1);
	m_ground.push_back(temp2);
	for (unsigned int i = 0; i < 2; i++) {
		m_ground[i].setSize(sf::Vector2f(760, 121));
		m_ground[i].tex.loadFromFile("./assets/objects/land.png");
		m_ground[i].setTexture(&m_ground[i].tex);
	}
	m_ground[0].setPosition(0, 620);
	m_ground[1].setPosition(m_ground[0].getPosition().x + m_ground[0].getGlobalBounds().width, m_ground[0].getPosition().y);
}

void ScrollGround::Scroll() {
	this->Move();
	this->Repeat();
}

void ScrollGround::Render(sf::RenderWindow& window) {
	window.draw(m_ground[0]);
	window.draw(m_ground[1]);
}

int ScrollGround::GroundHeight() const { 
	return m_ground[0].getPosition().y; 
}

const std::vector<Rect>& ScrollGround::GetGround() const {
	return m_ground; 
}

void ScrollGround::Move() {
	m_ground[0].move(-MOVE_SPEED, 0);
	m_ground[1].move(-MOVE_SPEED, 0);
}

void ScrollGround::Repeat() {
	for (unsigned int i = 0; i < 2; i++) {
		if (m_ground[i].getPosition().x < 0) {
			int other = swap(i);
			m_ground[other].setPosition(m_ground[i].getPosition().x + m_ground[i].getGlobalBounds().width, 620);
		}
	}
}

int ScrollGround::swap(int num) {
	if (num == 0) {
		num = 1;
	}
	else {
		num = 0;
	}
	return num;
}

ScrollGround::~ScrollGround() {
	m_ground.clear();
}
