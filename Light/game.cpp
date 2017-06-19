#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Hero.h"
int main()
{
	int x = 0;
	RenderWindow window(VideoMode(1280, 720), "Light");
	View view(FloatRect(0, 0, 1280, 720));
	Hero hero;
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
			if (i == 2) {
				bg[i].setSprite(layerPos, 2);
			}
			else {
				bg[i].setSprite(layerPos, 1);
			}
			layerPos += bg[i].getWidth();
		}
		state = "idle";
		if (Keyboard::isKeyPressed(Keyboard::Left) && x >= 15) {
			state = "run left";
			x -= 10;
			hero.xPos -= 10;
			if (x >= 550) {
				view.move(Vector2f(-10, 0));
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			state = "run right";
			x += 10;
			hero.xPos += 10;
			if (x >= 550) {
				view.move(Vector2f(10, 0));
			}
		}
		clock.restart().asMilliseconds();
		window.clear();
		window.setView(view);
		for (int i = 0; i < 12; i++)
		{
			bg[i].draw(window);
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
		if ((state == "idle", CurrentFrame > 2) || (state == "run left", CurrentFrame > 4) || (state == "run right", CurrentFrame > 4)) {
			CurrentFrame = 0;
		}
		for (int i = 0; i < (int)shadowTime; i++) {
			shadow[i].yPos = hero.yPos;
			shadow[i].xPos = hero.xPos;
			if (state == "run left") {
				shadow[i].drawShadow(window, state, (int)CurrentFrame, 100 - 10*i, i * 4);
			}
			else if (state == "run right") {
				shadow[i].drawShadow(window, state, (int)CurrentFrame, 100 - 10 * i, -i * 4);
			}
		}
		hero.draw(window, state, (int)CurrentFrame);
		window.display();
	}

	return 0;
}