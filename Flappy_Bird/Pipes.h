#pragma once
#include <SFML/Graphics.hpp>
#include "templates.h"
#include "Variables.h"
#include "Interface.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

class Pipes
{
public:
	Pipes(int groundHeight);
	~Pipes();
public:
	void Update();
	void Render(sf::RenderWindow& window);
private:
	void Move();
	void RandomizeOffset();
	void SpawnTop();
	void SpawnBottom();
	void Delete();
private:
	int                     m_groundHeight;
	int                     m_yOffset;
	Time                    m_frequency;
	std::vector<sf::Sprite> m_pipes;
	sf::Texture             m_pipeTopTex;
	sf::Texture             m_pipeBottomTex;
};

