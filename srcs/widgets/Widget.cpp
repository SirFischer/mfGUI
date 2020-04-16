#include "Widget.hpp"

namespace mf
{

Widget::Widget()
:mBackground(&mSize, &mPos)
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
    //render current widget
    for (auto &i : mWidgets)
        i->Render(tWindow);
}

void			Widget::AddWidget(Widget *tWidget)
{
    mWidgets.push_back(tWidget);
}

void			Widget::RemoveWidget(Widget *tWidget)
{
    (void)tWidget;
}

void        Widget::ClearWidgets()
{
    while (mWidgets.back())
    {
        mWidgets.back()->ClearWidgets();
        delete mWidgets.back();
        mWidgets.pop_back();
    }
}

Widget			*Widget::SetPositionType(ePosition tPosType)
{
    mPositionType = tPosType;
    return (this);
}

Widget			*Widget::SetPosition(sf::Vector2f tPos)
{
    mPos = tPos;
    return (this);
}

Widget			*Widget::SetSize(sf::Vector2f tSize)
{
    mSize = tSize;
    return (this);
}
    
} // namespace mf
