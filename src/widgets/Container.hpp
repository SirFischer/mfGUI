#pragma once

#include "Widget.hpp"

namespace mf
{
	class Container : public Widget
	{
	private:
		Container(/* args */);
		

		/**
		 * Components
		 **/
		component::Background mBackground;

	public:
		~Container();
		void				Render(sf::RenderWindow	*tWindow);

		/**
		 * Create
		 **/
		static std::shared_ptr<Container>	Create();

		/**
		 * Background
		 **/
		void					SetBackground(component::Background tBackground){mBackground = tBackground;}
		component::Background	*GetBackground(){return (&mBackground);}

	};
} // namespace mf
