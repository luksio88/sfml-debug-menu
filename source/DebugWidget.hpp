/*
	Copyright (c) 2022 luksio88
	Origin: https://github.com/luksio88/sfml-debug-menu
	For license information check "LICENSE" file.
*/

#ifndef SFML_DEBUG_MENU_DEBUG_WIDGET_HPP
#define SFML_DEBUG_MENU_DEBUG_WIDGET_HPP

#include <SFML/Graphics.hpp>

enum WidgetType {
	WidgetTypeButton,
	WidgetTypeCheckbox,
	WidgetTypeDropdown,
	WidgetTypeSlider,
	WidgetTypeSpinner,
	WidgetTypeTab,
	WidgetTypeTextbox
};

class DebugWidget : public sf::Drawable, public sf::Transformable { // todo: https://www.p-programowanie.pl/cpp/polimorfizm-metody-wirtualne
protected:
	int order = 0;
	bool isVisible = true;
	std::string label = "Widget";
	
	sf::Text labelText;
	sf::RectangleShape background;
	sf::RectangleShape border;

public:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	
	DebugWidget(sf::Font &font);
	
	void setOrder(int order);
	void setLabel(std::string label);
	void setVisibility(bool visibility);
	
	int getOrder();
	std::string getLabel();
	bool getVisibility();
};

#endif
