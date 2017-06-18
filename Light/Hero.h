#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Hero
{
public:
	int xPos, yPos;
	Texture texture;
	Sprite sprite;
	void draw(RenderWindow&, std::string, int);
};

