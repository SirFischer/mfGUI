#pragma once

#include "Widget.hpp"

namespace mf
{
    class Image : public Widget
    {
    private:
        Image(/* args */);
        ~Image();

    public:

    static Widget      *Create(std::string tPath);
    void			    Render(sf::RenderWindow *tWindow);
        
    };
} // namespace mf
