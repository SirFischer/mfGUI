#include "List.hpp"

namespace mf
{
	List::List(/* args */)
	:mBackground(&mTransform.mPosition, &mTransform.mSize)
	,mScrollBar(&mTransform.mPosition, &mTransform.mSize, &mContentSize, &mContentPosition)
	{
		
	}

	List::~List()
	{
	}

	List      *List::Create()
	{
		List   *list = new List();
		list->mScrollBar.GetSlider()->SetValue(1);
		return (list);
	}

	void		List::HandleEvent(sf::Event &tEvent)
	{
		mScrollBar.HandleEvent(tEvent);
		Widget::HandleEvent(tEvent);
	}

	void		List::Render(sf::RenderWindow *tWindow)
	{
		UpdateChildren();
		UpdateContentData();
		mView.setViewport(sf::FloatRect(mTransform.mPosition.x / (float)tWindow->getSize().x,
									mTransform.mPosition.y / (float)tWindow->getSize().y,
									mTransform.mSize.x / (float)tWindow->getSize().x,
									mTransform.mSize.y / (float)tWindow->getSize().y));
		mView.reset(sf::FloatRect(sf::Vector2f(mTransform.mPosition.x, mTransform.mPosition.y + mContentPosition.y), mTransform.mSize));
		mBackground.Draw(tWindow);
		sf::View tmp = tWindow->getView();
		mScrollBar.Draw(tWindow);
		tWindow->setView(mView);
		Widget::Render(tWindow);
		tWindow->setView(tmp);
	}

	void		List::UpdateChildren()
	{
		Widget	*lastWidget = NULL;
		float offset = 0;
		float maxOffset = 0;
		mScrollBar.GetSlider()->SetValue(mScrollBar.GetSlider()->GetValue());
		for (auto &child : mWidgets)
		{
			if ((child->GetSize().x > maxOffset && mListDirection == eDirection::VERTICAL) ||
				(child->GetSize().y > maxOffset && mListDirection == eDirection::HORIZONTAL))
				maxOffset = (mListDirection == eDirection::VERTICAL) ? child->GetSize().x : child->GetSize().y;

			if (mListDirection == eDirection::VERTICAL)
			{
				if (((lastWidget) ? lastWidget->GetPosition().y + lastWidget->GetSize().y + mItemSpacing : 0) + child->GetSize().y > mTransform.mSize.y + mTransform.mPosition.y   && mOverflow == eOverflow::WRAP)
				{
					if (maxOffset != 0 && lastWidget)
					{
						offset += maxOffset + mItemSpacing;
						lastWidget = NULL;
					}
					maxOffset = 0;
				}
				child->SetPosition(offset, ((lastWidget) ? lastWidget->GetRelativePosition().y + lastWidget->GetSize().y : 0) + mItemSpacing);
			}
			else
			{
				if (((lastWidget) ? lastWidget->GetPosition().x + lastWidget->GetSize().x + mItemSpacing : 0) + child->GetSize().x > mTransform.mSize.x + mTransform.mPosition.x && mOverflow == eOverflow::WRAP)
				{
					if (maxOffset != 0 && lastWidget)
					{
						offset += maxOffset + mItemSpacing;
						lastWidget = NULL;
					}
					maxOffset = 0;
				}
				child->SetPosition(((lastWidget) ? lastWidget->GetRelativePosition().x + lastWidget->GetSize().x : 0) + mItemSpacing, offset);
			}
			lastWidget = child;
		}
	}

	void			List::UpdateContentData()
	{
		sf::Vector2f	size = sf::Vector2f(0, 0);
		for (auto &child : mWidgets)
		{
			size.x += child->GetSize().x;
			size.y += child->GetSize().y;
			if (mContentPosition.x > child->GetPosition().x)
				mContentPosition.x = child->GetPosition().x;
			if (mContentPosition.y > child->GetPosition().y)
				mContentPosition.y = child->GetPosition().y;
		}
		mContentSize.x = size.x + (mWidgets.size() * mItemSpacing);
		mContentSize.y = size.y + (mWidgets.size() * mItemSpacing);
	}
}
