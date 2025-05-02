#pragma once
#include <functional>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdint>

#include "../utils/Events.hpp"

namespace mf
{
	namespace component
	{
		class EventManager
		{
		private:
			eEvent              mEvent = eEvent::OUTSIDE;
			bool				mFocus = false;
			eEvent              mPreviousEvent = eEvent::OUTSIDE;

			sf::Vector2f        *mPos;
			sf::Vector2f        *mSize;
			sf::Vector2f		mMousePos;

			char				mCharInput = 0;

			std::map<uint32_t, std::vector<std::function<void()>>>   mKeyListeners;

			void			RunEventListeners(eEvent tEvent);

		public:
			EventManager(sf::Vector2f *tPos, sf::Vector2f *tSize);
			~EventManager();

			void			Update(sf::Event &tEvent);
			void			AddEventListener(eEvent tEvent, std::function<void()> tListener);
			void			RemoveEventListener(eEvent tEvent, std::function<void()> tListener);
			void			RemoveAllEventListener(eEvent tEvent);
			void			TriggerEvent(eEvent tEvent);

			eEvent			GetEvent(){return (mEvent);}

			/**
			 * Returns if the widget has focus
			 * @return true if the widget has focus,
			 * @return false if the widget has no focus
			 */
			bool			GetFocus() {return (mFocus);}

			char			GetCharInput() {return (mCharInput);}
			sf::Vector2f	GetMousePosition(){return (mMousePos);}

			void			SetFocus(bool tFocus);
		};
	} // namespace component
	
    
    
} // namespace mf
