#include "Widget.hpp"

namespace mf
{

Widget::Widget()
:mEventManager(&mTransform.mPosition, &mTransform.mSize)
{
	//Default resize function
	mEventManager.AddEventListener(eEvent::RESIZE, [this] {
		this->SetPosition(mTransform.mRelativePosition);
		this->SetSize(mTransform.mRelativeSize);
	});
}

Widget::~Widget()
{

}

Widget      *Widget::Create()
{
	mf::Widget	*widget = new Widget();
    return (widget);
}

void        Widget::HandleEvent(sf::Event &tEvent)
{
	mEventManager.Update(tEvent);
	bool	isClickThrough = true;
	for (auto &i : boost::adaptors::reverse(mWidgets))
	{
		eEvent event = i->GetEvent();
		if (!i->mDisabled && isClickThrough)
			i->HandleEvent(tEvent);
		else
			i->Resize();
		if (!i->mDisabled && ((!i->IsClickThrough() && (event != eEvent::OUTSIDE && event != eEvent::EXITED))))
			isClickThrough = false;
	}
}

void		Widget::UpdatePosition()
{
	SetPosition(mTransform.mRelativePosition);
	for (auto &child : mWidgets)
	{
		child->UpdatePosition();
	}
}

void		Widget::UpdateSize()
{
	SetSize(mTransform.mRelativeSize);
	for (auto &child : mWidgets)
	{
		child->UpdateSize();
	}
}


void		Widget::Resize()
{
	mEventManager.TriggerEvent(mf::eEvent::RESIZE);
	for (auto &i : mWidgets)
		i->Resize();
}


void		Widget::Render(sf::RenderWindow *tWindow)
{
    for (auto &i : mWidgets)
		if (!i->mDisabled)
			i->Render(tWindow);
}

void		Widget::Init()
{
	this->SetPosition(mTransform.mRelativePosition);
	this->SetSize(mTransform.mRelativeSize);
}

void		Widget::SortWidgets()
{
	std::sort(mWidgets.begin(), mWidgets.end(), [](mf::Widget *first, mf::Widget *second){
		return (first->GetIndex() < second->GetIndex());
	});
}



Widget			*Widget::AddWidget(Widget *tWidget)
{
    tWidget->mParent = this;
    tWidget->SetPosition(tWidget->mTransform.mRelativePosition);
    mWidgets.push_back(tWidget);
	tWidget->Init();
	SortWidgets();
    return (this);
}

void			Widget::RemoveWidget(Widget *tWidget)
{
	std::vector<mf::Widget *>::iterator it;
    if ((it = std::find(mWidgets.begin(), mWidgets.end(), tWidget)) != mWidgets.end())
	{
		(*it)->ClearWidgets();
		mWidgets.erase(it);
	}
}

void        Widget::ClearWidgets()
{
    while (mWidgets.size())
    {
        mWidgets.back()->ClearWidgets();
        delete mWidgets.back();
        mWidgets.pop_back();
    }
}

void		Widget::ClearWidgets(bool tDelete)
{
	while (mWidgets.size())
	{
		mWidgets.back()->ClearWidgets(tDelete);
		if (tDelete)
			delete mWidgets.back();
		mWidgets.pop_back();
	}
}

Widget			*Widget::SetPosition(sf::Vector2f tPos)
{
	//TODO: MAKE POSITION PERCENTAGE FOR X AND Y
	mTransform.mPosition = tPos;
	mTransform.mRelativePosition = tPos;
	if (mTransform.mPositionPercentageX && mParent)
		mTransform.mPosition.x =mParent->mTransform.mSize.x * (tPos.x / 100.f);
	if (mTransform.mPositionPercentageY && mParent)
		mTransform.mPosition.y = mParent->mTransform.mSize.y * (tPos.y / 100.f);
	if (mParent)
	{
		mTransform.mPosition += mParent->mTransform.mPosition;
	}
    return (this);
}

Widget			*Widget::SetPosition(float tX, float tY)
{
    this->SetPosition(sf::Vector2f(tX, tY));
    return (this);
}

Widget			*Widget::SetPositionPercentage(bool tPercentageX, bool tPercentageY)
{
	mTransform.mPositionPercentageX = tPercentageX;
	mTransform.mPositionPercentageY = tPercentageY;
	this->SetPosition(mTransform.mPosition);
	return (this);
}


Widget			*Widget::SetSize(float tX, float tY)
{
    this->SetSize(sf::Vector2f(tX, tY));
    return (this);
}

Widget			*Widget::SetSize(sf::Vector2f tSize)
{
	//TODO: MAKE SZIE PERCENTAGE FOR X AND Y
	mTransform.mSize = tSize;
	mTransform.mRelativeSize = tSize;
	if (mTransform.mSizePercentageX && mParent)
		mTransform.mSize.x = mParent->mTransform.mSize.x * (tSize.x / 100.f);
	if (mTransform.mSizePercentageY && mParent)
		mTransform.mSize.y = mParent->mTransform.mSize.y * (tSize.y / 100.f);
    return (this);
}

Widget			*Widget::SetSizePercentage(bool tPercentageX, bool tPercentageY)
{
	mTransform.mSizePercentageX = tPercentageX;
	mTransform.mSizePercentageY = tPercentageY;
	this->SetSize(mTransform.mRelativeSize);
	return (this);
}
    
} // namespace mf
