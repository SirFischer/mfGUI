#pragma once

#include "widgets/widget.hpp"

namespace mf
{
	class GUI
	{
	private:
		GUI(/* args */);
		~GUI();
		static sf::Window	*mWindow;

	public:
		static void				Init(sf::Window *tWindow);
		static void				HandleEvents(sf::Event	&tEvent);
		static void				Render();

		static void				AddWidget(widget *tWidget);
		static void				RemoveWidget(widget *tWidget);

	};
} // namespace mf
