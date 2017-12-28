#include "stdafx.h"
#include "Collision.h"


Collision::Collision()
{
}

bool Collision::CheckCollision(sf::RectangleShape rect1, float scale1, sf::RectangleShape rect2, float scale2) {
	rect1.setScale(scale1, scale2);
	//rect2.setScale(scale1, scale2);
	sf::Rect<float> rect_1 = rect1.getGlobalBounds();
	sf::Rect<float> rect_2 = rect2.getGlobalBounds();

	return rect_1.intersects(rect_2);
}


Collision::~Collision()
{
}
