#include "Select.hpp"

namespace mf
{

Select::Select()
:mBackground(&mPos, &mSize)
,mText(&mPos, &mSize)
{
	mList = List::Create();
	mList->SetPosition(mPos + sf::Vector2f(0, mSize.y));

}

Select::~Select()
{

}

void		Select::HandleEvent(sf::Event &tEvent)
{
	mEventManager.Update(tEvent);
	Widget::HandleEvent(tEvent);
}

void		Select::Render(sf::RenderWindow *tWindow)
{
	mList->SetPosition(mPos + sf::Vector2f(0, mSize.y));
	mBackground.Draw(tWindow);
	mText.Draw(tWindow);
	Widget::Render(tWindow);
}


Select      *Select::Create(std::string tFont)
{
    Select *slct = new Select();

    slct->SetSize(sf::Vector2f(150, 50));
	slct->SetOutlineColor(sf::Color::Black);
	slct->SetOutlineThickness(1.f);
	slct->SetTextFont(tFont);

	slct->mEventManager.AddEventListener(eEvent::FOCUS, [slct] {
		slct->SetOutlineThickness(3.f);
		slct->RemoveWidget(slct->mList);
		slct->AddWidget(slct->mList);
	});

	slct->mEventManager.AddEventListener(eEvent::LOST_FOCUS, [slct] {
		slct->SetOutlineThickness(1.f);
		slct->RemoveWidget(slct->mList);
	});
    return (slct);
}

Select		*Select::SetClickEvent(std::function<void()> tListener)
{
	mEventManager.AddEventListener(eEvent::LEFT_CLICK, tListener);
	return (this);
}

Select		*Select::SetText(std::string tText)
{
	mText.SetString(tText);
	return (this);
}

Select		*Select::SetTextFont(std::string tPath)
{
	mText.LoadFont(tPath);
	return (this);
}

Select		*Select::SetTextFont(sf::Font tFont)
{
	mText.LoadFont(tFont);
	return (this);
}

Select		*Select::SetTextPosition(sf::Vector2f tPos)
{
	mText.SetPos(tPos);
	return (this);
}

Select		*Select::SetTextColor(sf::Color tColor)
{
	mText.SetColor(tColor);
	return (this);
}

Select		*Select::SetOutlineThickness(float tThickness)
{
	mBackground.SetOutlineThickness(tThickness);
	return (this);
}

Select		*Select::SetOutlineColor(sf::Color tColor)
{
	mBackground.SetOutlineColor(tColor);
	return (this);
}


} // namespace mf
