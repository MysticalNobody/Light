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
			else if (i < 3) {
				bgTextrure[i].loadFromFile(path);
				bgSprite[i].setTexture(bgTextrure[i]);
				bgSprite[i].setScale(5, 5);
			}
			bgSprite[i].setPosition(xPos, 0);
		}
	}
}

void Background::draw(RenderWindow &window)
{
	for (int i = 0; i < 4; i++) {
		window.draw(bgSprite[i]);
	}
}

