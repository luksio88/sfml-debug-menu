/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#include "WidgetSpinner.hpp"

void WidgetSpinner::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	DebugWidget::draw(target, states);
	states.transform *= getTransform();
}

// CONSTRUCTOR

WidgetSpinner::WidgetSpinner(sf::Font &font) : DebugWidget(font) {
	
}

// PUBLIC METHODS
