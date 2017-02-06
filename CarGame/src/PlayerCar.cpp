#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/PlayerCar.h"
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

PlayerCar::PlayerCar()
{
	m_Texture.loadFromFile(".//assets//pictures//player_car.png");
	m_Sprite.setTexture(m_Texture);
	m_fRotationAngle = 0;
	//m_Sprite.setRotation(270);
	//setScale(sf::Vector2f(3.f, 3.f));
	m_Sprite.setOrigin(m_Sprite.getLocalBounds().width/2.0f, m_Sprite.getLocalBounds().height/2.0f);
	m_Pos = Vector2f(876, 493);
	m_Vel = Vector2f(0, 0);
	m_Mass = 300;


	//HUD CODE
	font.loadFromFile("./assets/fonts/segoeui.ttf");
	TimerText.setFont(font);
	TimerText.setString(to_string(countdown.getElapsedTime().asSeconds()));
	//TimerText.setPosition(200.0f, 300.0f);

	Prev1Text.setFont(font);
	//Prev1Text.setPosition(200.0f, 325.0f);
	//Prev1Text.setString(TimerText.getString());

	Prev2Text.setFont(font);
	//Prev2Text.setPosition(200.0f, 350.0f);
	//Prev2Text.setString(Prev1Text.getString());

	R1.setFillColor(sf::Color::Black);
	R1.setSize(sf::Vector2f(145, 75));
};


void PlayerCar::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(m_Sprite); //draws the car sprite

	target.draw(R1);

	target.draw(TimerText); //draws the time text
	target.draw(Prev1Text);
	target.draw(Prev2Text);
	
}

sf::Vector2f PlayerCar::getUnitRotationVector()
{
	sf::Vector2f RotationVector;
	RotationVector.x = cosf(m_fRotationAngle * (3.14159f / 180.0f)); //changes angle into vector for x
	RotationVector.y = sinf(m_fRotationAngle * (3.14159f / 180.0f)); //changes angle into vector for y
	return RotationVector; //returns the rotation vector
}

void PlayerCar::Update(float fElapsedTime)
{

	float fMoveDirection = 0;
	float fCoefficient = 0.4f;
	float fGravity = 9.8f; //! Value of Gravity

	//m_Sprite.move(getUnitRotationVector() * 70.0f * (float)dir * fElapsedTime);

	Vector2f friction(m_Vel * fCoefficient * fGravity); //! The friction is calculated by Velocity multiplied by the scale of friction and the value of Gravity
	
	//sf::Event event;

	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		fMoveDirection = 1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Down))
	{
		fMoveDirection = -1;
	}
	else fMoveDirection = 0; //If the car is not moving then the movement is nothing
	

	m_AccValue = 700.0f * getUnitRotationVector() * fElapsedTime * fMoveDirection - friction;

	m_Vel += m_AccValue * fElapsedTime; //! the Velocity calculated by previous velocity plus Acceleration multiplied by the elapsed time

	m_Pos += m_Vel; //! The previous position plus the Velocity to make new position

	/*LEFT*/
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && magnitude(m_Vel) > 0.5f)
	{
		Rotate(-2.9, fElapsedTime);
	}
	//else if (Keyboard::isKeyPressed(Keyboard::Key::Left) && (Keyboard::isKeyPressed(Keyboard::Key::Down))) { Rotate(-1.5, fElapsedTime); };

	/*RIGHT*/
	if (Keyboard::isKeyPressed(Keyboard::Key::Right) && magnitude(m_Vel) > 0.5f) //!If the key is pressed and the car is moving then do action
	{
		Rotate(2.9, fElapsedTime); //! Rotate the car by the value at the elapsed time
	}
	//else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && (Keyboard::isKeyPressed(Keyboard::Key::Down))) { Rotate(1.5, fElapsedTime); };

	m_Sprite.setPosition(m_Pos); //! Set's the sprites position with the new values
	m_Sprite.setRotation(m_fRotationAngle); //! Set's the sprites rotation with the new values

	//HUD CODE
	countdown.getElapsedTime().asSeconds();
	TimerText.setString(to_string(countdown.getElapsedTime().asSeconds()));

	


}

void PlayerCar::Rotate(float dir, float fElapsedTime)
{
	m_fRotationAngle += 50.0f * dir * fElapsedTime;

	m_Sprite.setRotation(m_fRotationAngle);
}


sf::Vector2f PlayerCar::getPosition()
{
	return m_Pos;
	return m_AccValue;
}

float PlayerCar::magnitude(sf::Vector2f vector)
{
	return sqrtf(vector.x * vector.x + vector.y * vector.y);
}

void PlayerCar::ResolveCollision(sf::FloatRect Rect1)
{
	if (m_Sprite.getGlobalBounds().intersects(Rect1))
	{
		sf::Vector2f CollisionNormal = sf::Vector2f(0, 1.f); //sf::Vector2f(Bar1.m_Rect1.left, Bar1.m_Rect1.top) - m_Pos;
		const auto
			Width = m_Sprite.getLocalBounds().width,
			Height = m_Sprite.getLocalBounds().height;

		if (abs(m_Pos.x - Rect1.width / 2.0f) > abs(Rect1.left - Rect1.width / 2.0f) && abs(m_Pos.x + Rect1.width / 2.0f) < abs(Rect1.left + Rect1.width / 2.0f))
		{
			if (m_Pos.y > Rect1.top)
			{
				CollisionNormal = sf::Vector2f(0.f, 1.f);
			}
			else
			{
				CollisionNormal = sf::Vector2f(0.f, -1.f);
			}

		}
		else /*if (abs(m_Pos.y - Rect1.height / 2.0f) > abs(Rect1.top - Rect1.height / 2.0f) && abs(m_Pos.y + Rect1.height / 2.0f) < abs(Rect1.top + Rect1.height / 2.0f))*/
		{
			if (m_Pos.x > Rect1.left)
			{
				CollisionNormal = sf::Vector2f(1.f, 0.f);
			}
			else
			{
				CollisionNormal = sf::Vector2f(-1.f, 0.f);
			}

		}


		CollisionNormal = CollisionNormal / magnitude(CollisionNormal);

		std::cout << "\nCollision Normal: " << CollisionNormal.x << ", " << CollisionNormal.y << endl;

		m_Pos += CollisionNormal * 1.f;

		float e = 0.2f;

		m_Vel -= CollisionNormal * ((1.f + e) * (Collisions().DotProduct(m_Vel, CollisionNormal)));
	}
}

void PlayerCar::DetectCollisions(Barrier Bar1)
{
	sf::FloatRect CarBoundingBox = m_Sprite.getGlobalBounds();
	//sf::FloatRect area;

	float Direction = 1;
	
	const auto currentRect = Bar1.m_Rect2;

	ResolveCollision(Bar1.m_Rect1);
	ResolveCollision(Bar1.m_Rect2);
	ResolveCollision(Bar1.m_Rect3);
	ResolveCollision(Bar1.m_Rect4);
	ResolveCollision(Bar1.m_Rect5);
	ResolveCollision(Bar1.m_Rect6);
	ResolveCollision(Bar1.m_Rect7);
	ResolveCollision(Bar1.m_Rect8);
	ResolveCollision(Bar1.m_Rect9);
	ResolveCollision(Bar1.m_Rect10);

	if (m_Sprite.getGlobalBounds().intersects(currentRect))
	{

		cout << "Collision on 1" << endl;
	}
	else if (CarBoundingBox.intersects(Bar1.m_Rect2))
	{
		cout << "Collision on 2" << endl;
	}
	else if (CarBoundingBox.intersects(Bar1.m_Rect3))
	{
		cout << "Collision on 3" << endl;
	}
	else if (CarBoundingBox.intersects(Bar1.m_Rect4))
	{
		cout << "Collision on 4" << endl;
	}
	else if (CarBoundingBox.intersects(Bar1.m_Rect5))
	{
		cout << "Collision on 5" << endl;
	}
	else if (CarBoundingBox.intersects(Bar1.m_Rect6))
	{
		cout << "Collision on 6" << endl;
	}
	else if (CarBoundingBox.intersects(Bar1.m_Rect7))
	{
		cout << "Collision on 7" << endl;
	}
	else if (CarBoundingBox.intersects(Bar1.m_Rect8))
	{
		cout << "Collision on 8" << endl;
	}
	else if (CarBoundingBox.intersects(Bar1.m_Rect9))
	{
		cout << "Collision on 9" << endl;
	}
	else if (CarBoundingBox.intersects(Bar1.m_Rect10))
	{
		cout << "Collision on 10" << endl;
	}
	
}

void PlayerCar::LapCollisions(Lap start)
{

	sf::FloatRect CarBoundingBox = m_Sprite.getGlobalBounds();


	if (CarBoundingBox.intersects(start.Start))
	{

		if (starting == true && !halfway)
		{
			cout << "Timer Start" << endl;
			countdown.restart();
			starting = false;

			countdown.getElapsedTime().asSeconds();
			TimerText.setString(to_string(countdown.getElapsedTime().asSeconds()));
		}
		else if (!starting && halfway)
		{
			cout << "end" << endl;

			countdown.restart(); //restarts the clock

			Prev2Text.setString(Prev1Text.getString());
			Prev1Text.setString(TimerText.getString()); //sets the text to the above text
			
			halfway = false;
		}
	}
	else if (CarBoundingBox.intersects(start.Half))
	{
		if (halfway == false)
		{
			cout << "Halfway" << endl;
			halfway = true;
		}
	}

}

float PlayerCar::getMax()
{
	float max = m_Sprite.getPosition().x + 45;

	return max;
}