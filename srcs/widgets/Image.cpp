#include "Image.hpp"

namespace mf
{

Image::Image()
{

}

Image::~Image()
{

}

Widget      *Image::Create(std::string tPath)
{
    Image   *img = new Image();
    img->mBackground.SetBackground(tPath);
    return (img);
}

void	    Image::Render(sf::RenderWindow *tWindow)
{
    sf::RenderWindow    *win = (sf::RenderWindow *)tWindow;
    win->draw(*mBackground.GetBackground());
}

} // namespace mf
