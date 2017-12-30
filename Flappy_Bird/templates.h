#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

struct Rect : public sf::RectangleShape {
	sf::Texture tex;
};

struct Sprite : public sf::Sprite{
	sf::Texture tex;
};

struct Time {
	sf::Clock clock;
	sf::Time time;
};

struct Text : public sf::Text {
	Text(std::string filepath) {
		m_font.loadFromFile(filepath);
		this->setFont(m_font);
	}
private:
	sf::Font m_font;
};

struct Sound : public sf::Sound {
	sf::SoundBuffer buffer;
};