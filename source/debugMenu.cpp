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

#include "debugMenu.hpp"

void DebugMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	// states.transform *= getTransform(); // ??? is that necessary
}

DebugMenu::DebugMenu(sf::Font font) {
	
}

void DebugMenu::setExtendPhrase(std::string phrase) {
	extendPhrase = phrase;
	// todo reload font here
}

std::string DebugMenu::getExtendPhrase() {
	return extendPhrase;
}
