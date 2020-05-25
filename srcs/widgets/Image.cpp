#include "Image.hpp"

namespace mf
{

Image::Image()
:mBackground(&mPos, &mSize)
{

}

Image::~Image()
{

}

void		Image::Render(sf::RenderWindow *tWindow)
{
	if (mBackground.GetBackground())
    {
        tWindow->draw(*mBackground.GetBackground());    
    }
	Widget::Render(tWindow);
}

Image      *Image::Create(std::string tPath)
{
    Image   *img = new Image();
    img->mBackground.SetBackground(tPath);
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
