#pragma once

#include "Widget.hpp"
#include "List.hpp"

namespace mf
{
    class Select : public Widget
    {
    private:
        Select();
        ~Select();

        /**
		 * Components
		 **/
		component::Background  	mBackground;
		component::EventManager	mEventManager;
		component::Text			mText;

		List					*mList;

    public:
		void				HandleEvent(sf::Event &tEvent) override;
		void				Render(sf::RenderWindow *tWindow) override;

        /**
		 * Create
		 **/
        static Select      *Create(std::string tFont);

		/**
		 * Setters
		 **/
		Select				*SetClickEvent(std::function<void()> tListener);

		//Text
		Select				*SetText(std::string tText);
		Select				*SetTextFont(std::string tPath);
		Select				*SetTextFont(sf::Font tFont);
		Select				*SetTextPosition(sf::Vector2f tPos);
		Select				*SetTextColor(sf::Color tColor);

		//Background
		Select				*SetOutlineThickness(float tThickness);
		Select				*SetOutlineColor(sf::Color tColor);

		/**
		 * Overides
		 **/
		Select				*SetPosition(sf::Vector2f tPos){Widget::SetPosition(tPos); return (this);}
		Select				*SetPosition(float tX, float tY){Widget::SetPosition(tX, tY); return (this);}
		Select				*SetSize(sf::Vector2f tSize){Widget::SetSize(tSize); return (this);}
		Select				*SetSize(float tX, float tY){Widget::SetSize(tX, tY); return (this);}
		Select				*SetSizePercentage(bool tPercentage) { Widget::SetSizePercentage(tPercentage); return (this);}
		Select				*SetPositionPercentage(bool tPercentage) { Widget::SetPositionPercentage(tPercentage); return (this);}
        
    };
} // namespace mf
