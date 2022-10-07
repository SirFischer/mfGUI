#include "../../include/mfGUI.hpp"

mf::Text	*text;
mf::Slider	*slider;

void CreateMainMenu()
{
	mf::GUI::ClearWidgets();

	
	mf::Container *container = mf::Container::Create();
	mf::GUI::AddWidget(container
	->SetSize(50.f, 500.f)
	->SetPosition(5.f, 20.f)
	->SetOutlineColor(sf::Color::Black)
	->SetOutlineThickness(3.f)
	->SetSizePercentage(true, false)
	->SetPositionPercentage(true, false)
	->AddWidget(mf::Button::Create()
	->SetTextFont("assets/Bangers-Regular.ttf")
	->SetBackground(sf::Color::Black)
	->SetText("test"))
	->AddWidget(mf::Button::Create()
	->SetTextFont("assets/Bangers-Regular.ttf")
	->SetPosition(150, 0)
	->SetBackground(sf::Color::Black)
	->SetText("test")));


	//LIST TEST
	mf::List	*listWidget = mf::List::Create();
	listWidget->SetPosition(60, 20)
	->SetPositionPercentage(true, true)
	->SetSize(35, 50)
	->SetSizePercentage(true, true)
	->SetBackgroundColor(sf::Color::Green)
	->SetItemDirection(mf::eDirection::VERTICAL)
	->SetContentOverflow(mf::List::eOverflow::NOWRAP)
	->SetContentOffset(sf::Vector2f(20, 10));
	mf::GUI::AddWidget(listWidget);

	mf::Button	*btn = mf::Button::Create();
	listWidget->AddWidget(btn);

	mf::Button	*btn2 = mf::Button::Create();
	btn2->SetSize(120, 50);
	listWidget->AddWidget(btn2);

	mf::Button	*btn3 = mf::Button::Create();
	listWidget->AddWidget(btn3);

	mf::Button	*btn4 = mf::Button::Create();
	btn4->SetSize(110, 30);
	listWidget->AddWidget(btn4);

	mf::Button	*btn5 = mf::Button::Create();
	listWidget->AddWidget(btn5);

	mf::Button	*btn6 = mf::Button::Create(sf::Color::Black, sf::Color::White);
	listWidget->AddWidget(btn6);

	mf::Button	*btn7 = mf::Button::Create(sf::Color::Black, sf::Color::White);
	listWidget->AddWidget(btn7);

	mf::Button	*btn8 = mf::Button::Create(sf::Color::Black, sf::Color::White);
	listWidget->AddWidget(btn8);

	slider = mf::Slider::Create();
	
	slider->SetPosition(70, 60)->SetPositionPercentage(true, true);
	slider->SetDirection(mf::eDirection::VERTICAL);
	slider->SetSize(30, 200);
	mf::GUI::AddWidget(slider);

	text = mf::Text::Create();
	text->SetPosition(85, 80)->SetPositionPercentage(true, true);
	text->SetTextFont("assets/Bangers-Regular.ttf")->SetText(std::to_string(slider->GetValue()));
	text->SetTextColor(sf::Color::Black);
	mf::GUI::AddWidget(text);
}

int main()
{
	sf::RenderWindow	window(sf::VideoMode(1600, 900), "Sandbox", sf::Style::Default);
	mf::GUI::Init(&window);
	bool	isOpen = true;

	CreateMainMenu();

	int fps = 0;
	sf::Clock fpsClock;
	while (isOpen)
	{
		fps++;
		if (fpsClock.getElapsedTime().asSeconds() > 1.0)
		{
			std::cout << "FPS: " << fps << std::endl;
			fps = 0;
			fpsClock.restart();
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				isOpen = false;
			if (event.type == sf::Event::Resized)
			{
				window.setView(sf::View(sf::Vector2f(event.size.width / 2, event.size.height / 2), sf::Vector2f(window.getSize())));
			}
			mf::GUI::HandleEvent(event);
			text->SetText(std::to_string(std::clamp(slider->GetValue(), 0.f, 1.f)));
		}
		window.clear(sf::Color::White);
		mf::GUI::Render();
		window.display();
	}
	window.close();
	mf::GUI::ClearWidgets();
}