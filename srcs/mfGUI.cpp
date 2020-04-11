#include "mfGUI.hpp"

sf::Window	*mfGUI::mWindow = NULL;

void		mfGUI::Init(sf::Window *tWindow)
{
	mWindow = tWindow;
}

void		mfGUI::HandleEvents(sf::Event	&tEvent)
{
	(void)tEvent;
}

void		mfGUI::Render()
{

}