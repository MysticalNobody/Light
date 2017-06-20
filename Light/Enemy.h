#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Enemy
{
public:
	std::string state;
	int life = 100;
	float explosion = 0;
	float currentFrame = 0;
	int xPos, speed;
	Texture texture;
	Sprite sprite, expl;
	void draw(RenderWindow &, int, std::string);
	bool onCollision(int, int);
};

