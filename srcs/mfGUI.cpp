#include "mfGUI.hpp"

namespace mf
{
	sf::Window	*GUI::mWindow = NULL;
	Widget		*GUI::mBaseWidget = NULL;

	void		GUI::Init(sf::Window *tWindow)
	{
		mWindow = tWindow;
		mBaseWidget = Widget::Create();
		mBaseWidget->SetSize(sf::Vector2f(tWindow->getSize()));

	}

	void		GUI::HandleEvent(sf::Event	&tEvent)
	{
		mBaseWidget->HandleEvent(tEvent);
	}

	void		GUI::Render()
	{
		mBaseWidget->Render(mWindow);
	}

	void		GUI::AddWidget(Widget *tWidget)
	{
		mBaseWidget->AddWidget(tWidget);
	}

	void		GUI::RemoveWidget(Widget *tWidget)
	{
		mBaseWidget->RemoveWidget(tWidget);
	}

	void		GUI::ClearWidgets()
	{
		mBaseWidget->ClearWidgets();
	}

} // namespace mf

