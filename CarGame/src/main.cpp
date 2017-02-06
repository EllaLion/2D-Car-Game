#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include <SFML/Window.hpp>

using namespace std;

int main()
{

	sf::RenderWindow window(sf::VideoMode(600, 420), "Racers", sf::Style::Close | sf::Style::Titlebar); //creates a game window

	//sf::Clock timer; //setting up a clock

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close(); //closes the window and game when the 'X' button is pressed in the title bar
			}

		}
		
	}


}