#include "stdafx.h"
#include "Application.h"
#include "Variables.h"


Application::Application() {
	m_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "FlappyBird");
	stateManager.SetWindow(m_mainWindow);
	stateManager.SetState(new Menu());
	this->Run();
}


void Application::Run() {
	while (m_mainWindow.isOpen()) {
		sf::Event evnt;
		while (m_mainWindow.pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				m_mainWindow.close();
			}
		}
		m_mainWindow.clear();
		while (m_accumulator > m_ups) {
			m_accumulator -= m_ups;
			stateManager.Update();
		}
		m_accumulator += m_clock.restart();
		stateManager.Render();
		m_mainWindow.display();
	}
}


Application::~Application() {

}
