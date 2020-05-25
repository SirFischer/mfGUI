#pragma once

#include "Widget.hpp"

namespace mf
{
	class Image : public Widget
	{
	private:
		Image(/* args */);
		~Image();

		/**
		 * Components
		 **/
		component::Background mBackground;

	public:
		void	Render(sf::RenderWindow	*tWindow);

		/**
		 * Create
		 **/
		static Image *Create(std::string tPath);

		/**
		 * Setters
		 **/
		void	SetImage(std::string tPath);
		void	SetImage(sf::Texture &tTexture);
	};
} // namespace mf
