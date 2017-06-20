#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Hero.h"
#include "Enemy.h"
int main()
{
	int x = 0;
	RenderWindow window(VideoMode(1280, 720), "Light");
	View view(FloatRect(0, 0, 1280, 720));
	Hero hero;
	Font font;
	bool jumpUp, jumpDown;
	font.loadFromFile("Font/Roboto-Bold.ttf");
	Text dmg;
	dmg.setFillColor(Color(255, 0, 0));
	float textAnim = 0;
	dmg.setCharacterSize(20);
	dmg.setFont(font);
	Enemy enemy[20];
	for (int i = 0; i < 10; i++) {
		enemy[i].xPos = rand() % 12800 + 2000;
		enemy[i].speed = rand() % 5 + 1;
	}
	for (int i = 10; i < 20; i++) {
		enemy[i].xPos = rand() % 12800 + 2000;
		enemy[i].speed = rand() % 7 + 3;
	}
	Shader bloom;
	hero.shader.loadFromFile("Shaders/bloom.glsl", Shader::Fragment);
	Hero shadow[10];
	hero.xPos = 0, hero.yPos = 510;
	std::string state;
	Clock clock;
	float shadowTime = 0;
	float CurrentFrame = 0;
	while (window.isOpen())
	{
		Time time = clock.getElapsedTime();
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}
		int layerPos = 0;
		Background bg[12];
		for (int i = 0; i < 12; i++) {
			if (i == 1 || i == 4|| i == 8) {
				bg[i].setSprite(layerPos, 2);
			}
			else {
				bg[i].setSprite(layerPos, 1);
			}
			if (x >= 550) {
				bg[i].updatePos(layerPos - (x - 550)*0.7, layerPos - (x - 550)*0.8, layerPos - (x - 550)*0.9, layerPos - (x - 550));
			}
			layerPos += bg[i].getWidth();
		}

		//Обработка состояния героя
		state = "idle";
		if (Keyboard::isKeyPressed(Keyboard::Left) && x >= 15) {
			state = "run left";
			x -= 10;
			hero.xPos -= 10;
			if (x >= 550 && x <= layerPos - 550) {
				view.move(Vector2f(-10, 0));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) && x <= 6985) {
			state = "run right";
			x += 10;
			hero.xPos += 10;
			if (x >= 550 && x <= 7000) {
				view.move(Vector2f(10, 0));
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Space) && state == "run left") {
			state = "slice right";
		}
		else if (Keyboard::isKeyPressed(Keyboard::Space)) {
			state = "slice left";

		}
		if (Keyboard::isKeyPressed(Keyboard::Up) && !jumpUp && !jumpDown) {
			jumpUp = true;
		}
		if (jumpUp) {
			if (hero.yPos <= 380) {
				jumpUp = false;
				jumpDown = true;
			}
			else
			{
				hero.yPos -= 15;
			}
		}
		if (jumpDown) {
			if (hero.yPos >= 510) {
				jumpUp = false;
				jumpDown = false;
			}
			else
			{
				hero.yPos += 15;
			}
		}
		clock.restart().asMilliseconds();
		window.clear();
		window.setView(view);

		for (int layer = 0; layer < 4; layer++) {
			for (int i = 11; i >= 0; i--)
			{
				bg[i].draw(window, layer);
			}
		}
		if (state == "idle") {
			CurrentFrame += 0.03;
			if (shadowTime > 0) {
				shadowTime -= 0.5;
			}
		}
		else if (state == "run left" || state == "run right") {
			CurrentFrame += 0.2;
			if (shadowTime < 9) {
				shadowTime += 0.4;
			}
		}
		else if (state == "slice left" || state == "slice right") {
			CurrentFrame += 0.3;
			if (shadowTime < 9) {
				shadowTime += 0.4;
			}
		}
		if ((state == "idle", CurrentFrame > 2) || (state == "slice left", CurrentFrame > 2) || (state == "slice right", CurrentFrame > 2) ||
			(state == "run left", CurrentFrame > 4) || (state == "run right", CurrentFrame > 4)) {
			CurrentFrame = 0;
		}
		for (int i = 0; i < (int)shadowTime; i++) {
			shadow[i].yPos = hero.yPos;
			shadow[i].xPos = hero.xPos;
			if (state == "run left") {
				shadow[i].drawShadow(window, state, (int)CurrentFrame, 100 - 10 * i, i * 4);
			}
			else if (state == "run right") {
				shadow[i].drawShadow(window, state, (int)CurrentFrame, 100 - 10 * i, -i * 4);
			}
		}
		//Враги
		for (int i = 0; i < 20; i++) {
			if (std::abs(hero.xPos - enemy[i].xPos) < 1000) {
				if (hero.xPos - enemy[i].xPos >= -5) {
					if (!enemy[i].onCollision(hero.sprite.getGlobalBounds().left,
						hero.sprite.getGlobalBounds().left + hero.sprite.getGlobalBounds().width - 20)) {
						enemy[i].xPos += enemy[i].speed;
						enemy[i].explosion = 0;
					}
					else {
						enemy[i].explosion += 0.005;
					}

					if (i >= 10) {
						enemy[i].draw(window, 2, "right");
					}
					else
					{
						enemy[i].draw(window, 1, "right");
					}
				}
				else {
					if (!enemy[i].onCollision(hero.sprite.getGlobalBounds().left,
						hero.sprite.getGlobalBounds().left + hero.sprite.getGlobalBounds().width - 20)) {
						enemy[i].xPos -= enemy[i].speed;
						enemy[i].explosion = 0;
					}
					else {
						enemy[i].explosion += 0.005;
					}
					if (i >= 10) {
						enemy[i].draw(window, 2, "left");
					}
					else
					{
						enemy[i].draw(window, 1, "left");
					}
				}
			}
			else {
				if (hero.xPos - enemy[i].xPos >= -5) {
					if (i >= 10) {
						enemy[i].draw(window, 2, "right");
					}
					else
					{
						enemy[i].draw(window, 1, "right");
					}
				}
				else {
					if (i >= 10) {
						enemy[i].draw(window, 2, "left");
					}
					else
					{
						enemy[i].draw(window, 1, "left");
					}
				}

			}
			if (enemy[i].currentFrame >= 3.8) {
				enemy[i].currentFrame = 0;
			}
			else {
				enemy[i].currentFrame += 0.2;
			}
			if (enemy[i].explosion >= 1 && enemy[i].onCollision(hero.sprite.getGlobalBounds().left,
				hero.sprite.getGlobalBounds().left + hero.sprite.getGlobalBounds().width - 20) && enemy[i].life > 0) {
				hero.life -= 50;
				dmg.setString("50");
				dmg.setPosition(hero.sprite.getGlobalBounds().left + enemy[i].sprite.getGlobalBounds().width / 2,
					hero.sprite.getGlobalBounds().top + enemy[i].sprite.getGlobalBounds().height / 2);
				textAnim = 0.03;
				enemy[i].life = 0;
			}
			else if (enemy[i].onCollision(hero.sprite.getGlobalBounds().left,
				hero.sprite.getGlobalBounds().left + hero.sprite.getGlobalBounds().width - 20) && enemy[i].life > 0 && (state == "slice left" || state == "slice right")) {
				enemy[i].life -= 20;
				dmg.setString("20");
				dmg.setPosition(enemy[i].sprite.getGlobalBounds().left + enemy[i].sprite.getGlobalBounds().width / 2,
					enemy[i].sprite.getGlobalBounds().top + enemy[i].sprite.getGlobalBounds().height / 2);
				textAnim = 0.03;
			}

		}
		hero.draw(window, state, (int)CurrentFrame);
		if (textAnim > 0 && textAnim < 1) {
			textAnim += 0.05;
			dmg.setFillColor(Color(255, 0, 0, 255 * textAnim));
			dmg.setPosition(dmg.getPosition().x, dmg.getPosition().y - textAnim * 10);
			window.draw(dmg);
		}
		else if (textAnim >= 1) {
			textAnim = 0;
		}
		window.display();
	}

	return 0;
}