#include "mfGUI.hpp"

namespace mf
{
	sf::Window	*GUI::mWindow = NULL;

	void		GUI::Init(sf::Window *tWindow)
	{
		mWindow = tWindow;
	}

	void		GUI::HandleEvents(sf::Event	&tEvent)
	{
		(void)tEvent;
	}

	void		GUI::Render()
	{

	}

	void		GUI::AddWidget(widget *tWidget)
	{
		(void)tWidget;
	}

	void		GUI::RemoveWidget(widget *tWidget)
	{
		(void)tWidget;
	}

} // namespace mf

