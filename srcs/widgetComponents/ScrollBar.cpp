#include "ScrollBar.hpp"

namespace mf
{
	namespace component
	{
		ScrollBar::ScrollBar(sf::Vector2f *tPos, sf::Vector2f *tSize, sf::Vector2f *tContentSize, sf::Vector2f *tContentPosition) {
			mPos = tPos;
			mSize = tSize;
			mContentSize = tContentSize;
			mContentPosition = tContentPosition;
			mSlider = mf::Slider::Create();
			mSlider->SetValue(1);
		}
		ScrollBar::~ScrollBar() {
			delete mSlider;
		}

		void				ScrollBar::HandleEvent(sf::Event &tEvent)
		{
			mSlider->HandleEvent(tEvent);
			if (mContentSize->y > mSize->y)
				mContentPosition->y = (mSlider->GetValue() * std::abs(mSize->y - mContentSize->y));
			else
				mContentPosition->y = 0;
		}

		void            	ScrollBar::Draw(sf::RenderWindow *tWindow)
		{
			if (mContentSize->y > mSize->y)
			{
				mSlider->SetDirection(eDirection::VERTICAL);
				mSlider->SetSize(30, mSize->y - 2);
				mSlider->SetPosition((mPos->x + mSize->x) - 31, mPos->y + 1);
				mSlider->Render(tWindow);
			}
		}
	}
} // namespace mf
