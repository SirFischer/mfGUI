#pragma once

#include <SFML/Graphics.hpp>

namespace mf
{
    class Background
    {
    protected:
        sf::Drawable    *mBackGround;

    public:
        Background(/* args */);
        ~Background();

        virtual void            SetBackground(sf::Drawable *tBackground) = 0;
        virtual sf::Drawable    *GetBackground() = 0;
    };
    
    Background::Background(/* args */)
    {
    }
    
    Background::~Background()
    {
    }
    
} // namespace mf
