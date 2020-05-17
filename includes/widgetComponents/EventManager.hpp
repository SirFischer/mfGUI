#pragma once
#include <functional>
#include <SFML/Graphics.hpp>
#include "utils/Events.hpp"
#include <iostream>

namespace mf
{
    class EventManager
    {
    private:
        eEvent              mEvent = eEvent::OUTSIDE;
        eEvent              mPreviousEvent = eEvent::OUTSIDE;

        sf::Vector2f        *mPos;
        sf::Vector2f        *mSize;

        std::map<uint32_t, std::function<void()>>   mKeyListeners;
        std::function<void()> mOnLeftClickListener;
        std::function<void()> mOnRightClickListener;
        std::function<void()> mOnEnterListener;
        std::function<void()> mOnHoverListener;
        std::function<void()> mOnExitListener;

        void            Update(sf::Event &tEvent);

        EventManager(sf::Vector2f *tPos, sf::Vector2f *tSize);
        ~EventManager();

    public:
        friend class Widget;

       	void    AddEventListener(eEvent tEvent ,std::function<void()> tListener);
        void    TriggerEvent(eEvent tEvent);

    };
    
} // namespace mf
