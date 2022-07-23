/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#ifndef SFML_DEBUG_MENU_WIDGET_TAB_HPP
#define SFML_DEBUG_MENU_WIDGET_TAB_HPP

#include <SFML/Graphics.hpp>

#include "DebugWidget.hpp"

class WidgetTab : public DebugWidget {
	bool isExtended = false;
	std::string title = "Tab";
	
	sf::Texture triangleTexture;
	sf::Sprite triangle;
	
  public:
	WidgetTab();
};

#endif
