#include "Widget.hpp"

namespace mf
{

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

void		Widget::Render(sf::Window *tWindow)
{
    //render current widget
    for (auto &i : mWidgets)
        i->Render(tWindow);
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
    
} // namespace mf
