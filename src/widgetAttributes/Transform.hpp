#pragma once
#include <SFML/Graphics.hpp>

namespace mf
{
	namespace attribute
	{
		struct Transformable
		{
		protected:
			sf::Vector2f mPosition = sf::Vector2f(0, 0);
			sf::Vector2f mRelativePosition;
			sf::Vector2f mSize = sf::Vector2f(100, 100);
			sf::Vector2f mRelativeSize;

			bool mSizePercentageX = false;
			bool mSizePercentageY = false;
			bool mPositionPercentageX = false;
			bool mPositionPercentageY = false;

			Transformable *mParent = nullptr;

			Transformable() = default;

			void	SetParent(Transformable *tParent)
			{
				mParent = tParent;
			}

		public:
			virtual void SetPosition(sf::Vector2f tPos)
			{
				// TODO: MAKE POSITION PERCENTAGE FOR X AND Y
				mPosition = tPos;
				mRelativePosition = tPos;
				if (mPositionPercentageX && mParent)
					mPosition.x = mParent->mSize.x * (tPos.x / 100.f);
				if (mPositionPercentageY && mParent)
					mPosition.y = mParent->mSize.y * (tPos.y / 100.f);
				if (mParent)
				{
					mPosition += mParent->mPosition;
				}
				
			}

			virtual void SetPosition(float tX, float tY)
			{
				return this->SetPosition(sf::Vector2f(tX, tY));
			}

			virtual void SetPositionPercentage(bool tPercentageX, bool tPercentageY)
			{
				mPositionPercentageX = tPercentageX;
				mPositionPercentageY = tPercentageY;
				this->SetPosition(mPosition);
				
			}

			virtual void SetSize(float tX, float tY)
			{
				return this->SetSize(sf::Vector2f(tX, tY));
			}

			virtual void SetSize(sf::Vector2f tSize)
			{
				// TODO: MAKE SZIE PERCENTAGE FOR X AND Y
				mSize = tSize;
				mRelativeSize = tSize;
				if (mSizePercentageX && mParent)
					mSize.x = mParent->mSize.x * (tSize.x / 100.f);
				if (mSizePercentageY && mParent)
					mSize.y = mParent->mSize.y * (tSize.y / 100.f);
				
			}

			virtual void SetSizePercentage(bool tPercentageX, bool tPercentageY)
			{
				mSizePercentageX = tPercentageX;
				mSizePercentageY = tPercentageY;
				return this->SetSize(mRelativeSize);
			}

			sf::Vector2f	GetPosition(){return (mPosition);}
			sf::Vector2f	GetRelativePosition(){return (mRelativePosition);}
			sf::Vector2f	GetSize(){return (mSize);}
			sf::Vector2f	GetRelativeSize(){return (mRelativeSize);}
		
		};
	} // namespace component
} // namespace mf