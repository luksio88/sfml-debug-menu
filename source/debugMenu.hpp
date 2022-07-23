/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#ifndef SFML_DEBUG_MENU_DEBUG_MENU_HPP
#define SFML_DEBUG_MENU_DEBUG_MENU_HPP

#include <SFML/Graphics.hpp>

class DebugWidget { // todo: https://www.p-programowanie.pl/cpp/polimorfizm-metody-wirtualne
	int order = 0;
	std::string label = "Widget";
};

class WidgetButton : public DebugWidget {
	std::string value = "Push";
};

class WidgetCheckbox : public DebugWidget {
	bool value = false;
};

class WidgetDropdown : public DebugWidget {
	int value = 0;
};

class WidgetSlider : public DebugWidget {
	float value;
	float valueMin;
	float valueMax;
	float step;
};

class WidgetSpinner : public DebugWidget {
	float value;
	float valueMin;
	float valueMax;
	float step;
};

class DebugMenuTab : public DebugWidget {
	bool isExtended = false;
	std::string title = "Tab";
};

class WidgetTextbox : public DebugWidget { //todo https://www.youtube.com/watch?v=T31MoLJws4U
	std::string value = "";
	bool isSelected = false;
	int limit = 0;
};

class DebugMenu : public sf::Drawable, public sf::Transformable {
	bool isExtended = false;
	std::string extendPhrase = "Show";
	std::string retractPhrase = "Hide";
	
	sf::Text extendButtonText;
	sf::RectangleShape extendButtonBg;
	sf::Texture triangleTexture;
	sf::Sprite triangle; // todo: MOVE TRIANGLE (and every its resources) TO TABS !!!
	
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	
public:
	DebugMenu(sf::Font &font);
	
	void extend();
	
	void retract();
	
	void setExtendPhrase(std::string phrase);
	
	void setRetractPhrase(std::string phrase);
	
	std::string getExtendPhrase();
	
	std::string getRetractPhrase();
};

#endif
