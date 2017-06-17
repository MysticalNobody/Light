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
	Background(int, int);
	void setSprite();
	void draw(RenderWindow&);
};

