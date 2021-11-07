#pragma once

#include <boost/range/adaptor/reversed.hpp>

#include <SFML/Graphics.hpp>
#include "utils/Events.hpp"

#include "widgetComponents/Background.hpp"
#include "widgetComponents/EventManager.hpp"
#include "widgetComponents/Text.hpp"
#include "widgetComponents/Transform.hpp"

namespace mf
{
	class Widget
	{
	protected:
		Widget(/* args */);

		//Components
		component::EventManager			mEventManager;
		component::Transform			mTransform;

		//tmp
		sf::Vector2f					mContentSize = sf::Vector2f(0, 0);
		sf::Vector2f					mContentPosition = sf::Vector2f(0, 0);

		sf::View						mView;

		bool							mDisabled = false;
		bool							mClickThrough = false;

		Widget							*mParent = NULL;
		std::vector<Widget *>			mWidgets = std::vector<Widget *>();

		/**
		 * INTERNAL FUNCTIONS
		 **/
		virtual void	Render(sf::RenderWindow *tWindow);
		virtual void	HandleEvent(sf::Event &tEvent);
		virtual void	Resize();

		virtual void	Init();

		virtual void	SortWidgets();

	public:
		virtual ~Widget();
		friend class	GUI;

		static Widget 	*Create();
		Widget			*AddWidget(Widget *tWidget);
		void			RemoveWidget(Widget *tWidget);
		void			ClearWidgets();
		void			ClearWidgets(bool tDelete);

		/**
		 * Setters
		 **/

		virtual Widget	*SetPosition(sf::Vector2f tPos);
		virtual Widget	*SetPosition(float tX, float tY);
		virtual Widget	*SetPositionPercentage(bool tPercentageX, bool tPercentageY);
		virtual Widget	*SetSize(float tX, float tY);
		virtual Widget	*SetSize(sf::Vector2f tSize);
		virtual Widget	*SetSizePercentage(bool tPercentageX, bool tPercentageY);
		virtual Widget	*SetIndex(int tIndex){mTransform.mIndex = tIndex; return (this);}

		virtual Widget	*SetDisabled(bool tDisabled){mDisabled = tDisabled; return (this);}
		virtual Widget	*SetClickThrough(bool tClickThrough){mClickThrough = tClickThrough; return (this);}
		virtual Widget	*SetFocus(bool tFocus){mEventManager.SetFocus(tFocus); return (this);}

		/**
		 * Getters
		 **/
		sf::Vector2f	GetPosition(){return (mTransform.mPosition);}
		sf::Vector2f	GetRelativePosition(){return (mTransform.mRelativePosition);}

		sf::Vector2f	GetSize(){return (mTransform.mSize);}
		sf::Vector2f	GetRelativeSize(){return (mTransform.mRelativeSize);}

		int				GetIndex(){return (mTransform.mIndex);}

		mf::eEvent		GetEvent(){return (mEventManager.GetEvent());}

		bool			IsFocus(){return (mEventManager.GetFocus());}

		bool			IsDisabled(){return (mDisabled);}
		bool			IsClickThrough(){return (mClickThrough);}

	};
	
} // namespace mf
