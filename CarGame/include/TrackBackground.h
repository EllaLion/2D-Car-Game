#ifndef TRACKBACKGROUND_H
#define TRACKBACKGROUND_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>


class TrackBackground : public sf::Sprite
{
private:
	sf::Texture m_Texture;
public:
	TrackBackground();
};

#endif