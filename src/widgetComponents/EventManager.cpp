#include "EventManager.hpp"

namespace mf
{
	namespace component
	{
		EventManager::EventManager(sf::Vector2f *tPos, sf::Vector2f *tSize)
		: mPos(tPos), mSize(tSize)
		{
		}

		EventManager::~EventManager()
		{
		}

		void EventManager::RunEventListeners(eEvent tEvent)
		{
			if (mKeyListeners.find((uint32_t)tEvent) != mKeyListeners.end())
			{
				for (auto &listener : mKeyListeners[(uint32_t)tEvent])
				{
					listener();
				}
			}
		}


		void EventManager::Update(sf::Event &tEvent)
		{
			sf::Vector2i pos = sf::Vector2i(tEvent.mouseMove.x, tEvent.mouseMove.y);
			bool inside = (pos.x > mPos->x && pos.y > mPos->y && pos.x < mPos->x + mSize->x && pos.y < mPos->y + mSize->y);
			switch (tEvent.type)
			{
			case sf::Event::MouseMoved:
				if (inside && mEvent == eEvent::OUTSIDE)
					mEvent = eEvent::ENTERED;
				else if (inside || mEvent == eEvent::ENTERED)
					mEvent = eEvent::INSIDE;
				else if (!inside && mEvent == eEvent::INSIDE)
					mEvent = eEvent::EXITED;
				else if (!inside || mEvent == eEvent::EXITED)
					mEvent = eEvent::OUTSIDE;
				mMousePos = sf::Vector2f(tEvent.mouseMove.x, tEvent.mouseMove.y);
				break;

			case sf::Event::MouseButtonPressed:
				if (mEvent != eEvent::OUTSIDE && mEvent != eEvent::EXITED)
				{
					if (tEvent.mouseButton.button == sf::Mouse::Left)
						mEvent = eEvent::LEFT_CLICK;
					if (tEvent.mouseButton.button == sf::Mouse::Right)
						mEvent = eEvent::RIGHT_CLICK;
					mFocus = true;
					RunEventListeners(eEvent::FOCUS);
				}
				else
				{
					mFocus = false;
					RunEventListeners(eEvent::LOST_FOCUS);
				}
					
			break;

			case sf::Event::MouseButtonReleased:
				if (mEvent != eEvent::OUTSIDE && mEvent != eEvent::EXITED)
				{
					if (tEvent.mouseButton.button == sf::Mouse::Left)
						mEvent = eEvent::LEFT_CLICK_RELEASE;
					if (tEvent.mouseButton.button == sf::Mouse::Right)
						mEvent = eEvent::RIGHT_CLICK_RELEASE;
				}
			break;

			case sf::Event::Resized:
				mEvent = eEvent::RESIZE;
				RunEventListeners(eEvent::RESIZE);
			break;

			default:
				mEvent = (inside) ? eEvent::INSIDE : eEvent::OUTSIDE;
				break;
			}

			if (mPreviousEvent != mEvent)
			{
				RunEventListeners(mEvent);
			}

			if (tEvent.type == sf::Event::TextEntered)
				mCharInput = tEvent.text.unicode;
			else
				mCharInput = 0;
			mPreviousEvent = mEvent;
		}

		void EventManager::AddEventListener(eEvent tEvent ,std::function<void()> tListener)
		{
			if (mKeyListeners.find((uint32_t)tEvent) == mKeyListeners.end())
				mKeyListeners[(uint32_t)tEvent] = std::vector<std::function<void()>>();
			mKeyListeners[(uint32_t)tEvent].push_back(tListener);
		}

		void EventManager::RemoveEventListener(eEvent tEvent, std::function<void()> tListener)
		{
			(void)tEvent;
			(void)tListener;
			throw std::runtime_error("Not implemented");
		}

		void EventManager::RemoveAllEventListener(eEvent tEvent)
		{
			mKeyListeners[(uint32_t)tEvent].clear();
		}


		void    EventManager::TriggerEvent(eEvent tEvent)
		{
			RunEventListeners(tEvent);
		}

		void	EventManager::SetFocus(bool tFocus)
		{
			mFocus = tFocus;
			if (tFocus)
				RunEventListeners(eEvent::FOCUS);
			else
				RunEventListeners(eEvent::LOST_FOCUS);
		}

	} // namespace component
	
	

} // namespace mf
