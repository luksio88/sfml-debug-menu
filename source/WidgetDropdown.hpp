/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#ifndef SFML_DEBUG_MENU_WIDGET_DROPDOWN_HPP
#define SFML_DEBUG_MENU_WIDGET_DROPDOWN_HPP

#include <SFML/Graphics.hpp>

#include "DebugWidget.hpp"

class WidgetDropdown : public DebugWidget {
	int value = 0;
	
public:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	
	WidgetDropdown(sf::Font &font);
};

#endif
