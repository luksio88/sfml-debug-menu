/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#include <algorithm>

#include "DebugMenu.hpp"

sf::Vector2f mouse; // current cursor position for internal use

void textCenterOrigin(sf::Text &text)
{
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin((int)(textRect.left + textRect.width/2.0f), (int)(textRect.top  + textRect.height/2.0f));
}

bool compareWidgetOrder(DebugWidget *w1, DebugWidget *w2) {
	return (w1->getOrder() < w2->getOrder());
}

sf::FloatRect translateFloatRect(sf::FloatRect rect, sf::Vector2f vector) {
	sf::FloatRect newRect(rect.left + vector.x, rect.top + vector.y, rect.width, rect.height);
	return newRect;
}

void DebugMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	int widgetShownCount = 0;
	if(isExtended) {
		for(int i = 0; i < widgetVector.size(); i++) {
			if(widgetVector[i]->getVisibility()) {
				widgetVector[i]->setPosition(sf::Vector2f(0, 40 * i));
				target.draw(*widgetVector[i], states);
				widgetShownCount++;
			}
		}
	}
	
	extendButtonBg.setPosition(sf::Vector2f(0, 40 * widgetShownCount));
	extendButtonText.setPosition(sf::Vector2f(150, 40 * widgetShownCount + 10));
	
	target.draw(extendButtonBg, states);
	target.draw(extendButtonText, states);
}

// CONSTRUCTOR

DebugMenu::DebugMenu(sf::Font &font) {
	DebugMenu::font = font;
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

void DebugMenu::toggle() {
	if(isExtended) retract();
	else extend();
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

void DebugMenu::handleEvent(sf::Event &event) {
	if(event.type == sf::Event::MouseButtonPressed) {
		if(translateFloatRect(extendButtonBg.getGlobalBounds(), this->getPosition()).contains(mouse)) { // mayby simplify it later
			toggle();
		}
	}
	else if(event.type == sf::Event::MouseMoved) {
		mouse.x = event.mouseMove.x;
		mouse.y = event.mouseMove.y;
	}
}

void DebugMenu::addWidget(WidgetType widgetType, std::string label, int order) {
	widgetVector.emplace_back();
	switch(widgetType) {
	case WidgetTypeButton:
		widgetVector.back() = new WidgetButton(font);
		break;
	case WidgetTypeCheckbox:
		widgetVector.back() = new WidgetCheckbox(font);
		break;
	case WidgetTypeDropdown:
		widgetVector.back() = new WidgetDropdown(font);
		break;
	case WidgetTypeSlider:
		widgetVector.back() = new WidgetSlider(font);
		break;
	case WidgetTypeSpinner:
		widgetVector.back() = new WidgetSpinner(font);
		break;
	case WidgetTypeTab:
		widgetVector.back() = new WidgetTab(font);
		break;
	case WidgetTypeTextbox:
		widgetVector.back() = new WidgetTextbox(font);
		break;
	}
	widgetVector.back()->setOrder(order);
	if(label == "") {
		widgetVector.back()->setLabel("Widget_" + std::to_string(widgetVector.size()));
	}
	else {
		widgetVector.back()->setLabel(label);
	}
	sort(widgetVector.begin(), widgetVector.end(), compareWidgetOrder);
}

DebugWidget *DebugMenu::getWidget(std::string label) {
	for(int i = 0; i < widgetVector.size(); i++) {
		if(widgetVector[i]->getLabel() == label) {
			return widgetVector[i];
		}
	}
	return NULL;
}
