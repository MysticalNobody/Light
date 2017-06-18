#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Background
{
public:
	int xPos, layer;
	Texture bgTextrure[4];
	Sprite bgSprite[4];
	int getWidth();
	void setSprite(int, int);
	void draw(RenderWindow&);
};

