/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#include "DebugMenu.hpp"

void textCenterOrigin(sf::Text &text)
{
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin((int)(textRect.left + textRect.width/2.0f), (int)(textRect.top  + textRect.height/2.0f));
}

void DebugMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(extendButtonBg, states);
	target.draw(extendButtonText, states);
}

// CONSTRUCTOR

DebugMenu::DebugMenu(sf::Font &font) {
	extendButtonText.setFont(font);
	extendButtonText.setCharacterSize(12);
	extendButtonText.setFillColor(sf::Color::White);
	extendButtonText.setString(extendPhrase);
	textCenterOrigin(extendButtonText);
	extendButtonText.setPosition(sf::Vector2f(150, 10));
	
	extendButtonBg.setSize(sf::Vector2f(300, 20));
	extendButtonBg.setFillColor(sf::Color(0, 0, 0, 128));
}

// PUBLIC METHODS

void DebugMenu::extend() {
	isExtended = true;
	extendButtonText.setString(retractPhrase);
	textCenterOrigin(extendButtonText);
}

void DebugMenu::retract() {
	isExtended = false;
	extendButtonText.setString(extendPhrase);
	textCenterOrigin(extendButtonText);
}

void DebugMenu::setExtendPhrase(std::string phrase) {
	extendPhrase = phrase;
	if(!isExtended) {
		extendButtonText.setString(phrase);
		textCenterOrigin(extendButtonText);
	}
}

void DebugMenu::setRetractPhrase(std::string phrase) {
	retractPhrase = phrase;
	if(isExtended) {
		extendButtonText.setString(phrase);
		textCenterOrigin(extendButtonText);
	}
}

std::string DebugMenu::getExtendPhrase() {
	return extendPhrase;
}

std::string DebugMenu::getRetractPhrase() {
	return retractPhrase;
}
