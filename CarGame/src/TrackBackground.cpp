#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/TrackBackground.h"
#include <SFML/Window.hpp>

using namespace std;

TrackBackground::TrackBackground()
{
	m_Texture.loadFromFile(".//assets//pictures//TrackBG.png");
	setTexture(m_Texture);
	//setScale(sf::Vector2f(3.f, 3.f));
	setOrigin(getLocalBounds().width / 2.0f, getLocalBounds().height / 2.0f);
	setPosition(512, 384);
}