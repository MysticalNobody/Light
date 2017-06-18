#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Hero.h"
int main()
{
	int x = 0;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Light");
	sf::View view(sf::FloatRect(0, 0, 1280, 720));
	Hero hero;
	hero.xPos = 0, hero.yPos = 510;
	std::string state;
	while (window.isOpen())
	{
		float CurrentFrame = 0;
		Clock clock;
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
		if (Keyboard::isKeyPressed(Keyboard::Left) && x >= 10) {
			state = "run left";
			hero.xPos -= 10;
			if (x >= 550) {
				view.move(-10, 0);
			}
			x -= 10;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			state = "run right";
			x += 10;
			hero.xPos += 10;
			if (x > 550) {
				view.move(10, 0);
			}
		}
		window.setView(view);
		for (int i = 0; i < 12; i++)
		{
			bg[i].draw(window);
		}

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;
		CurrentFrame += 0.025*time;
		if ((state == "idle", CurrentFrame > 2) || (state == "run left", CurrentFrame > 4) || (state == "run right", CurrentFrame > 4)) {
			CurrentFrame = 0;
		}
		hero.draw(window, state, (int)CurrentFrame);
		window.display();
	}

	return 0;
}