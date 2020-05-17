#pragma once

#include "Widget.hpp"

namespace mf
{
    class Button : public Widget
    {
    private:
        Button(/* args */);
        ~Button();

    public:

    static Button      *Create(std::string tPathIdle, std::string tPathHover);
    static Button      *Create(sf::Color tIdle, sf::Color tHover);
        
    };
} // namespace mf
