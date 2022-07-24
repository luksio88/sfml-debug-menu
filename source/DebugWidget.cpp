/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#include "DebugWidget.hpp"

void DebugWidget::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(background, states);
	target.draw(border, states);
	target.draw(labelText, states);
}

// CONSTRUCTOR

DebugWidget::DebugWidget(sf::Font &font) {
	labelText.setFont(font);
	labelText.setCharacterSize(12);
	labelText.setFillColor(sf::Color::White);
	labelText.setString(label);
	labelText.setPosition(sf::Vector2f(10, 11));
	
	background.setSize(sf::Vector2f(300, 38));
	background.setFillColor(sf::Color(0, 0, 0, 128));
	
	border.setSize(sf::Vector2f(300, 2));
	border.setFillColor(sf::Color(255, 255, 255, 128));
	border.setPosition(sf::Vector2f(0, 38));
}

// PUBLIC METHODS

void DebugWidget::setOrder(int order) {
	
}