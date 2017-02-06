#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Barrier.h"
#include <SFML/Window.hpp>

using namespace std;

Barrier::Barrier()
{
	//m_Rect1.height = 61.0f;
	//m_Rect1.width = 1023.99f;
	//m_Rect1.left = 0.0f;
	//m_Rect1.top = 0.0f;

	//m_Rect2.height = 108.0f;
	//m_Rect2.width = 227.0f;
	//m_Rect2.left = 405.0f;
	//m_Rect2.top = 61.0f;

	//m_Rect3.height = 648.0f;
	//m_Rect3.width = 81.0f;
	//m_Rect3.left = 0.0f;
	//m_Rect3.top = 61.0f;

	//m_Rect4.height = 59.0f;
	//m_Rect4.width = 1023.99f;
	//m_Rect4.left = 0.0f;
	//m_Rect4.top = 709.0f;

	/*m_Rect5.height = 648.0f;
	m_Rect5.width = 79.0f;
	m_Rect5.left = 945.0f;
	m_Rect5.top = 61.0f;
*/
	m_Rect5.height = 500.0f;
	m_Rect5.width = 500.0f;
	m_Rect5.left = 945.0f;
	m_Rect5.top = 61.0f;

	m_Rect6.height = 117.0f;
	m_Rect6.width = 108.0f;
	m_Rect6.left = 729.0f;
	m_Rect6.top = 158.0f;

	//m_Rect7.height = 325.0f;
	//m_Rect7.width = 217.0f;
	//m_Rect7.left = 621.0f;
	//m_Rect7.top = 277.0f;

	//m_Rect8.height = 108.0f;
	//m_Rect8.width = 321.0f;
	//m_Rect8.left = 299.0f;
	//m_Rect8.top = 277.0f;

	//m_Rect9.height = 443.0f;
	//m_Rect9.width = 109.0f;
	//m_Rect9.left = 188.0f;
	//m_Rect9.top = 158.0f;

	//m_Rect10.height = 217.0f;
	//m_Rect10.width = 108.0f;
	//m_Rect10.left = 404.0f;
	//m_Rect10.top = 492.0f;


	//r1.setPosition(sf::Vector2f(m_Rect1.left, m_Rect1.top));
	//r1.setSize(sf::Vector2f(m_Rect1.width, m_Rect1.height));

	//r2.setPosition(sf::Vector2f(m_Rect2.left, m_Rect2.top));
	//r2.setSize(sf::Vector2f(m_Rect2.width, m_Rect2.height));

	//r3.setPosition(sf::Vector2f(m_Rect3.left, m_Rect3.top));
	//r3.setSize(sf::Vector2f(m_Rect3.width, m_Rect3.height));

	//r4.setPosition(sf::Vector2f(m_Rect4.left, m_Rect4.top));
	//r4.setSize(sf::Vector2f(m_Rect4.width, m_Rect4.height));

	r5.setPosition(sf::Vector2f(m_Rect5.left, m_Rect5.top));
	r5.setSize(sf::Vector2f(m_Rect5.width, m_Rect5.height));

	r6.setPosition(sf::Vector2f(m_Rect6.left, m_Rect6.top));
	r6.setSize(sf::Vector2f(m_Rect6.width, m_Rect6.height));

	//r7.setPosition(sf::Vector2f(m_Rect7.left, m_Rect7.top));
	//r7.setSize(sf::Vector2f(m_Rect7.width, m_Rect7.height));

	//r8.setPosition(sf::Vector2f(m_Rect8.left, m_Rect8.top));
	//r8.setSize(sf::Vector2f(m_Rect8.width, m_Rect8.height));

	//r9.setPosition(sf::Vector2f(m_Rect9.left, m_Rect9.top));
	//r9.setSize(sf::Vector2f(m_Rect9.width, m_Rect9.height));

	//r10.setPosition(sf::Vector2f(m_Rect10.left, m_Rect10.top));
	//r10.setSize(sf::Vector2f(m_Rect10.width, m_Rect10.height));

}

void Barrier::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	//target.draw(r1);
	//target.draw(r2);
	//target.draw(r3);
	//target.draw(r4);
	target.draw(r5);
	target.draw(r6);
	//target.draw(r7);
	//target.draw(r8);
	//target.draw(r9);
	//target.draw(r10);
}

/*void Barrier::BoundingBox()
{
	sf::FloatRect boundingBox1 = m_Rect1.getGlobalBounds();
}*/