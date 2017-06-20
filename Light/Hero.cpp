#include "Hero.h"
void Hero::draw(RenderWindow& window, std::string state, int currFrame) {
	std::string path = "Images/Hero/" + state + "_" + std::to_string(currFrame) + ".png";
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	//shader.setUniform("sourceTexture", texture);
	//shader.setUniform("sigma", 1.0f);
	//shader.setUniform("glowMultiplier", 4.0f);
	//shader.setUniform("width", sprite.getGlobalBounds().width);
	sprite.setColor(Color(132, 255, 255, 255));
	sprite.setPosition(xPos, yPos);
	sprite.setScale(2.5, 2.5);
	path = "Images/Hero/hp.png";
	hpTex.loadFromFile(path);
	hp.setTexture(hpTex);
	hp.setScale(0.3, 0.3);
	window.draw(sprite);
	for (int i = 0; i < life / 10; i++) {
		if (xPos >= 550) {
			hp.setPosition(10 + xPos - 550 + 50 * i, 10);
		}
		else
		{
			hp.setPosition(50 * i, 10);
		}
		window.draw(hp);
	}
}
void Hero::drawShadow(RenderWindow& window, std::string state, int currFrame, int intensivity, int xPosFromHero) {
	std::string path = "Images/Hero/" + state + "_" + std::to_string(currFrame) + ".png";
	texture.loadFromFile(path);
	shadow.setTexture(texture);
	//shader.setUniform("sourceTexture", texture);
	//shader.setUniform("sigma", 10.0f);
	//shader.setUniform("glowMultiplier", 4.0f);
	//shader.setUniform("width", sprite.getGlobalBounds().width);
	shadow.setColor(Color(132, 255, 255, intensivity));
	shadow.setPosition(xPos + xPosFromHero, yPos);
	shadow.setScale(2.5, 2.5);
	window.draw(shadow);
}
