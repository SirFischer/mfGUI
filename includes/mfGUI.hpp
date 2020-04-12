#pragma once

#include "widgets/Widget.hpp"

namespace mf
{
	class GUI
	{
	private:
		GUI(/* args */);
		~GUI();
		static sf::Window	*mWindow;
		static Widget		*mBaseWidget;

	public:
		static void				Init(sf::Window *tWindow);
		static void				HandleEvent(sf::Event	&tEvent);
		static void				Render();

		static void				AddWidget(Widget *tWidget);
		static void				RemoveWidget(Widget *tWidget);
		static void				ClearWidgets();

		static void				Render();

	};
} // namespace mf
