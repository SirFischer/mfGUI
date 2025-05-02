#pragma once

#include "Widget.hpp"
#include "../widgetComponents/ScrollBar.hpp"
#include "../widgetComponents/Background.hpp"
#include "../widgetComponents/Text.hpp"

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

		void					FlashingCursor();
		sf::Clock				mFlashingCursorClock;
		bool					mFlashingCursor = false;

	public:
		~Text();
		void			HandleEvent(sf::Event &tEvent) override;
		void			Update() override;
		void			Render(sf::RenderWindow	*tWindow) override;

		/**
		 * Create
		 **/
		static std::shared_ptr<Text>		Create();

		void			EnableEdit();
		void			DisableEdit();

		
		//Default: -1 for no limit
		void			SetMaxTextLength(int tLength){mMaxTextLength = tLength;}

		void			SetBackground(mf::component::Background tBackground){mBackground = tBackground;}
		mf::component::Background	*GetBackground(){return (&mBackground);}

		void			SetText(mf::component::Text tText){mText = tText;}
		mf::component::Text	*GetText(){return (&mText);}

		/**
		 * Getters
		 **/
		std::string					GetString() { return (mText.GetString());}
		std::shared_ptr<Slider>		GetScrollBar(){return (mScrollBar.GetSlider());}

	};
} // namespace mf
