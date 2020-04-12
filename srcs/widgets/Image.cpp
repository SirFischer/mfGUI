#include "Image.hpp"

namespace mf
{
Widget      *Image::Create(std::string tPath)
{
    return (new Image());
}

} // namespace mf
