#pragma once

#include <SFML/Graphics.hpp>

class mfGUI
{
private:
	mfGUI(/* args */);

	static sf::Window	*mWindow;

public:
	~mfGUI();

	static void				Init(sf::Window *tWindow);
	static void				HandleEvents(sf::Event	&tEvent);
	static void				Render();

};


