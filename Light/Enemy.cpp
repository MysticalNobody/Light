#include "Enemy.h"
#include "Hero.h"
void Enemy::draw(RenderWindow &window, int type, std::string st) {
	if (life > 0) {
		std::string path = "Images/Enemies/" + std::to_string(type) + "/sprite.png";
		texture.loadFromFile(path);
		sprite.setTexture(texture);
		expl.setTexture(texture);
		if (st == "right") {
			sprite.setTextureRect(IntRect(16 * (int)currentFrame, 32, 16, 16));
			expl.setTextureRect(IntRect(16 * (int)currentFrame, 32, 16, 16));
		}
		else {
			sprite.setTextureRect(IntRect(16 * (int)currentFrame, 16, 16, 16));
			expl.setTextureRect(IntRect(16 * (int)currentFrame, 16, 16, 16));
		}
		sprite.setPosition(xPos, 640 - 16 * 5 * explosion);
		expl.setPosition(xPos, 640 - 16 * 5 * explosion);
		expl.setColor(Color(255, 0, 0, 255 * explosion));
		sprite.setScale(5 + 5 * explosion, 5 + 5 * explosion);
		expl.setScale(5 + 5 * explosion, 5 + 5 * explosion);
		window.draw(sprite);
		window.draw(expl);
	}
}

bool Enemy::onCollision(int left, int right)
{
	return sprite.getGlobalBounds().left >= left&& sprite.getGlobalBounds().left <= right;
}
