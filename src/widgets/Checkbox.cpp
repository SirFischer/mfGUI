#include "Checkbox.hpp"

namespace mf
{
	Checkbox::Checkbox()
	: mBackground(&mPosition, &mSize)
	, mChecked(false)
	{
		mBackground.SetBackground(sf::Color::White);
		mBackground.SetOutlineColor(sf::Color::Black);
		mBackground.SetOutlineThickness(1);

		mEventManager.AddEventListener(eEvent::LEFT_CLICK, [this]()
		{
			mChecked = !mChecked;
		});

	}

	Checkbox::~Checkbox()
	{

	}

	void		Checkbox::Render(sf::RenderWindow *tWindow)
	{
		mBackground.Draw(tWindow);
		if (mChecked)
		{
			DrawCheckMark(tWindow);
		}
	}

	std::shared_ptr<Checkbox>      Checkbox::Create()
	{
		std::shared_ptr<Checkbox> checkbox(new Checkbox());
		checkbox->SetSize(sf::Vector2f(20, 20));

		return (checkbox);
	}

	void		Checkbox::SetChecked(bool tChecked)
	{
		mChecked = tChecked;
	}

	void Checkbox::DrawCheckMark(sf::RenderWindow *tWindow)
    {
        sf::VertexArray checkMark(sf::Lines, 4);

        checkMark[0].position = sf::Vector2f(mPosition.x + 4, mPosition.y + 10);
        checkMark[1].position = sf::Vector2f(mPosition.x + 8, mPosition.y + 14);
        checkMark[2].position = sf::Vector2f(mPosition.x + 8, mPosition.y + 14);
        checkMark[3].position = sf::Vector2f(mPosition.x + 16, mPosition.y + 4);

        checkMark[0].color = sf::Color::Black;
        checkMark[1].color = sf::Color::Black;
        checkMark[2].color = sf::Color::Black;
        checkMark[3].color = sf::Color::Black;

        tWindow->draw(checkMark);
    }

} // namespace mf