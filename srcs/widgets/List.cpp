#include "List.hpp"

namespace mf
{
	List::List(/* args */)
	:mBackground(&mPos, &mSize)
	{
		
	}

	List::~List()
	{
	}

	List      *List::Create()
	{
		List   *list = new List();
		return (list);
	}

	void		List::Render(sf::RenderWindow *tWindow)
	{
		UpdateChildren();
		mBackground.Draw(tWindow);
		Widget::Render(tWindow);
	}

	void		List::UpdateChildren()
	{
		Widget	*lastWidget = NULL;
		for (auto &child : mWidgets)
		{
			if (mListDirection == eListDirection::VERTICAL)
				child->SetPosition(mContentPosition.x, ((lastWidget) ? lastWidget->GetRelativePosition().y + lastWidget->GetSize().y : 0) + mItemSpacing + mContentPosition.y);
			else
				child->SetPosition(((lastWidget) ? lastWidget->GetRelativePosition().x + lastWidget->GetSize().x : 0) + mItemSpacing + mContentPosition.x, mContentPosition.y);
			lastWidget = child;
		}
	}

}
