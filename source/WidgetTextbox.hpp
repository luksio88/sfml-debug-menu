/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#ifndef SFML_DEBUG_MENU_WIDGET_TEXTBOX_HPP
#define SFML_DEBUG_MENU_WIDGET_TEXTBOX_HPP

#include <SFML/Graphics.hpp>

#include "DebugWidget.hpp"

class WidgetTextbox : public DebugWidget { //todo https://www.youtube.com/watch?v=T31MoLJws4U
	std::string value = "";
	bool isSelected = false;
	int limit = 0;
};

#endif
