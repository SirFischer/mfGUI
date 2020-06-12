#pragma once

#include "Widget.hpp"

namespace mf
{
	class Text : public Widget
	{
	private:
		Text(/* args */);
		~Text();

		/**
		 * Components
		 **/
		component::Background   mBackground;
        component::Text         mText;

	public:
		void			Render(sf::RenderWindow	*tWindow);

		/**
		 * Create
		 **/
		static Text		*Create(std::string tFontPath, std::string tString);

		/**
		 * Setters
		 **/
		Text			*SetText(std::string tText);
		Text			*AddText(std::string tText) {mText.AddString(tText); return (this);}
		Text			*SetTextFont(std::string tPath);
		Text			*SetTextFont(sf::Font tFont);
		Text			*SetTextPosition(sf::Vector2f tPos);
		Text			*SetTextColor(sf::Color tColor);

		Text			*SetOutlineThickness(float tThickness);
		Text			*SetOutlineColor(sf::Color tColor);

		/**
		 * Overides
		 **/
		Text			*SetPositionType(ePosition tPosType){Widget::SetPositionType(tPosType); return (this);}
		Text			*SetPosition(sf::Vector2f tPos){Widget::SetPosition(tPos); return (this);}
		Text			*SetPosition(float tX, float tY){Widget::SetPosition(tX, tY); return (this);}
		Text			*SetSize(sf::Vector2f tSize){Widget::SetSize(tSize); mText.ReformatString(); return (this);}
		Text			*SetSize(float tX, float tY){Widget::SetSize(tX, tY); mText.ReformatString(); return (this);}
	};
} // namespace mf
