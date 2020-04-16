#pragma once

#include <SFML/Graphics.hpp>
#include "utils/Positions.hpp"
#include "../widgetComponents/Background.hpp"

namespace mf
{
	class Widget
	{
	protected:
		Widget(/* args */);
		virtual ~Widget();

		Widget					*mParent = NULL;
		std::vector<Widget *>	mWidgets;

		ePosition		mPositionType = ePosition::RELATIVE;
		sf::Vector2f	mPos = sf::Vector2f(0, 0);
		sf::Vector2f	mSize = sf::Vector2f(100, 100);

		int				mIndex;

		virtual void	Render(sf::RenderWindow *tWindow);
		void			HandleEvent(sf::Event &tEvent);

	public:
		friend class	GUI;

		static Widget 	*Create();
		void			AddWidget(Widget *tWidget);
		void			RemoveWidget(Widget *tWidget);
		void			ClearWidgets();
		/**
		 * Components
		 **/
		Background  	mBackground;

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
