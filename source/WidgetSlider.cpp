/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#include "WidgetSlider.hpp"

void WidgetSlider::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	DebugWidget::draw(target, states);
	states.transform *= getTransform();
}

// CONSTRUCTOR

WidgetSlider::WidgetSlider(sf::Font &font) : DebugWidget(font) {
	
}

// PUBLIC METHODS
