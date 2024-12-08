#include "Image.hpp"

namespace mf
{

Image::Image()
:mBackground(&mPosition, &mSize)
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

std::shared_ptr<Image>      Image::Create()
{
	std::shared_ptr<Image> img(new Image());
    return (img);
}

void	Image::SetImage(std::string tPath)
{
	this->mBackground.SetBackground(tPath);
}

void	Image::SetImage(sf::Texture	&tTexture)
{
	this->mBackground.SetBackground(tTexture);
}

} // namespace mf
