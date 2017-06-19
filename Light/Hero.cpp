#include "Hero.h"
void Hero::draw(RenderWindow& window, std::string state, int currFrame) {
	std::string path = "Images/Hero/" + state + "_" + std::to_string(currFrame) + ".png";
	texture.loadFromFile(path);
	shader.setUniform("sourceTexture", texture);
	sprite.setTexture(texture);
	shader.setUniform("sigma", 1.0f);
	shader.setUniform("glowMultiplier", 4.0f);
	shader.setUniform("width", sprite.getGlobalBounds().width);
	sprite.setColor(Color(132, 255, 255, 255));
	sprite.setPosition(xPos, yPos);
	sprite.setScale(2.5, 2.5);
	window.draw(sprite);
}
void Hero::drawShadow(RenderWindow& window, std::string state, int currFrame, int intensivity, int xPosFromHero) {
	std::string path = "Images/Hero/" + state + "_" + std::to_string(currFrame) + ".png";
	texture.loadFromFile(path);
	shader.setUniform("sourceTexture", texture);
	shadow.setTexture(texture);
	shader.setUniform("sigma", 10.0f);
	shader.setUniform("glowMultiplier", 4.0f);
	shader.setUniform("width", sprite.getGlobalBounds().width);
	shadow.setColor(Color(132, 255, 255, intensivity));
	shadow.setPosition(xPos + xPosFromHero, yPos);
	shadow.setScale(2.5, 2.5);
	window.draw(shadow, &shader);
}
