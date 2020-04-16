#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

namespace mf
{
    class Background
    {
    protected:
        std::unique_ptr<sf::RectangleShape>   mBackground;
        sf::Texture                     mTexture;

        sf::Vector2f                    *mSize;
        sf::Vector2f                    *mPos;

    public:
        Background(sf::Vector2f *tSize, sf::Vector2f *tPos);
        ~Background();

        void            SetBackground(sf::RectangleShape *tBackground);
        void            SetBackground(sf::Color tColor);
        void            SetBackground(std::string tPath);
        sf::Drawable    *GetBackground();

        void            Draw();
    };
    
} // namespace mf
