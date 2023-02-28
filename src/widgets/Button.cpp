#include "Button.hpp"

namespace mf
{

Button::Button()
:mBackground(&mTransform.mPosition, &mTransform.mSize)
,mText(&mTransform.mPosition, &mTransform.mSize)
{

}

Button::~Button()
{

}

void		Button::Render(sf::RenderWindow *tWindow)
{
	mBackground.Draw(tWindow);
	mText.Draw(tWindow);
	Widget::Render(tWindow);
}

Button      *Button::Create()
{
    Button *btn = new Button();
    btn->SetSize(sf::Vector2f(100, 50));
    return (btn);
}

Button		*Button::SetClickEvent(std::function<void()> tListener)
{
	mEventManager.AddEventListener(eEvent::LEFT_CLICK, tListener);
	return (this);
}

Button		*Button::AddEventListener(eEvent tEvent, std::function<void()> tListener)
{
	mEventManager.AddEventListener(tEvent, tListener);
	return (this);
}

Button		*Button::SetText(std::string tText)
{
	mText.SetString(tText);
	return (this);
}

Button		*Button::SetTextFont(std::string tPath)
{
	mText.LoadFont(tPath);
	return (this);
}

Button		*Button::SetTextFont(sf::Font tFont)
{
	mText.LoadFont(tFont);
	return (this);
}

Button		*Button::SetTextPosition(sf::Vector2f tPos)
{
	mText.SetPos(tPos);
	return (this);
}

Button		*Button::SetTextPosition(float tX, float tY)
{
	mText.SetPos(sf::Vector2f(tX, tY));
	return (this);
}


Button		*Button::SetTextColor(sf::Color tColor)
{
	mText.SetColor(tColor);
	return (this);
}

Button		*Button::SetCharacterSize(unsigned int tSize)
{
	mText.SetSize(tSize);
	return (this);
}



Button		*Button::SetOutlineThickness(float tThickness)
{
	mBackground.SetOutlineThickness(tThickness);
	return (this);
}

Button		*Button::SetOutlineColor(sf::Color tColor)
{
	mBackground.SetOutlineColor(tColor);
	return (this);
}

Button		*Button::SetBackground(const sf::Color &tColor)
{
	mBackground.SetBackground(tColor);
	return (this);
}

Button		*Button::SetBackground(const sf::Texture &tTexture)
{
	mBackground.SetBackground(tTexture);
	return (this);
}




} // namespace mf
