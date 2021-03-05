#include "widgets/Text.hpp"

namespace mf
{

Text::Text()
:mBackground(&mPos, &mSize)
,mEventManager(&mPos, &mSize)
,mScrollBar(&mPos, &mSize, &mContentSize, &mContentPosition)
,mText(&mPos, &mSize)
{

}

Text::~Text()
{

}

void		Text::HandleEvent(sf::Event &tEvent)
{
	if (mIsEditable)
	{
		mEventManager.Update(tEvent);
		if (mEventManager.GetFocus())
		{
			char tmp = mEventManager.GetCharInput();
			if (tmp == 8)
				mText.DeleteString(1);
			if ((int)mText.GetString().length() < mMaxTextLength || mMaxTextLength == -1)
			{
				if (isblank(tmp) || (tmp >= 33 && tmp <= 126))
					mText.AddString(std::string("") + tmp);
				if (tmp == 13)
					mText.AddString("\n");
			}
		}
	}
	mContentSize = sf::Vector2f(mSize.x, mText.GetVerticalHeight());
	mScrollBar.HandleEvent(tEvent);
	Widget::HandleEvent(tEvent);
}

void		Text::Render(sf::RenderWindow *tWindow)
{
	mView.setViewport(sf::FloatRect(mPos.x / (float)tWindow->getSize().x,
									mPos.y / (float)tWindow->getSize().y,
									mSize.x / (float)tWindow->getSize().x,
									mSize.y / (float)tWindow->getSize().y));
	mView.reset(sf::FloatRect(sf::Vector2f(mPos.x, mPos.y + mContentPosition.y), mSize));
	
	mBackground.Draw(tWindow);
	sf::View		tmp = tWindow->getView();
	tWindow->setView(mView);
	mText.Draw(tWindow);
	tWindow->setView(tmp);
	mScrollBar.Draw(tWindow);
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

Text			*Text::EnableEdit()
{
	mIsEditable = true;
	Text* tmp = this;
	mEventManager.AddEventListener(eEvent::FOCUS, [tmp] {
		tmp->SetOutlineThickness(5);
	});
	mEventManager.AddEventListener(eEvent::LOST_FOCUS, [tmp] {
		tmp->SetOutlineThickness(1);
	});
	return (this);
}

Text			*Text::DisableEdit()
{
	mIsEditable = false;
	return (this);
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

Text		*Text::SetCharacterSize(unsigned int tSize)
{
	mText.SetSize(tSize);
	return (this);
}


} // namespace mf
