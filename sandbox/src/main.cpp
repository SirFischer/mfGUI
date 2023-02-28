#include "../../include/mfGUI.hpp"

mf::Container *CreateMainMenu()
{
	mf::GUI::ClearWidgets();

	mf::Container *container = mf::Container::Create();
	container
	->SetSize(500.f, 500.f)
	->SetPosition(5.f, 20.f)
	->SetOutlineColor(sf::Color::Blue)
	->SetOutlineThickness(3.f)
	->SetSizePercentage(false, false)
	->SetPositionPercentage(true, false)
	->AddWidget(mf::Button::Create()
	->SetTextFont("assets/Bangers-Regular.ttf")
	->SetBackground(sf::Color::Black)
	->SetText("test"))
	->AddWidget(mf::Button::Create()
	->SetTextFont("assets/Bangers-Regular.ttf")
	->SetPosition(150, 0)
	->SetBackground(sf::Color::Red)
	->SetText("test"));
	return (container);
}

int main()
{
	sf::RenderWindow	window(sf::VideoMode(1600, 900), "Sandbox", sf::Style::Default);

	mf::GUI::Init(&window);
	bool	isOpen = true;

	auto container = CreateMainMenu();

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
			container->HandleEvent(event);
			mf::GUI::HandleEvent(event);
		}
		window.clear(sf::Color::White);
		mf::GUI::Render();
		container->Render(&window);
		window.display();
	}
	window.close();
	mf::GUI::ClearWidgets();
}