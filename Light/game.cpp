#include <SFML/Graphics.hpp>
#include "Background.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Light");
	sf::View view(sf::FloatRect(0, 0, 1280, 720));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Background bgCurrent(0, 1);
		Background bgNext(0 + bgCurrent.getWidth(), 1);
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			view.move(-10, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			view.move(10, 0);
		}
		window.setView(view);
		bgCurrent.draw(window);
		bgNext.draw(window);
		window.display();
	}

	return 0;
}