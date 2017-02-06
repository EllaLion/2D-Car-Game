#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include <SFML/Window.hpp>
#include "include/PlayerCar.h"
#include "include/TrackBackground.h"
#include "include/Barrier.h"
//#include "include/HUD.h"
#include "include/Lap.h"
#include "include/Collisions.h"

using namespace std;
using namespace sf;


int main()
{
	/*bool upmove = false;
	bool downmove = false;
	bool leftmove = false;
	bool rightmove = false;*/

	PlayerCar player1car;
	TrackBackground TrackBG;
	Barrier Barriers;
	//HUD hud;
	Lap lap;
	Collisions collide;

	sf::RenderWindow window(sf::VideoMode(1024, 768), "Racers", sf::Style::Close | sf::Style::Titlebar); //creates a game window

	float frameTime(1.0f / 60.0f);
	float fElapsedTime;

	sf::View player_view(sf::FloatRect(0, 0, 600, 500));
	sf::View minimapView;

	minimapView.setViewport(sf::FloatRect(player_view.getCenter().x + 150, player_view.getCenter().y + 125, 0.25f, 0.25f));

	//sf::View HUD(sf::FloatRect(0.0f,0.0f,20.0f,30.0f));

	sf::Clock timer; //setting up a clock

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

		if (timer.getElapsedTime().asSeconds() > frameTime)
		{
			/* UPDATE */

			fElapsedTime = timer.restart().asSeconds(); //! Restarts the timer using seconds
			
			//sf::FloatRect P1CarBound = player1car.getGlobalBounds();

			//if (Keyboard::isKeyPressed(Keyboard::Key::Up)){ player1car.Move(1, fElapsedTime); };
			//if (!Keyboard::isKeyPressed(Keyboard::Key::Up)) { upmove = false; };
			//if (Keyboard::isKeyPressed(Keyboard::Key::Down)) { player1car.Move(-1, fElapsedTime); };


			player1car.Update(fElapsedTime); //! Updates the cars variables into main
			player1car.DetectCollisions(Barriers);
			//collide.AABBvsAABB(player1car, Barriers);

			//hud.Update();

			/*
			//rotate only when car is moving forward or backwards


			//LEFT
			if (Keyboard::isKeyPressed(Keyboard::Key::Left) && (Keyboard::isKeyPressed(Keyboard::Key::Up))) { player1car.Rotate(-1.5, fElapsedTime); }
			else if (Keyboard::isKeyPressed(Keyboard::Key::Left) && (Keyboard::isKeyPressed(Keyboard::Key::Down))) { player1car.Rotate(-1.5, fElapsedTime); };

			//RIGHT
			if (Keyboard::isKeyPressed(Keyboard::Key::Right) && (Keyboard::isKeyPressed(Keyboard::Key::Up))) { player1car.Rotate(1.5, fElapsedTime); }
			else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && (Keyboard::isKeyPressed(Keyboard::Key::Down))) { player1car.Rotate(1.5, fElapsedTime); };
			*/

		}
		/*
		if (collide.AABBvsAABB(player1car, Barriers) == true)
		{
			cout << " AABB COLLIDING " << endl;
		}
		*/
		player1car.TimerText.setPosition(player_view.getCenter().x + 150, player_view.getCenter().y + 125);

		player1car.R1.setPosition(player1car.TimerText.getPosition().x - 5, player1car.TimerText.getPosition().y + 6);

		//player1car.R1.setSize(sf::Vector2f(player1car.TimerText.getSize().x, player1car.TimerText.getScale).y));
		player1car.Prev1Text.setPosition(player_view.getCenter().x + 150, player_view.getCenter().y + 150);
		player1car.Prev2Text.setPosition(player_view.getCenter().x + 150, player_view.getCenter().y + 175);

		//player_view.setCenter(player1car.getPosition());
		if (player1car.getPosition().x > 724 && player1car.getPosition().y < 250)
		{
			player_view.setCenter(724, 250);
		}
		else if (player1car.getPosition().x > 724 && player1car.getPosition().y > 518)
		{
			player_view.setCenter(724, 518);
		}
		else if (player1car.getPosition().x < 300 && player1car.getPosition().y > 518)
		{
			player_view.setCenter(300, 518);
		}
		else if (player1car.getPosition().x < 300 && player1car.getPosition().y < 250)
		{
			player_view.setCenter(300, 250);
		}
		else if (player1car.getPosition().x < 300)
		{
			player_view.setCenter(300, player1car.getPosition().y);
		}
		else if (player1car.getPosition().x > 724)
		{
			player_view.setCenter(724, player1car.getPosition().y);
		}
		else if (player1car.getPosition().y < 250)
		{
			player_view.setCenter(player1car.getPosition().x, 250);
		}
		else if (player1car.getPosition().y > 518)
		{
			player_view.setCenter(player1car.getPosition().x, 518);
		}
		else
		{
			player_view.setCenter(player1car.getPosition());
		}

		//HUD.setViewport(FloatRect());
		
		window.setView(player_view);

		player1car.DetectCollisions(Barriers);
		player1car.LapCollisions(lap);

		window.draw(TrackBG);
		window.draw(player1car);
		window.draw(Barriers);
		window.setView(minimapView);
			
		window.display(); //! Displays everything drawn to window

		window.clear(sf::Color::White); //! Refreshes window to draw updated elements
		
	}


}

/*TO DO LIST*/

//Mass for vehicle

//Barrier object

//Collision with barrier