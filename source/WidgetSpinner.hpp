/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#ifndef SFML_DEBUG_MENU_WIDGET_SPINNER_HPP
#define SFML_DEBUG_MENU_WIDGET_SPINNER_HPP

#include <SFML/Graphics.hpp>

#include "DebugWidget.hpp"

class WidgetSpinner : public DebugWidget {
	float value;
	float valueMin;
	float valueMax;
	float step;
	
public:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	
	WidgetSpinner(sf::Font &font);
};

#endif
