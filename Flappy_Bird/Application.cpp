#include "stdafx.h"
#include "Application.h"


Application::Application() {
	m_mainWindow.create(sf::VideoMode(550, 700), "FlappyBird");
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
		stateManager.Run();
		m_mainWindow.display();
	}
}


Application::~Application() {

}
