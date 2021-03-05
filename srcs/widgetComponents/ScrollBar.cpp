#include "ScrollBar.hpp"

namespace mf
{
	namespace component
	{
		ScrollBar::ScrollBar(sf::Vector2f *tPos, sf::Vector2f *tSize) {
			mPos = tPos;
			mSize = tSize;
			mSlider = mf::Slider::Create();
		}
		ScrollBar::~ScrollBar() {
			delete mSlider;
		}

		void            	ScrollBar::Draw(sf::RenderWindow *tWindow)
		{
			mSlider->Render(tWindow);
		}
	}
} // namespace mf
