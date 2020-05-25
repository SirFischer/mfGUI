#pragma once

#include "Widget.hpp"

namespace mf
{
    class Button : public Widget
    {
    private:
        Button(/* args */);
        ~Button();

        /**
		 * Components
		 **/
		component::Background  	mBackground;
		component::EventManager	mEventManager;

    public:
		void				HandleEvent(sf::Event &tEvent);
		void				Render(sf::RenderWindow *tWindow);

        /**
		 * Create
		 **/
        static Button      *Create(std::string tPathIdle, std::string tPathHover);
        static Button      *Create(sf::Color tIdle, sf::Color tHover);

		/**
		 * Setters
		 **/
		void				SetClickEvent(std::function<void()> tListener);
        
    };
} // namespace mf
