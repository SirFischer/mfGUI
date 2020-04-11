#pragma once

#include <SFML/Graphics.hpp>

namespace mf
{
	class widget
	{
	private:
		widget(/* args */);
		~widget();

		sf::Vector2f	mPos;
		sf::Vector2f	mSize;

		int				mIndex;
	public:
		
	};
	
} // namespace mf
