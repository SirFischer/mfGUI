#include "Text.hpp"

namespace mf
{

Text::Text()
:mBackground(&mPos, &mSize)
,mText(&mPos, &mSize)
{

}

Text::~Text()
{

}

void		Text::Render(sf::RenderWindow *tWindow)
{
	mBackground.Draw(tWindow);
	mText.Draw(tWindow);
	Widget::Render(tWindow);
}

Text      *Text::Create(std::string tFontPath, std::string tString)
{
    Text *txt = new Text();
    txt->mBackground.SetBackground(sf::Color::White);
    txt->SetSize(sf::Vector2f(200, 100));
	txt->SetTextFont(tFontPath);
	txt->SetText(tString);
    return (txt);
}

Text		*Text::SetText(std::string tText)
{
	mText.SetString(tText);
	return (this);
}

Text		*Text::SetTextFont(std::string tPath)
{
	mText.LoadFont(tPath);
	return (this);
}

Text		*Text::SetTextFont(sf::Font tFont)
{
	mText.LoadFont(tFont);
	return (this);
}

Text		*Text::SetTextPosition(sf::Vector2f tPos)
{
	mText.SetPos(tPos);
	return (this);
}

Text		*Text::SetTextColor(sf::Color tColor)
{
	mText.SetColor(tColor);
	return (this);
}

Text		*Text::SetOutlineThickness(float tThickness)
{
	mBackground.SetOutlineThickness(tThickness);
	return (this);
}

Text		*Text::SetOutlineColor(sf::Color tColor)
{
	mBackground.SetOutlineColor(tColor);
	return (this);
}


} // namespace mf
