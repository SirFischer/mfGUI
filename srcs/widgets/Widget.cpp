#include "Widget.hpp"

namespace mf
{

Widget::Widget()
{

}

Widget::~Widget()
{

}

Widget      *Widget::Create()
{
    return (new Widget());
}

void        Widget::HandleEvent(sf::Event &tEvent)
{
    //handle event for current widget
    for (auto &i : mWidgets)
        i->HandleEvent(tEvent);
}

void		Widget::Render(sf::RenderWindow *tWindow)
{
    for (auto &i : mWidgets)
        i->Render(tWindow);
}

Widget			*Widget::AddWidget(Widget *tWidget)
{
    tWidget->mParent = this;
    tWidget->SetPosition(tWidget->mRelativePos);
    mWidgets.push_back(tWidget);
    return (this);
}

void			Widget::RemoveWidget(Widget *tWidget)
{
    (void)tWidget;
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

Widget			*Widget::SetPositionType(ePosition tPosType)
{
    mPositionType = tPosType;
    mPos = (mPositionType == ePosition::RELATIVE && mParent) ? mRelativePos + mParent->mPos : mRelativePos;
    return (this);
}

Widget			*Widget::SetPosition(sf::Vector2f tPos)
{
    mPos = (mPositionType == ePosition::RELATIVE && mParent) ? tPos + mParent->mPos : tPos;
    mRelativePos = tPos;
    return (this);
}

Widget			*Widget::SetSize(sf::Vector2f tSize)
{
    mSize = tSize;
    return (this);
}
    
} // namespace mf
