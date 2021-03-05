#pragma once

#include "Widget.hpp"

namespace mf
{
	class Container : public Widget
	{
	private:
		Container(/* args */);
		

		/**
		 * Components
		 **/
		component::Background mBackground;

	public:
		~Container();
		void				Render(sf::RenderWindow	*tWindow);

		/**
		 * Create
		 **/
		static Container	*Create();

		/**
		 * Setters
		 **/

		Container			*SetDisabled(bool tDisabled){mDisabled = tDisabled; return (this);}


		Container			*SetOutlineThickness(float tThickness);
		Container			*SetOutlineColor(sf::Color tColor);

		Container			*SetBackground(sf::Color tColor){mBackground.SetBackground(tColor); return (this);}

		/**
		 * Overides
		 **/
		Container			*SetPosition(sf::Vector2f tPos){Widget::SetPosition(tPos); return (this);}
		Container			*SetPosition(float tX, float tY){Widget::SetPosition(tX, tY); return (this);}
		Container			*SetSize(sf::Vector2f tSize){Widget::SetSize(tSize); return (this);}
		Container			*SetSize(float tX, float tY){Widget::SetSize(tX, tY); return (this);}
		Container			*SetSizePercentage(bool tPercentage) { Widget::SetSizePercentage(tPercentage); return (this);}
		Container			*SetPositionPercentage(bool tPercentage) { Widget::SetPositionPercentage(tPercentage); return (this);}
	};
} // namespace mf
