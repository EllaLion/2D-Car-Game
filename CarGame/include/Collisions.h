#ifndef COLLISIONS_H
#define COLLISIONS_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include "PlayerCar.h"
#include "Barrier.h"


class Collisions
{
private:
	sf::Vector2f Vec2;

public:
	Collisions();
	float DotProduct(sf::Vector2f V1, sf::Vector2f V2);
	//void ApplyImpulse(void);
	//struct AABB;
	//bool AABBvsAABB(PlayerCar *m);
	//bool AABBvsAABB(PlayerCar a, Barrier b);
	//void ResolveCollision(PlayerCar A, Barrier B);

};

#endif