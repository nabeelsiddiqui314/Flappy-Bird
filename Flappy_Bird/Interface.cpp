#include "stdafx.h"
#include "Interface.h"


Interface::Interface() {

}

bool Interface::isHovered(sf::RenderWindow& window, sf::RectangleShape& button) {
	sf::IntRect _button(button.getPosition().x, button.getPosition().y, button.getGlobalBounds().width, button.getGlobalBounds().height);
	return _button.contains(sf::Mouse::getPosition(window));
}

void Interface::SetPointer(sf::RenderWindow& window, sf::RectangleShape& pointer, bool hideMouse) {
	window.setMouseCursorVisible(!hideMouse);
	pointer.setOrigin(pointer.getGlobalBounds().width / 2, pointer.getGlobalBounds().height / 2);
	sf::Vector2f mousePos(sf::Mouse::getPosition(window));
	pointer.setPosition(mousePos);
}

bool Interface::isClicked(sf::RenderWindow& window, sf::RectangleShape& button) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::IntRect button(button.getPosition().x, button.getPosition().y,
			button.getGlobalBounds().width, button.getGlobalBounds().height);

		return button.contains(sf::Mouse::getPosition(window));
	}
}


Interface::~Interface()
{
}
