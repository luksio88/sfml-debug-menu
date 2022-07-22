/*
	An example of use sfml-debug-menu.
*/

#include "../debugMenu.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "sfml-debug-menu example");
	sf::Event event;
	
	// loading font
	sf::Font font;
	font.loadFromFile("resources/roboto-regular.ttf");
	
	// setting up our menu
	DebugMenu myMenu(font);
	
	while(window.isOpen()) {
		
		// EVENTS
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
                window.close();
			}
		}
		
		// RENDER
		window.clear(sf::Color::Black);
		
		window.draw(myMenu); // drawing menu
		
		window.display();
	}
}
