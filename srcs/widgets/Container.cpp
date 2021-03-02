#include "Container.hpp"

namespace mf
{

Container::Container()
:mBackground(&mPos, &mSize)
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

Container      *Container::Create()
{
    Container   *container = new Container();
   container->SetSize(300, 200);
    return (container);
}

Container	*Container::SetOutlineThickness(float tThickness)
{
	mBackground.SetOutlineThickness(tThickness);
	return (this);
}

Container	*Container::SetOutlineColor(sf::Color tColor)
{
	mBackground.SetOutlineColor(tColor);
	return (this);
}

} // namespace mf
