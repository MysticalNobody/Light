#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Hero
{
public:
	int life = 100;
	Shader shader;
	int xPos, yPos;
	Texture texture;
	Sprite sprite;
	Texture hpTex;
	Sprite hp;
	Sprite shadow;
	void draw(RenderWindow&, std::string, int);
	void drawShadow(RenderWindow&, std::string, int, int, int);
};

