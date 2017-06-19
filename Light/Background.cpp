#include "Background.h"
int Background::getWidth()
{
	return bgSprite[0].getGlobalBounds().width;
}

void Background::setSprite(int x, int lay)
{
	layer = lay;
	xPos = x;
	std::string path;
	for (int i = 0; i < 4; i++) {
		path = "Images/Background/" + std::to_string(layer) + "/" + std::to_string(i) + ".png";
		if (layer == 1) {
			bgTextrure[i].loadFromFile(path);
			bgSprite[i].setTexture(bgTextrure[i]);
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
		else if (layer == 2) {
			if (i == 0) {
				bgTextrure[i].loadFromFile(path);
				bgSprite[i].setTexture(bgTextrure[i]);
				bgSprite[i].setScale(4.5, 4.5);
			}
			else if (i > 1) {
				bgTextrure[i].loadFromFile(path);
				bgSprite[i].setTexture(bgTextrure[i]);
				bgSprite[i].setScale(3.55, 4.5);
			}
			bgSprite[i].setPosition(xPos, 0);
		}
	}
}

void Background::draw(RenderWindow &window, int layer)
{
	window.draw(bgSprite[layer]);
}

void Background::updatePos(int xPos1, int xPos2, int xPos3, int xPos4)
{
	bgSprite[0].setPosition(xPos1, bgSprite[0].getPosition().y);
	bgSprite[1].setPosition(xPos2, bgSprite[1].getPosition().y);
	bgSprite[2].setPosition(xPos3, bgSprite[2].getPosition().y);
	bgSprite[3].setPosition(xPos4, bgSprite[3].getPosition().y);
}


