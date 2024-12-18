#pragma once

#include "Widget.hpp"
#include "../widgetComponents/Background.hpp"

namespace mf
{
	class Checkbox : public Widget
	{
	private:
		Checkbox(/* args */);

		/**
		 * Components
		 **/
		component::Background  	mBackground;

		bool					mChecked;

		void					DrawCheckMark(sf::RenderWindow *tWindow);


	public:
		~Checkbox();
		void					Render(sf::RenderWindow *tWindow) override;

		/**
		 * Create
		 **/
		static std::shared_ptr<Checkbox>     Create();

		/**
		 * Setters
		 **/
		void					SetChecked(bool tChecked);

		//Background
		void					SetBackground(component::Background tBackground){mBackground = tBackground;}
		component::Background	*GetBackground(){return (&mBackground);}

	};
}