#include "Slider.hpp"

namespace mf
{
	Slider::Slider(/* args */)
	:mBackground(&mPosition, &mSize)
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
			this->mChangeListener();
		});
	}

	void		Slider::SetButtonHeight()
	{
		if (mDirection == eDirection::HORIZONTAL)
			mButton->SetSize(mButton->GetSize().x, mSize.y);
		else
			mButton->SetSize(mSize.x, mButton->GetSize().y);
	}

	std::shared_ptr<Slider>      Slider::Create()
	{
		try {
			std::shared_ptr<Slider> slider(new Slider());
			slider->mButton = Button::Create();
			slider->AddWidget(slider->mButton);
			slider->SetSize(200, 40);
			slider->mBackground.SetOutlineColor(sf::Color::Black);
			slider->mBackground.SetOutlineThickness(1.f);
			slider->mButton->SetSize(30, 40);
			slider->mButton->GetBackground()->SetBackground(sf::Color::Blue);
			slider->mButton->SetPosition(0, 0);
			slider->mButton->GetText()->SetString("");
			return (slider);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		return (nullptr);
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
			this->mChangeListener();
		}
		Widget::HandleEvent(tEvent);
	}


	void		Slider::SetValue(float tValue)
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
	};



	void		Slider::SetDirection(eDirection tDirection)
	{
		mDirection = tDirection;
		SetButtonHeight();
	}

	void		Slider::SetSize(sf::Vector2f tSize)
	{
		Widget::SetSize(tSize);
		SetButtonHeight();
	}

	void		Slider::SetSize(float tX, float tY)
	{
		Widget::SetSize(tX, tY);
		SetButtonHeight();
	}

}
