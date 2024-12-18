#pragma once

#include "Widget.hpp"
#include "../widgetComponents/Background.hpp"

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
		static std::shared_ptr<Image>	Create();

		/**
		 * Setters
		 **/
		void			SetImage(std::string tPath);
		void			SetImage(sf::Texture &tTexture);

	};
} // namespace mf
