#ifndef BARRIER_H
#define BARRIER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>


class Barrier : public sf::Drawable
{
private:
	/*sf::FloatRect m_Rect1;
	sf::FloatRect m_Rect2;
	sf::FloatRect m_Rect3;
	sf::FloatRect m_Rect4;
	sf::FloatRect m_Rect5;
	sf::FloatRect m_Rect6;
	sf::FloatRect m_Rect7;
	sf::FloatRect m_Rect8;
	sf::FloatRect m_Rect9;
	sf::FloatRect m_Rect10;*/

public:
	Barrier();

	sf::FloatRect m_Rect1;
	sf::FloatRect m_Rect2;
	sf::FloatRect m_Rect3;
	sf::FloatRect m_Rect4;
	sf::FloatRect m_Rect5;
	sf::FloatRect m_Rect6;
	sf::FloatRect m_Rect7;
	sf::FloatRect m_Rect8;
	sf::FloatRect m_Rect9;
	sf::FloatRect m_Rect10;

	sf::RectangleShape r1, r2, r3, r4, r5, r6, r7, r8, r9, r10;


	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	//void BoundingBox();

	//static float magnitude(sf::Vector2f vector);

};

#endif