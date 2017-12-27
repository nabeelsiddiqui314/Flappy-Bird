#include "stdafx.h"
#include "Menu.h"


inline void Menu::init_backround() {
	m_backroundImg.setSize(sf::Vector2f(550, 700));
	m_backroundImg.setPosition(0, 0);
	m_backroundImg.tex.loadFromFile("./assets/backrounds/sky.png");
	m_backroundImg.setTexture(&m_backroundImg.tex);

	m_title.setSize(sf::Vector2f(450, 120));
	m_title.setPosition(50, 20);
	m_title.tex.loadFromFile("./assets/backrounds/title.png");
	m_title.setTexture(&m_title.tex);
}

inline void Menu::init_buttons() {
	m_play_button.setSize(sf::Vector2f(140, 90));
	m_play_button.setPosition(200, 300);
	m_play_button.tex.loadFromFile("./assets/buttons/play.png");
	m_play_button.setTexture(&m_play_button.tex);
}

Menu::Menu()
{
	init_backround();
	init_buttons();
}


void Menu::HandleInput(sf::RenderWindow& window) {
	if (Interface::isClicked(window, m_play_button)) {
		stateManager.SetState(new Game());
	}
}

void Menu::Update(sf::RenderWindow& window) {
	
}

void Menu::Render(sf::RenderWindow& window) {
	window.draw(m_backroundImg);
	window.draw(m_title);
	window.draw(m_play_button);
}


Menu::~Menu()
{
	
}
