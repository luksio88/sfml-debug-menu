/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#include "WidgetTab.hpp"

#define PIXEL_BLANK 0, 0, 0, 0
#define PIXEL_WHITE 255, 255, 255, 255

const sf::Uint8 triangleTexturePixels[100] = {
	PIXEL_BLANK, PIXEL_BLANK, PIXEL_WHITE, PIXEL_BLANK, PIXEL_BLANK,
	PIXEL_BLANK, PIXEL_BLANK, PIXEL_WHITE, PIXEL_WHITE, PIXEL_BLANK,
	PIXEL_BLANK, PIXEL_BLANK, PIXEL_WHITE, PIXEL_WHITE, PIXEL_WHITE,
	PIXEL_BLANK, PIXEL_BLANK, PIXEL_WHITE, PIXEL_WHITE, PIXEL_BLANK,
	PIXEL_BLANK, PIXEL_BLANK, PIXEL_WHITE, PIXEL_BLANK, PIXEL_BLANK,
};

// CONSTRUCTOR

WidgetTab::WidgetTab() {
	triangleTexture.create(5, 5);
	triangleTexture.update(triangleTexturePixels);
	triangle.setTexture(triangleTexture);
}