#pragma once

#include <SFML/Graphics.hpp>


namespace mf
{
	namespace component
	{
		struct Transform
		{
			sf::Vector2f		mPosition = sf::Vector2f(0, 0);
			sf::Vector2f		mRelativePosition;
			sf::Vector2f		mSize = sf::Vector2f(100, 100);
			sf::Vector2f		mRelativeSize;

			//Draw Order Index
			int					mIndex = 0;

			bool				mSizePercentageX = false;
			bool				mSizePercentageY = false;
			bool				mPositionPercentageX = false;
			bool				mPositionPercentageY = false;
		};
	} // namespace component
} // namespace mf