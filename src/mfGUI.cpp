#include "mfGUI.hpp"

namespace mf
{
	sf::RenderWindow		*GUI::mWindow = NULL;
	std::shared_ptr<Widget>	GUI::mBaseWidget = NULL;

	void		GUI::Init(sf::RenderWindow *tWindow)
	{
		mWindow = tWindow;
		mBaseWidget = Widget::Create();
		mBaseWidget->SetSize(sf::Vector2f(tWindow->getSize()));
	}

	void		GUI::HandleEvent(sf::Event	&tEvent)
	{
		if (tEvent.type == sf::Event::Resized)
		{
			mBaseWidget->SetSize(sf::Vector2f(tEvent.size.width, tEvent.size.height));
		}
		mBaseWidget->HandleEvent(tEvent);
	}

	void		GUI::Render()
	{
		mBaseWidget->Render(mWindow);
	}

	void		GUI::AddWidget(std::shared_ptr<Widget> tWidget)
	{
		mBaseWidget->AddWidget(tWidget);
	}

	void		GUI::RemoveWidget(std::shared_ptr<Widget> tWidget)
	{
		mBaseWidget->RemoveWidget(tWidget);
	}

	void		GUI::ClearWidgets()
	{
		mBaseWidget->ClearWidgets();
	}

} // namespace mf

