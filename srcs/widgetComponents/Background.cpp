#include "Background.hpp"

namespace mf
{
	namespace component
	{
		Background::Background(sf::Vector2f *tPos,sf::Vector2f *tSize)
		:mPos(tPos)
		,mSize(tSize)
		{

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

		void			Background::SetBackground(sf::Texture tTexture)
		{
			mTexture = tTexture;
			SetBackground(sf::Color::White);
			sf::RectangleShape      *rectangle = (sf::RectangleShape *)mBackground.get();
			rectangle->setTexture(&mTexture);
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
			if (!mBackground)
				return (NULL);
			if (mBackground->getPosition() != *mPos)
				mBackground->setPosition(*mPos);
			if (mBackground->getSize() != *mSize)
				mBackground->setSize(*mSize);
			return (mBackground.get());
		}

		void            Background::Draw(sf::RenderWindow *tWindow)
		{
			if (this->GetBackground())
			{
				tWindow->draw(*mBackground.get());
			}
		}
	} // namespace component 
} // namespace mf
