#ifndef PLAYERCAR_H
#define PLAYERCAR_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include "Barrier.h"
#include "Lap.h"
#include "HUD.h"
#include "Collisions.h"


class PlayerCar : public sf::Drawable
{
private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	float m_fRotationAngle;
	sf::Vector2f m_Vel;
	sf::Vector2f m_AccValue;
	sf::Vector2f m_Pos;
	float m_Mass;

	//HUD CODE
	bool starting = true;
	bool halfway = false;
	//bool ending = false;

	//sf::Text TimerText;
	sf::Font font;
	sf::Clock countdown;
	//sf::Text Prev1Text;
	//sf::Text Prev2Text;

public:
	PlayerCar();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::Vector2f getUnitRotationVector();
	void Update(float fElapsedTime);
	void Rotate(float dir, float fElapsedTime);
	void DetectCollisions(Barrier Bar1);
	void ResolveCollision(sf::FloatRect Rect1);
	void LapCollisions(Lap start);
	sf::Vector2f getPosition();
	float getMax(); //returns max positions

	static float magnitude(sf::Vector2f vector);

	sf::Text TimerText;
	sf::Text Prev1Text;
	sf::Text Prev2Text;
	sf::RectangleShape R1;
	sf::RectangleShape R2;
	sf::RectangleShape R3;

	float max;

	//void Velocity();
	//void Acceleration() const;

};

#endif