#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/HUD.h"
#include <SFML/Window.hpp>

using namespace std;

HUD::HUD()
{

	font.loadFromFile("./assets/fonts/segoeui.ttf");
	TimerText.setFont(font);
	TimerText.setString(to_string(countdown.getElapsedTime().asSeconds()));
	TimerText.setPosition(200.0f, 300.0f);

	Prev1Text.setFont(font);
	Prev1Text.setPosition(200.0f, 325.0f);
	//Prev1Text.setString(TimerText.getString());

	Prev2Text.setFont(font);
	Prev2Text.setPosition(200.0f, 350.0f);
	//Prev2Text.setString(Prev1Text.getString());

}

void HUD::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(TimerText); //draws the time text
	//target.draw(Prev1Text);
	//target.draw(Prev2Text);
}

void HUD::Update()
{

	countdown.getElapsedTime().asSeconds();
	TimerText.setString(to_string(countdown.getElapsedTime().asSeconds()));

	Prev1Text.setString(TimerText.getString());
	Prev2Text.setString(Prev1Text.getString());
	
}