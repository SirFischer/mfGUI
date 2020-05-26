#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

namespace mf
{
	namespace component
	{
		class Text
		{
		protected:
			
			sf::Vector2f                            *mPos = NULL;
			sf::Vector2f                            *mSize = NULL;
			
		public:
			Text(sf::Vector2f *tPos,sf::Vector2f *tSize);
			~Text();
			
			void            Draw();
		};
	}
} // namespace mf
