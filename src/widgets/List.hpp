#pragma once

#include "Widget.hpp"
#include "../widgetComponents/ScrollBar.hpp"
#include "../utils/Direction.hpp"

namespace mf
{
	class List : public Widget
	{
	public:

		enum class eOverflow
		{
			NOWRAP,
			WRAP,
			INVISIBLE
		};
	
	private:
		List(/* args */);
		

		/**
		 * Components
		 **/
		component::Background  	mBackground;
		component::ScrollBar	mScrollBar;

		/**
		 * Type specific vars
		 **/
		eDirection		mListDirection = eDirection::VERTICAL;
		eOverflow		mOverflow = eOverflow::NOWRAP;
		float			mItemSpacing = 5.f;
		sf::Vector2f	mContentOffset = sf::Vector2f(0, 0);

		void			UpdateChildren();
		void			UpdateContentData();

	public:
		~List();
		static std::shared_ptr<List>		Create();

		void			HandleEvent(sf::Event &tEvent);
		void			Render(sf::RenderWindow	*tWindow);

		/**
		 * Setters
		 **/

		//Background
		void			SetBackgroundColor(sf::Color tColor) {mBackground.SetBackground(tColor);}
		void			SetOutlineThickness(float tThickness) {mBackground.SetOutlineThickness(tThickness);}
		void			SetOutlineColor(sf::Color tColor){mBackground.SetOutlineColor(tColor);}

		//List
		void			SetItemSpacing(float tSpacing) {mItemSpacing = tSpacing;}
		void			SetItemDirection(eDirection tDirection) {mListDirection = tDirection;}
		void			SetContentOverflow(eOverflow tOverflow) {mOverflow = tOverflow;}
		void			SetContentOffset(sf::Vector2f tPos){mContentOffset = tPos;}

	};
}
