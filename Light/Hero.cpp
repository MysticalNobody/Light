#include "Hero.h"

void Hero::draw(RenderWindow& window, std::string state, int currFrame) {
	std::string path = "Images/Hero/" + state + "_" + std::to_string(currFrame) + ".png";
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setPosition(xPos, yPos);
	sprite.setScale(2.5, 2.5);
	window.draw(sprite);
}
