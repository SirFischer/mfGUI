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
			sf::Vector2f		*mPos = NULL;
			sf::Vector2f		*mSize = NULL;

			sf::Vector2f		mRelPos = sf::Vector2f(0.f, 0.f);

			sf::Font			mFont;
			sf::Text			mText;
			
		public:
			Text(sf::Vector2f *tPos,sf::Vector2f *tSize);
			~Text();

			void			LoadFont(std::string tPath);
			void			LoadFont(sf::Font tFont);

			void			SetString(std::string tString);
			void			SetSize(unsigned int tSize);
			void			SetPos(sf::Vector2f tPos);

			void            Draw(sf::RenderWindow *tWindow);
		};
	}
} // namespace mf
