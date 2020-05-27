#include "Text.hpp"

namespace mf
{
	namespace component
	{
		Text::Text(sf::Vector2f *tPos,sf::Vector2f *tSize)
		:mPos(tPos)
		,mSize(tSize)
		{

		}
		
		Text::~Text()
		{
		}

		void			Text::LoadFont(std::string tPath)
		{
			mFont.loadFromFile(tPath);
			mText.setFont(mFont);
		}

		void			Text::LoadFont(sf::Font tFont)
		{
			mFont = tFont;
			mText.setFont(mFont);
		}

		void			Text::SetString(std::string tString)
		{
			mText.setString(tString);
		}

		void			Text::SetSize(unsigned int tSize)
		{
			mText.setCharacterSize(tSize);
		}

		void			Text::SetPos(sf::Vector2f tPos)
		{
			mRelPos = tPos;
		}

		void			Text::Draw(sf::RenderWindow *tWindow)
		{
			mText.setPosition(*mPos + mRelPos);
			tWindow->draw(mText);
		}

	} // namespace component 
} // namespace mf
