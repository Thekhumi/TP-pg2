#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main(){
	sf::RenderWindow window(sf::VideoMode(600, 600), "Smile");
	sf::Texture texture;
	texture.loadFromFile("image.bmp");

	sf::Sprite sprite;
	sprite.setTexture(texture);

	sf::Clock clock;

	while (window.isOpen()){
		sf::Event event;
		sf::Time elapsed = clock.restart();
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}
		/*switch (event.type) {
			case sf::Event::KeyPressed:
				switch (event.key.code){
					case sf::Keyboard::Up:
						sprite.move(0, -100*elapsed.asSeconds());
						break;
					case sf::Keyboard::Down:
						sprite.move(0, 100 * elapsed.asSeconds());
						break;
					case sf::Keyboard::Left:
						sprite.move(-100 * elapsed.asSeconds(), 0);
						break;
					case sf::Keyboard::Right:
						sprite.move(100 * elapsed.asSeconds(), 0);
						break;
				}
				break;
				
		}
		*/
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			sprite.move(0, -100 * elapsed.asSeconds());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			sprite.move(0, 100 * elapsed.asSeconds());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			sprite.move(-100 * elapsed.asSeconds(), 0);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			sprite.move(100 * elapsed.asSeconds(), 0);
		}
		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}