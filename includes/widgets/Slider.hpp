#pragma once

#include "Widget.hpp"
#include "Button.hpp"
#include "utils/Direction.hpp"

namespace mf
{
	class Slider : public Widget
	{
	private:
		Slider(/* args */);

		Button					*mButton;
		float					mValue = 0.f;

		/**
		 * Components
		 **/
		component::Background  	mBackground;
		eDirection				mDirection = eDirection::HORIZONTAL;

		/**
		 * HIDDEN MEMBERS
		 **/
		using					Widget::AddWidget;
		using					Widget::RemoveWidget;
		using					Widget::ClearWidgets;

		void					LoadClickFunction();

	public:
		~Slider();
		static Slider			*Create();

		void					Render(sf::RenderWindow	*tWindow);
		void					HandleEvent(sf::Event &tEvent);

		/**
		 * Setters
		 **/

		//Slider
		Slider					*SetValue(float tValue);
		float					GetValue(){return (std::clamp(mValue, 0.f, 1.f));}

		Slider					*SetDirection(eDirection tDirection);

		//Transform
		Slider					*SetPosition(sf::Vector2f tPos){Widget::SetPosition(tPos); mButton->SetPosition(mButton->GetRelativePosition()); return (this);}
		Slider					*SetPosition(float tX, float tY){Widget::SetPosition(tX, tY); mButton->SetPosition(mButton->GetRelativePosition()); return (this);}
		Slider					*SetSize(sf::Vector2f tSize){Widget::SetSize(tSize); return (this);}
		Slider					*SetSize(float tX, float tY){Widget::SetSize(tX, tY); return (this);}
		Slider					*SetSizePercentage(bool tPercentage) {Widget::SetSizePercentage(tPercentage); return (this);}
		Slider					*SetPositionPercentage(bool tPercentage) { Widget::SetPositionPercentage(tPercentage); return (this);}

		//Background
		Slider					*SetBackgroundColor(sf::Color tColor) {mBackground.SetBackground(tColor); return (this);}
		Slider					*SetOutlineThickness(float tThickness) {mBackground.SetOutlineThickness(tThickness); return (this);}
		Slider					*SetOutlineColor(sf::Color tColor){mBackground.SetOutlineColor(tColor); return (this);}

		Slider					*SetDisabled(bool tDisabled){mDisabled = tDisabled; return (this);}

		/**
		 * Getters
		 **/
		Button					*GetButton(){return (mButton);}

	};
}
