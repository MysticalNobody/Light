#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Hero
{
public:
	Shader shader;
	int xPos, yPos;
	Texture texture;
	Sprite sprite;
	Sprite shadow;
	void draw(RenderWindow&, std::string, int);
	void drawShadow(RenderWindow&, std::string, int, int, int);
};

