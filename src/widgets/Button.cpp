#include "Button.hpp"

namespace mf
{

Button::Button()
: mBackground(&mPosition, &mSize)
, mText(&mPosition, &mSize)
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
	btn->GetText()->SetString("Button");

    return (btn);
}

void		Button::SetClickEvent(std::function<void()> tListener)
{
	mEventManager.AddEventListener(eEvent::LEFT_CLICK, tListener);
}

void		Button::AddEventListener(eEvent tEvent, std::function<void()> tListener)
{
	mEventManager.AddEventListener(tEvent, tListener);
}

} // namespace mf
