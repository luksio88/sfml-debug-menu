/*
	MIT License

	Copyright (c) 2022 luksio88

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
	
	Origin: https://github.com/luksio88/sfml-debug-menu
*/

#include <SFML/Graphics.hpp>

class DebugWidget { // todo: https://www.p-programowanie.pl/cpp/polimorfizm-metody-wirtualne
	int order = 0;
	std::string label = "Widget";
};

class WidgetButton : public DebugWidget {
	std::string value = "Push";
};

class WidgetCheckbox : public DebugWidget {
	bool value = false;
};

class WidgetDropdown : public DebugWidget {
	int value = 0;
};

class WidgetSlider : public DebugWidget {
	float value;
	float valueMin;
	float valueMax;
	float step;
};

class WidgetSpinner : public DebugWidget {
	float value;
	float valueMin;
	float valueMax;
	float step;
};

class DebugMenuTab : public DebugWidget {
	bool isExtended = false;
	std::string title = "Tab";
};

class WidgetTextbox : public DebugWidget {
	std::string value = "";
	bool isSelected = false;
	int limit = 0;
};

class DebugMenu : public sf::Drawable, public sf::Transformable { // todo: https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php#creating-an-sfml-like-entity
	bool isExtended = false;
	std::string extendPhrase = "Show";
	std::string retractPhrase = "Hide";
	
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	
public:
	DebugMenu(sf::Font font);
	void setExtendPhrase(std::string phrase);
	std::string getExtendPhrase();
};
