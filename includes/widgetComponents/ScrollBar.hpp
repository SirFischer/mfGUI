#pragma once

#include <SFML/Graphics.hpp>
#include "../widgets/Slider.hpp"

namespace mf
{
	namespace component
	{
		class ScrollBar
		{
		private:
			sf::Vector2f					*mPos = NULL;
			sf::Vector2f					*mSize = NULL;
			
			mf::Slider						*mSlider;
		public:
			ScrollBar(sf::Vector2f *tPos, sf::Vector2f *tSize);
			~ScrollBar();

			void            				Draw(sf::RenderWindow *tWindow);
		};
	}
}