/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#ifndef SFML_DEBUG_MENU_WIDGET_BUTTON_HPP
#define SFML_DEBUG_MENU_WIDGET_BUTTON_HPP

#include <SFML/Graphics.hpp>

#include "DebugWidget.hpp"

class WidgetButton : public DebugWidget {
	std::string value = "Push";
	
public:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	
	WidgetButton(sf::Font &font);
};

#endif
