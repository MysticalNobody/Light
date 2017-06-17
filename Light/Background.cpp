#include "Background.h"



int Background::getWidth()
{
	return bgSprite[0].getGlobalBounds().width;
}

Background::Background(int x, int lay)
{
	layer = lay;
	xPos = x;
	setSprite();
}

void Background::setSprite()
{
	std::string path;
	for (int i = 0; i < 4; i++) {
		path = "Images/Background/" + std::to_string(layer) + "/" + std::to_string(i) + ".png";
		bgTextrure[i].loadFromFile(path);
		bgSprite[i].setTexture(bgTextrure[i]);
		if (layer == 1) {
			bgSprite[i].setScale(4.5, 4.5);
			if (i == 0) {
				bgSprite[i].setPosition(xPos, 0);
			}
			else if (i == 1) {
				bgSprite[i].setPosition(xPos, 81);
			}
			else if (i == 2) {
				bgSprite[i].setPosition(xPos, 45);
			}
			else {
				bgSprite[i].setPosition(xPos, 252);
			}
		}
	}
}

void Background::draw(RenderWindow &window)
{
	for (int i = 0; i < 4; i++) {
		window.draw(bgSprite[i]);
	}
}

