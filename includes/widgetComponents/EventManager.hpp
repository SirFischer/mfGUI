#pragma once
#include <functional>
#include <SFML/Graphics.hpp>
#include "utils/Events.hpp"
#include <iostream>

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

			std::map<uint32_t, std::function<void()>>   mKeyListeners;			

		public:
			EventManager(sf::Vector2f *tPos, sf::Vector2f *tSize);
			~EventManager();

			void			Update(sf::Event &tEvent);
			void			AddEventListener(eEvent tEvent ,std::function<void()> tListener);
			void			TriggerEvent(eEvent tEvent);

			eEvent			GetEvent(){return (mEvent);}

			bool			GetFocus() {return (mFocus);}
			char			GetCharInput() {return (mCharInput);}
			sf::Vector2f	GetMousePosition(){return (mMousePos);}
		};
	} // namespace component
	
    
    
} // namespace mf
