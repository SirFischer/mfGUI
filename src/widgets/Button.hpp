#pragma once

#include "Widget.hpp"

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
		void				Render(sf::RenderWindow *tWindow);

        /**
		 * Create
		 **/
        static Button      *Create();

		/**
		 * Setters
		 **/
		Button				*SetClickEvent(std::function<void()> tListener);
		Button				*AddEventListener(eEvent tEvent, std::function<void()> tListener);

		Button				*SetDisabled(bool tDisabled){mDisabled = tDisabled; return (this);}


		//Text
		Button				*SetText(std::string tText);
		Button				*SetTextFont(std::string tPath);
		Button				*SetTextFont(sf::Font tFont);
		Button				*SetTextPosition(sf::Vector2f tPos);
		Button				*SetTextPosition(float tX, float tY);
		Button				*SetTextColor(sf::Color tColor);

		Button				*SetCharacterSize(unsigned int tSize);

		//Background
		Button				*SetOutlineThickness(float tThickness);
		Button				*SetOutlineColor(sf::Color tColor);
		Button				*SetBackground(const sf::Color &tColor);
		Button				*SetBackground(const sf::Texture &tTexture);

		/**
		 * Overides
		 **/
		Button				*SetPosition(sf::Vector2f tPos){Widget::SetPosition(tPos); return (this);}
		Button				*SetPosition(float tX, float tY){Widget::SetPosition(tX, tY); return (this);}
		Button				*SetSize(sf::Vector2f tSize){Widget::SetSize(tSize); return (this);}
		Button				*SetSize(float tX, float tY){Widget::SetSize(tX, tY); return (this);}
		Button				*SetSizePercentage(bool tPercentageX, bool tPercentageY) { Widget::SetSizePercentage(tPercentageX, tPercentageY); return (this);}
		Button				*SetPositionPercentage(bool tPercentageX, bool tPercentageY) { Widget::SetPositionPercentage(tPercentageX, tPercentageY); return (this);}

		/**
		 * Getters
		 */
		sf::Vector2f		GetTextPosition(){return (mText.GetPosition());}
    };
} // namespace mf
