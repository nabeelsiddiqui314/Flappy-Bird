#include "stdafx.h"
#include "Animation.h"


Animation::Animation(std::vector<std::string> filepaths) {
	for (unsigned short int i = 0; i < filepaths.size(); i++) {
		sf::Texture* texture = new sf::Texture();
		texture->loadFromFile(filepaths[i]);
		m_textures.push_back(texture);
	}
}

void Animation::Animate(sf::RectangleShape& sprite, float dt) {
	m_DT.time = m_DT.clock.getElapsedTime();
	if (m_DT.time.asSeconds() >  dt) {
		sprite.setTexture(m_textures[m_index]);
		if (m_index < m_textures.size() - 1) {
			m_index++;
		}
		else {
			m_index = 0;
		}
		m_DT.clock.restart();
	}
}


Animation::~Animation()
{
}
