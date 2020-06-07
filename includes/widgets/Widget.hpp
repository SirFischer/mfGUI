#pragma once

#include <SFML/Graphics.hpp>
#include "utils/Positions.hpp"
#include "utils/Events.hpp"

#include "widgetComponents/Background.hpp"
#include "widgetComponents/EventManager.hpp"
#include "widgetComponents/Text.hpp"

namespace mf
{
	class Widget
	{
	protected:
		Widget(/* args */);
		virtual ~Widget();

		ePosition		mPositionType = ePosition::RELATIVE;
		sf::Vector2f	mPos = sf::Vector2f(0, 0);
		sf::Vector2f	mRelativePos = sf::Vector2f(0, 0);
		sf::Vector2f	mSize = sf::Vector2f(100, 100);

		Widget					*mParent = NULL;
		std::vector<Widget *>	mWidgets = std::vector<Widget *>();

		int				mIndex;

		virtual void	Render(sf::RenderWindow *tWindow);
		virtual void	HandleEvent(sf::Event &tEvent);

	public:
		friend class	GUI;

		static Widget 	*Create();
		Widget			*AddWidget(Widget *tWidget);
		void			RemoveWidget(Widget *tWidget);
		void			ClearWidgets();

		/**
		 * Setters
		 **/
		Widget			*SetPositionType(ePosition tPosType);
		Widget			*SetPosition(sf::Vector2f tPos);
		Widget			*SetPosition(float tX, float tY);
		Widget			*SetSize(float tX, float tY);
		Widget			*SetSize(sf::Vector2f tSize);

		/**
		 * Getters
		 **/

	};
	
} // namespace mf
