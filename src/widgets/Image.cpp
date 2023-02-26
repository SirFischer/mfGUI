#include "Image.hpp"

namespace mf
{

Image::Image()
:mBackground(&mTransform.mPosition, &mTransform.mSize)
{

}

Image::~Image()
{

}

void		Image::Render(sf::RenderWindow *tWindow)
{
	mBackground.Draw(tWindow);
	Widget::Render(tWindow);
}

Image      *Image::Create()
{
    Image   *img = new Image();
    return (img);
}

Image	*Image::SetImage(std::string tPath)
{
	this->mBackground.SetBackground(tPath);
	return (this);
}

Image	*Image::SetImage(sf::Texture	&tTexture)
{
	this->mBackground.SetBackground(tTexture);
	return (this);
}

Image	*Image::SetOutlineThickness(float tThickness)
{
	mBackground.SetOutlineThickness(tThickness);
	return (this);
}

Image	*Image::SetOutlineColor(sf::Color tColor)
{
	mBackground.SetOutlineColor(tColor);
	return (this);
}

} // namespace mf
