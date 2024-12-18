#pragma once

#include "widgets/Widget.hpp"
#include "widgets/Slider.hpp"
#include "widgets/Image.hpp"
#include "widgets/Button.hpp"
#include "widgets/Text.hpp"
#include "widgets/List.hpp"
#include "widgets/Container.hpp"
#include "widgets/Checkbox.hpp"

namespace mf
{
	class GUI
	{
	private:
		GUI(/* args */);
		~GUI();
		static sf::RenderWindow			*mWindow;
		static std::shared_ptr<Widget>	mBaseWidget;

	public:
		static void				Init(sf::RenderWindow *tWindow);
		static void				HandleEvent(sf::Event	&tEvent);
		static void				Render();

		static void				AddWidget(std::shared_ptr<Widget> tWidget);
		static void				RemoveWidget(std::shared_ptr<Widget> tWidget);
		static void				ClearWidgets();

	};
} // namespace mf
