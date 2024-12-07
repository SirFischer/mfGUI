#pragma once

#include "Widget.hpp"
#include "../widgetComponents/Background.hpp"

namespace mf
{
    class Button : public Widget
    {
    private:
        Button(/* args */);

        /**
		 * Components
		 **/
		component::Background  	mBackground;
		component::Text			mText;

    public:
		~Button();
		void					Render(sf::RenderWindow *tWindow) override;

        /**
		 * Create
		 **/
        static Button      		*Create();

		/**
		 * Setters
		 **/
		void					SetClickEvent(std::function<void()> tListener);
		void					AddEventListener(eEvent tEvent, std::function<void()> tListener);

		//Background
		void					SetBackground(component::Background tBackground){mBackground = tBackground;}
		component::Background	*GetBackground(){return (&mBackground);}

		//Text
		void					SetText(component::Text tText){mText = tText;}
		component::Text			*GetText(){return (&mText);}
    };
} // namespace mf
