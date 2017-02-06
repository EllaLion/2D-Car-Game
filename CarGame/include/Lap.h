#ifndef LAP_H
#define LAP_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>


class Lap
{
private:
	
public:
	Lap();

	sf::FloatRect Start;
	sf::FloatRect Half;
	sf::FloatRect End;
};

#endif