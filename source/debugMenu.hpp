/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#ifndef SFML_DEBUG_MENU_DEBUG_MENU_HPP
#define SFML_DEBUG_MENU_DEBUG_MENU_HPP

#include <SFML/Graphics.hpp>

#include "DebugWidget.hpp"
#include "WidgetButton.hpp"
#include "WidgetCheckbox.hpp"
#include "WidgetDropdown.hpp"
#include "WidgetSlider.hpp"
#include "WidgetSpinner.hpp"
#include "WidgetTab.hpp"
#include "WidgetTextbox.hpp"

class DebugMenu : public sf::Drawable, public sf::Transformable {
	bool isExtended = false;
	std::string extendPhrase = "Show";
	std::string retractPhrase = "Hide";
	
	sf::Text extendButtonText;
	sf::RectangleShape extendButtonBg;
	
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
