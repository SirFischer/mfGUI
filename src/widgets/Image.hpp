#pragma once

#include "Widget.hpp"

namespace mf
{
	class Image : public Widget
	{
	private:
		Image(/* args */);
		

		/**
		 * Components
		 **/
		component::Background mBackground;

	public:
		~Image();
		void	Render(sf::RenderWindow	*tWindow);

		/**
		 * Create
		 **/
		static Image	*Create();

		/**
		 * Setters
		 **/
		Image			*SetImage(std::string tPath);
		Image			*SetImage(sf::Texture &tTexture);

		Image			*SetDisabled(bool tDisabled){mDisabled = tDisabled; return (this);}


		Image			*SetOutlineThickness(float tThickness);
		Image			*SetOutlineColor(sf::Color tColor);

		/**
		 * Overides
		 **/
		Image			*SetPosition(sf::Vector2f tPos){Widget::SetPosition(tPos); return (this);}
		Image			*SetPosition(float tX, float tY){Widget::SetPosition(tX, tY); return (this);}
		Image			*SetSize(sf::Vector2f tSize){Widget::SetSize(tSize); return (this);}
		Image			*SetSize(float tX, float tY){Widget::SetSize(tX, tY); return (this);}
		Image			*SetSizePercentage(bool tPercentageX, bool tPercentageY) { Widget::SetSizePercentage(tPercentageX, tPercentageY); return (this);}
		Image			*SetPositionPercentage(bool tPercentageX, bool tPercentageY) { Widget::SetPositionPercentage(tPercentageX, tPercentageY); return (this);}
	};
} // namespace mf
