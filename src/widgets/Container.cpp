#include "Container.hpp"

namespace mf
{

Container::Container()
:mBackground(&mPosition, &mSize)
{

}

Container::~Container()
{

}

void		Container::Render(sf::RenderWindow *tWindow)
{
	mBackground.Draw(tWindow);
	Widget::Render(tWindow);
}

Container     *Container::Create()
{
    Container   *container = new Container();
   container->SetSize(300, 200);
    return (container);
}

} // namespace mf
