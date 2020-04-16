#include "Background.hpp"

namespace mf
{
    Background::Background(sf::Vector2f *tSize, sf::Vector2f *tPos)
    {
        mSize = tSize;
        mPos = tPos;
    }
    
    Background::~Background()
    {
    }

    void            Background::SetBackground(sf::RectangleShape *tBackground)
    {
        mBackground.reset(tBackground);
    }

    void            Background::SetBackground(sf::Color tColor)
    {
        sf::RectangleShape      *rectangle = new sf::RectangleShape(*mSize);
        rectangle->setFillColor(tColor);
        rectangle->setPosition(*mPos);
        SetBackground(rectangle);
    }

    void            Background::SetBackground(std::string tPath)
    {
        mTexture.loadFromFile(tPath);
        SetBackground(sf::Color::White);
        sf::RectangleShape      *rectangle = (sf::RectangleShape *)mBackground.get();
        rectangle->setTexture(&mTexture);
    }

    sf::Drawable    *Background::GetBackground()
    {
        if (mBackground->getPosition() != *mPos)
            mBackground->setPosition(*mPos);
        if (mBackground->getSize() != *mSize)
            mBackground->setSize(*mSize);
        return (mBackground.get());
    }
} // namespace mf
