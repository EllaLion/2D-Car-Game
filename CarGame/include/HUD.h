#ifndef HUD_H
#define HUD_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>


class HUD : public sf::Drawable
{
private:
	sf::Text TimerText;
	sf::Font font;
	sf::Clock countdown;
	sf::Text Prev1Text;
	sf::Text Prev2Text;
	//sf::Text Speed;
public:
	HUD();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void Update();
};

#endif