#pragma once

#include <SFML/Graphics.hpp>
#include "Positions.hpp"

namespace mf
{
	class Widget
	{
	protected:
		Widget(/* args */);
		~Widget();

		Widget					*mParent = NULL;
		std::vector<Widget *>	mWidgets;

		ePosition		mPositionType = ePosition::RELATIVE;
		sf::Vector2f	mPos = sf::Vector2f(0, 0);
		sf::Vector2f	mSize = sf::Vector2f(100, 100);

		int				mIndex;

		void			Render(sf::Window *tWindow);
		void			HandleEvent(sf::Event &tEvent);

	public:
		friend class	GUI;

		static Widget 	*Create();
		void			AddWidget(Widget *tWidget);
		void			RemoveWidget(Widget *tWidget);
		void			ClearWidgets();

		/**
		 * Setters
		 **/
		Widget			*SetPositionType(ePosition tPosType);
		Widget			*SetPosition(sf::Vector2f tPos);
		Widget			*SetSize(sf::Vector2f tSize);

		/**
		 * Getters
		 **/

	};
	
} // namespace mf
