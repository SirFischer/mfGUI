#include "widgets/Text.hpp"

namespace mf
{

Text::Text()
:mBackground(&mPosition, &mSize)
,mScrollBar(&mPosition, &mSize, &mContentSize, &mContentPosition)
,mText(&mPosition, &mSize)
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

void		Text::Update()
{
	if (mIsEditable) FlashingCursor();
}

void		Text::Render(sf::RenderWindow *tWindow)
{
	mView.setViewport(sf::FloatRect(mPosition.x / (float)tWindow->getSize().x,
									mPosition.y / (float)tWindow->getSize().y,
									mSize.x / (float)tWindow->getSize().x,
									mSize.y / (float)tWindow->getSize().y));
	mView.reset(sf::FloatRect(sf::Vector2f(mPosition.x, mPosition.y + mContentPosition.y), mSize));
	
	mBackground.Draw(tWindow);
	sf::View		tmp = tWindow->getView();
	tWindow->setView(mView);

	if (mFlashingCursor && mEventManager.GetFocus())
	{
		mText.SetString(mText.GetString() + "|");
	}

	mText.Draw(tWindow);

	if (mFlashingCursor && mEventManager.GetFocus())
	{
		mText.SetString(mText.GetString().substr(0, mText.GetString().length() - 1));
	}

	tWindow->setView(tmp);
	mScrollBar.Draw(tWindow);
	Widget::Render(tWindow);
}


std::shared_ptr<Text>      Text::Create()
{
	std::shared_ptr<Text> txt(new Text());
    txt->SetSize(sf::Vector2f(200, 100));
    return (txt);
}

void			Text::EnableEdit()
{
	mIsEditable = true;
	Text* tmp = this;
	mEventManager.AddEventListener(eEvent::FOCUS, [tmp] {
		tmp->mBackground.SetOutlineThickness(2);
	});
	mEventManager.AddEventListener(eEvent::LOST_FOCUS, [tmp] {
		tmp->mBackground.SetOutlineThickness(1);
	});
}

void			Text::DisableEdit()
{
	mIsEditable = false;
}


void			Text::FlashingCursor()
{
	if (mEventManager.GetFocus())
	{
		if (mFlashingCursorClock.getElapsedTime().asMilliseconds() > 500)
		{
			mFlashingCursor = !mFlashingCursor;
			mFlashingCursorClock.restart();
		}
	}
}

} // namespace mf
