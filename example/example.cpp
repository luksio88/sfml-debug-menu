/*
	An example of use sfml-debug-menu.

	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#include "../source/DebugMenu.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "sfml-debug-menu example", sf::Style::Close);
	sf::Event event;
	
	// loading font
	sf::Font font;
	font.loadFromFile("resources/Roboto-Regular.ttf");
	
	// setting up our menu
	DebugMenu myMenu(font);
	myMenu.setPosition(sf::Vector2f(900, 0));
	
	// adding test widget
	myMenu.addWidget(WidgetTypeTab);
	myMenu.addWidget(WidgetTypeTab, "My Label");
	myMenu.addWidget(WidgetTypeTab, "First!", -1);
	
	while(window.isOpen()) {
		
		// EVENTS
		
		while(window.pollEvent(event)) {
			
			// handle events for menu
			myMenu.handleEvent(event);
			
			// rest of event handling
			if(event.type == sf::Event::Closed) {
                window.close();
			}
		}
		
		// RENDER
		
		window.clear(sf::Color(100, 100, 200));
		
		// drawing menu
		window.draw(myMenu);
		
		window.display();
	}
}
