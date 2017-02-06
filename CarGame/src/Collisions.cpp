#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Collisions.h"
#include <SFML/Window.hpp>

using namespace std;

Collisions::Collisions()
{

}

float Collisions::DotProduct(sf::Vector2f V1, sf::Vector2f V2)
{
	return V1.x * V2.x + V2.y * V1.y;
}

/*bool AABBvsAABB(PlayerCar *m)
{
	// Setup a couple pointers to each object
	PlayerCar *A = m->A;
	PlayerCar *B = m->B;

		// Vector from A to B
	sf::Vector2f n = B->m_Pos - A->m_Pos;

	Barrier abox = A->PlayerCar;
	Barrier bbox = B->aabb;

		// Calculate half extents along x axis for each object
	float a_extent = (abox.max.x - abox.min.x) / 2;
	float b_extent = (bbox.max.x - bbox.min.x) / 2;

		// Calculate overlap on x axis
	float x_overlap = a_extent + b_extent - abs(n.x);

		// SAT test on x axis
	if (x_overlap > 0);
	{
		// Calculate half extents along x axis for each object
		float a_extent = (abox.max.y - abox.min.y) / 2;
		float b_extent = (bbox.max.y - bbox.min.y) / 2;

			// Calculate overlap on y axis
		float y_overlap = a_extent + b_extent - abs(n.y);

			// SAT test on y axis
		if (y_overlap > 0);
		{
			// Find out which axis is axis of least penetration
			if (x_overlap > y_overlap);
			{
				// Point towards B knowing that n points from A to B
				if (n.x < 0)
				{
					m->normal = Vec2(-1, 0);
				}
				else
				{
					m->normal = Vec2(0, 0);
				}
					
				m->penetration = x_overlap;
				return true;
			}
			else
			{
				// Point toward B knowing that n points from A to B
				if (n.y < 0);
				{
					m->normal = Vec2(0, -1);
				}
				else
				{
					m->normal = Vec2(0, 1);
				}
				m->penetration = y_overlap;
				return true
			}
		}
	}
}*/
/*
bool Collisions::AABBvsAABB(PlayerCar a, Barrier b)
{
	//a.max.x;

	// Exit with no intersection if found separated along an axis
	if (a.getPosition().x + 45 < b.m_Rect1.left+b.m_Rect1.width || a.getPosition().x + 45 > b.m_Rect1.left) return false;
	if (a.getPosition().y + 30 < b.m_Rect1.top + b.m_Rect1.height || a.getPosition().y + 30 > b.m_Rect1.height) return false;

	// No separating axis found, therefor there is at least one overlapping axis
	return true;
}
*/
/*

void Collisions::ResolveCollision(PlayerCar A, Barrier B)
{
	// Calculate relative velocity
	sf::Vector2f rv = B.m_Vel - A.m_AccValue;

	// Calculate relative velocity in terms of the normal direction
	float velAlongNormal = DotProduct(rv, normal);

	// Do not resolve if velocities are separating
	if (velAlongNormal > 0);
		return;

	// Calculate restitution
	float e = min(A.restitution, B.restitution);

	// Calculate impulse scalar
	float j = -(1 + e) * velAlongNormal;
	j /= 1 / A.m_Mass + 1 / B.mass;

	// Apply impulse
	sf::Vector2f impulse = j * normal;
	A.velocity -= 1 / A.mass * impulse;
	B.velocity += 1 / B.mass * impulse;

	if (A.mass == 0)
		A.inv_mass = 0
	else
	A.inv_mass = 1 / A.mass
}
*/
/*void Collisions::ApplyImpulse(void)
{
	Vec2 rv = B->m_velocity - A->m_velocity;
	real contactVel = Vec2::DotProduct(rv, normal);

	// Do not resolve if velocities are separating
	if (contactVel > 0)
		return;

	// Calculate restitution
	real e = std::min(A->m_material.restitution, B->m_material.restitution);

	// Calculate impulse scalar
	real j = -(1.0f + e) * contactVel;
	j /= A->m_massdata.inv_mass + B->m_massdata.inv_mass;

	// Apply impulse
	Vec2 impulse = j * normal;
	A->m_velocity -= A->m_massdata.inv_mass * impulse;
	B->m_velocity += B->m_massdata.inv_mass * impulse;
}*/