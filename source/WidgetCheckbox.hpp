/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#ifndef SFML_DEBUG_MENU_WIDGET_CHECKBOX_HPP
#define SFML_DEBUG_MENU_WIDGET_CHECKBOX_HPP

#include <SFML/Graphics.hpp>

#include "DebugWidget.hpp"

class WidgetCheckbox : public DebugWidget {
	bool value = false;
};

#endif
