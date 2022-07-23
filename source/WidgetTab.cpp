/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#include "WidgetTab.hpp"

#define PX_BLANK 0, 0, 0, 0
#define PX_WHITE 255, 255, 255, 255

const sf::Uint8 triangleTexturePixels[100] = {
	PX_BLANK, PX_BLANK, PX_WHITE, PX_BLANK, PX_BLANK,
	PX_BLANK, PX_BLANK, PX_WHITE, PX_WHITE, PX_BLANK,
	PX_BLANK, PX_BLANK, PX_WHITE, PX_WHITE, PX_WHITE,
	PX_BLANK, PX_BLANK, PX_WHITE, PX_WHITE, PX_BLANK,
	PX_BLANK, PX_BLANK, PX_WHITE, PX_BLANK, PX_BLANK,
};

void WidgetTab::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	DebugWidget::draw(target, states);
	states.transform *= getTransform();
	target.draw(triangle, states);
}

// CONSTRUCTOR

WidgetTab::WidgetTab(sf::Font &font) : DebugWidget(font) {
	triangleTexture.create(5, 5);
	triangleTexture.update(triangleTexturePixels);
	triangle.setTexture(triangleTexture);
	triangle.setPosition(sf::Vector2f(4, 17));
}