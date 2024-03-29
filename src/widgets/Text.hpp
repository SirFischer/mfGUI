#pragma once

#include "Widget.hpp"
#include "../widgetComponents/ScrollBar.hpp"

namespace mf
{
	class Text : public Widget
	{
	private:

		Text();

		/**
		 * Components
		 **/
		component::Background   mBackground;
		component::ScrollBar	mScrollBar;
        component::Text         mText;

		bool					mIsEditable = false;

		int						mMaxTextLength = -1;

	public:
		~Text();
		void			HandleEvent(sf::Event &tEvent);
		void			Render(sf::RenderWindow	*tWindow);

		/**
		 * Create
		 **/
		static Text		*Create();

		Text			*EnableEdit();
		Text			*DisableEdit();

		/**
		 * Setters
		 **/
		Text			*SetText(std::string tText);
		Text			*AddText(std::string tText) {mText.AddString(tText); return (this);}
		Text			*DeleteText(size_t tNum) {mText.DeleteString(tNum); return (this);}
		Text			*SetTextFont(std::string tPath);
		Text			*SetTextFont(sf::Font tFont);
		Text			*SetTextPosition(sf::Vector2f tPos);
		Text			*SetTextColor(sf::Color tColor);
		Text			*SetCharacterSize(unsigned int tSize);

		Text			*SetDisabled(bool tDisabled){mDisabled = tDisabled; return (this);}
		
		//Default: -1 for no limit
		Text			*SetMaxTextLength(int tLength){mMaxTextLength = tLength; return (this);}

		//Background
		Text			*SetBackgroundColor(sf::Color tColor) {mBackground.SetBackground(tColor); return (this);}
		Text			*SetOutlineThickness(float tThickness) {mBackground.SetOutlineThickness(tThickness); return (this);}
		Text			*SetOutlineColor(sf::Color tColor){mBackground.SetOutlineColor(tColor); return (this);}

		/**
		 * Overides
		 **/
		Text			*SetPosition(sf::Vector2f tPos){Widget::SetPosition(tPos); return (this);}
		Text			*SetPosition(float tX, float tY){Widget::SetPosition(tX, tY); return (this);}
		Text			*SetSize(sf::Vector2f tSize){Widget::SetSize(tSize); return (this);}
		Text			*SetSize(float tX, float tY){Widget::SetSize(tX, tY); return (this);}
		Text			*SetSizePercentage(bool tPercentageX, bool tPercentageY) { Widget::SetSizePercentage(tPercentageX, tPercentageY); return (this);}
		Text			*SetPositionPercentage(bool tPercentageX, bool tPercentageY) { Widget::SetPositionPercentage(tPercentageX, tPercentageY); return (this);}

		/**
		 * Getters
		 **/
		std::string		GetString() { return (mText.GetString());}
		mf::Slider		*GetScrollBar(){return (mScrollBar.GetSlider());}

	};
} // namespace mf
