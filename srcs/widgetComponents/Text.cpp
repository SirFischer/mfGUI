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

		void			Text::SetSize(unsigned int tSize)
		{
			mText.setCharacterSize(tSize);
		}

		void			Text::SetPos(sf::Vector2f tPos)
		{
			mRelPos = tPos;
		}

		void			Text::SetColor(sf::Color tColor)
		{
			mText.setFillColor(tColor);
		}

		void			Text::Draw(sf::RenderWindow *tWindow)
		{
			mText.setPosition(*mPos + mRelPos);
			tWindow->draw(mText);
		}

		void			Text::FormatText()
		{
			std::string		res = mString;
			unsigned int	start = 0;
			unsigned int	maxCharPerLine = (mSize->x / (mText.getCharacterSize())) * 2.5;

			while (start < res.size())
			{
				std::size_t stopPos = res.find_first_of('\n', start) - start;
				if (stopPos == std::string::npos)
					stopPos = 0;
				if (stopPos && stopPos < maxCharPerLine)
				{
					start += stopPos + 1;
					continue;
				}
				if (start + maxCharPerLine < res.size())
					res.insert(start + maxCharPerLine, "-\n");
				start += maxCharPerLine + 2;
			}
			mText.setString(res);
		}
		
		void			Text::SetString(std::string tString)
		{
			mString = tString;
			FormatText();
		}

		void			Text::AddString(std::string tString)
		{
			(void)tString;
		}

		void			Text::DeleteString(int tNum)
		{
			(void)tNum;
		}

		void			Text::ResetString()
		{
			mString = "";
			mText.setString("");
		}

	} // namespace component 
} // namespace mf
