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
			sf::Vector2f					*mContentSize = NULL;
			sf::Vector2f					*mContentPosition = NULL;
			
			std::shared_ptr<Slider>			mSlider;
		public:
			ScrollBar(sf::Vector2f *tPos, sf::Vector2f *tSize, sf::Vector2f *tContentSize, sf::Vector2f *tContentPosition);
			~ScrollBar();

			void							HandleEvent(sf::Event &tEvent);
			void            				Draw(sf::RenderWindow *tWindow);
			std::shared_ptr<Slider>			GetSlider(){return (mSlider);}
		};
	}
}