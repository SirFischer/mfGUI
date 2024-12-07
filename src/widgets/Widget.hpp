#pragma once

#include <boost/range/adaptor/reversed.hpp>

#include <SFML/Graphics.hpp>
#include "../utils/Events.hpp"

#include "../widgetComponents/Background.hpp"
#include "../widgetComponents/EventManager.hpp"
#include "../widgetComponents/Text.hpp"
#include "../widgetAttributes/Transform.hpp"

namespace mf
{
	class Widget : public attribute::Transformable
	{
	protected:
		Widget(/* args */)
			: mEventManager(&this->mPosition, &this->mSize)
		{
			
			// Default resize function
			mEventManager.AddEventListener(eEvent::RESIZE, [this] {
				this->SetPosition(mRelativePosition);
				this->SetSize(mRelativeSize);
			});
		}

		// Components
		component::EventManager mEventManager;

		// tmp
		sf::Vector2f mContentSize = sf::Vector2f(0, 0);
		sf::Vector2f mContentPosition = sf::Vector2f(0, 0);

		sf::View mView;

		int mIndex = 0; // draw Order Index
		bool mDisabled = false;
		bool mClickThrough = false;

		std::vector<Widget *> mWidgets = std::vector<Widget *>();

		/**
		 * INTERNAL FUNCTIONS
		 **/
		virtual void Resize()
		{
			mEventManager.TriggerEvent(mf::eEvent::RESIZE);
			for (auto &i : mWidgets)
				i->Resize();
		}

		virtual void Init()
		{
			this->SetPosition(mRelativePosition);
			this->SetSize(mRelativeSize);
		}

		virtual void SortWidgets()
		{
			std::sort(mWidgets.begin(), mWidgets.end(), [](mf::Widget *first, mf::Widget *second){
				return (first->GetIndex() < second->GetIndex());
			});
		}

		virtual void UpdatePosition()
		{
			SetPosition(mRelativePosition);
			for (auto &child : mWidgets)
			{
				child->UpdatePosition();
			}
		}

		virtual void UpdateSize()
		{
			SetSize(mRelativeSize);
			for (auto &child : mWidgets)
			{
				child->UpdateSize();
			}
		}

	public:
		friend class GUI;

		virtual ~Widget() {}

		static Widget *Create()
		{
			Widget *widget = new Widget();
			return (widget);
		}

		virtual void Render(sf::RenderWindow *tWindow)
		{
			for (auto &i : mWidgets)
				if (!i->mDisabled)
					i->Render(tWindow);
		}

		virtual void HandleEvent(sf::Event &tEvent)
		{
			mEventManager.Update(tEvent);
			bool isClickThrough = true;
			for (auto &i : boost::adaptors::reverse(mWidgets))
			{
				eEvent event = i->GetEvent();
				if (!i->mDisabled && isClickThrough)
					i->HandleEvent(tEvent);
				else
					i->Resize();
				if (!i->mDisabled && ((!i->IsClickThrough() && (event != eEvent::OUTSIDE && event != eEvent::EXITED))))
					isClickThrough = false;
			}
		}

		void			AddWidget(Widget *tWidget)
		{
			tWidget->SetParent(this);
			tWidget->SetPosition(tWidget->mRelativePosition);
			mWidgets.push_back(tWidget);
			tWidget->Init();
			SortWidgets();
		}

		void			RemoveWidget(Widget *tWidget)
		{
			std::vector<mf::Widget *>::iterator it;
			if ((it = std::find(mWidgets.begin(), mWidgets.end(), tWidget)) != mWidgets.end())
			{
				(*it)->ClearWidgets();
				mWidgets.erase(it);
			}
		}

		void        ClearWidgets()
		{
			while (mWidgets.size())
			{
				mWidgets.back()->ClearWidgets();
				delete mWidgets.back();
				mWidgets.pop_back();
			}
		}

		void		ClearWidgets(bool tDelete)
		{
			while (mWidgets.size())
			{
				mWidgets.back()->ClearWidgets(tDelete);
				if (tDelete)
					delete mWidgets.back();
				mWidgets.pop_back();
			}
		}

		/**
		 * Setters
		 **/

		virtual void SetIndex(int tIndex) { mIndex = tIndex; }
		virtual void SetDisabled(bool tDisabled) { mDisabled = tDisabled; }
		virtual void SetClickThrough(bool tClickThrough) { mClickThrough = tClickThrough; }
		virtual void SetFocus(bool tFocus) { mEventManager.SetFocus(tFocus); }

		/**
		 * Getters
		 **/
		int GetIndex() { return (mIndex); }
		mf::eEvent GetEvent() { return (mEventManager.GetEvent()); }
		bool IsFocus() { return (mEventManager.GetFocus()); }
		bool IsDisabled() { return (mDisabled); }
		bool IsClickThrough() { return (mClickThrough); }
	};

} // namespace mf
