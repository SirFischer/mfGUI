#pragma once

#include "Widget.hpp"
#include "Button.hpp"
#include "../utils/Direction.hpp"
#include "../widgetComponents/Background.hpp"

namespace mf
{
	class Slider : public Widget
	{
	private:
		Slider(/* args */);

		Button					*mButton;
		float					mValue = 0.f;
		std::function<void()> 	mChangeListener = [](){};
		eDirection				mDirection = eDirection::HORIZONTAL;

		/**
		 * Components
		 **/
		component::Background  	mBackground;

		/**
		 * HIDDEN MEMBERS
		 **/
		using					Widget::AddWidget;
		using					Widget::RemoveWidget;
		using					Widget::ClearWidgets;

		void					LoadClickFunction();
		void					SetButtonHeight();

	public:
		~Slider();
		static Slider			*Create();

		void					Render(sf::RenderWindow	*tWindow);
		void					HandleEvent(sf::Event &tEvent);

		/**
		 * Setters
		 **/

		//Slider
		void					SetValue(float tValue);
		float					GetValue(){return (std::clamp(mValue, 0.f, 1.f));}
		void					SetChangeEventListener(std::function<void()> tListener) { mChangeListener = tListener; }


		void					SetDirection(eDirection tDirection);

		//Transform
		void					SetPosition(sf::Vector2f tPos){Widget::SetPosition(tPos); mButton->SetPosition(mButton->GetRelativePosition());}
		void					SetPosition(float tX, float tY){Widget::SetPosition(tX, tY); mButton->SetPosition(mButton->GetRelativePosition());}
		void					SetSize(sf::Vector2f tSize) override;
		void					SetSize(float tX, float tY) override;
		void					SetSizePercentage(bool tPercentageX, bool tPercentageY) { Widget::SetSizePercentage(tPercentageX, tPercentageY);}
		void					SetPositionPercentage(bool tPercentageX, bool tPercentageY) { Widget::SetPositionPercentage(tPercentageX, tPercentageY);}

		//Background
		void					SetBackground(component::Background tBackground){mBackground = tBackground;}
		component::Background	*GetBackground(){return (&mBackground);}

		/**
		 * Getters
		 **/
		Button					*GetButton(){return (mButton);}

	};
}
