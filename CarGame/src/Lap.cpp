#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Lap.h"
#include <SFML/Window.hpp>

using namespace std;

Lap::Lap()
{

	Start.height = 42.0f;
	Start.width = 125.0f;
	Start.left = 826.0f;
	Start.top = 394.0f;

	End.height = 10.0f;
	End.width = 125.0f;
	End.left = 826.0f;
	End.top = 394.0f;

	Half.height = 61.0f;
	Half.width = 121.0f;
	Half.left = 74.0f;
	Half.top = 366.0f;

}
