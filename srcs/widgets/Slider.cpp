#include "Slider.hpp"

namespace mf
{
	Slider::Slider(/* args */)
	:mBackground(&mPos, &mSize)
	{
		LoadClickFunction();
	}

	Slider::~Slider()
	{
	}


	void		Slider::LoadClickFunction()
	{
		component::EventManager	*manager = &mEventManager;
		eDirection *direction = &mDirection;

		mEventManager.AddEventListener(eEvent::LEFT_CLICK, [this, manager, direction] {
			float	relpos;
			if (*direction == eDirection::HORIZONTAL)
				relpos = (manager->GetMousePosition().x - this->GetPosition().x) / (this->GetSize().x  - mButton->GetSize().x) - ((mButton->GetSize().x / 2.f) / this->GetSize().x);
			else
				relpos = (manager->GetMousePosition().y - this->GetPosition().y) / (this->GetSize().y  - mButton->GetSize().y) - ((mButton->GetSize().y / 2.f) / this->GetSize().y);
			this->SetValue(relpos);
		});
	}

	Slider      *Slider::Create()
	{
		Slider   *slider = new Slider();
		slider->SetSize(200, 40);
		slider->SetOutlineColor(sf::Color::Black)->SetOutlineThickness(1.f);
		slider->mButton = Button::Create(sf::Color::Red, sf::Color::Green);
		slider->mButton->SetSize(30, 40);
		slider->AddWidget(slider->mButton);
		slider->mButton->SetPosition(0, 0);
		return (slider);
	}

	void		Slider::Render(sf::RenderWindow *tWindow)
	{
		mBackground.Draw(tWindow);
		Widget::Render(tWindow);
	}

	void		Slider::HandleEvent(sf::Event &tEvent)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mEventManager.GetEvent() == eEvent::INSIDE)
		{
			if (mDirection == eDirection::HORIZONTAL)
				SetValue((mEventManager.GetMousePosition().x - this->GetPosition().x) / (this->GetSize().x  - mButton->GetSize().x) - ((mButton->GetSize().x / 2.f) / this->GetSize().x));
			else
				SetValue((mEventManager.GetMousePosition().y - this->GetPosition().y) / (this->GetSize().y  - mButton->GetSize().y) - ((mButton->GetSize().y / 2.f) / this->GetSize().y));
		}
		Widget::HandleEvent(tEvent);
	}


	Slider		*Slider::SetValue(float tValue)
	{
		mValue = tValue;
		float newpos;
		if (mDirection == eDirection::HORIZONTAL)
		{
			newpos = tValue * (mSize.x - mButton->GetSize().x);
			newpos = std::clamp(newpos, 0.f, mSize.x - mButton->GetSize().x);
			mButton->SetPosition(newpos, 0);
		}
		else
		{
			newpos = tValue * (mSize.y - mButton->GetSize().y);
			newpos = std::clamp(newpos, 0.f, mSize.y - mButton->GetSize().y);
			mButton->SetPosition(0, newpos);
		}
		return (this);
	};

	Slider		*Slider::SetDirection(eDirection tDirection)
	{
		mDirection = tDirection;
		return (this);
	}


}
