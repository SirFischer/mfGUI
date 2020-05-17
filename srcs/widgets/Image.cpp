#include "Image.hpp"

namespace mf
{

Image::Image()
{

}

Image::~Image()
{

}

Image      *Image::Create(std::string tPath)
{
    Image   *img = new Image();
    img->mBackground.SetBackground(tPath);
    return (img);
}

} // namespace mf
