#include "../../include/mfGUI.hpp"

mf::Container *CreateMainMenu()
{
	mf::Container *container = mf::Container::Create();
	container
	->SetSize(80.f, 80.f)
	->SetSizePercentage(true, true)
	->SetOutlineColor(sf::Color::Blue)
	->SetBackground(sf::Color(230, 230, 240))
	->SetOutlineThickness(1.f)
	->SetPosition(5.f, 20.f)
	->SetPositionPercentage(true, false);

	mf::Button *button;
	container->AddWidget((button = mf::Button::Create())
	->SetPosition(5, 5)
	->SetBackground(sf::Color::White)
	->SetOutlineColor(sf::Color::Red)
	->SetOutlineThickness(1.f)
	->AddEventListener(mf::eEvent::ENTERED, [button](){
		std::cout << "entered" << "\n";
		button->SetBackground(sf::Color::Green);
	})
	->AddEventListener(mf::eEvent::EXITED, [button](){
		std::cout << "exited" << "\n";
		button->SetBackground(sf::Color::White);
	})
	->SetText("test")
	->SetClickEvent([](){std::cout << "test" << "\n";}));

	mf::Image *image;
	container->AddWidget((image = mf::Image::Create())
	->SetPosition(5, 60)
	->SetSize(200, 200)
	->SetImage("assets/photo-1542044896530-05d85be9b11a.jpeg"));

	mf::Slider *slider;
	container->AddWidget((slider = mf::Slider::Create())
	->SetPosition(5, 270)
	->SetSize(200, 30)
	->SetOutlineColor(sf::Color::Red));

	return (container);
}

int main()
{
	sf::RenderWindow	window(sf::VideoMode(1600, 900), "Sandbox", sf::Style::Default);

	mf::GUI::Init(&window);
	bool	isOpen = true;

	auto container = CreateMainMenu();
	mf::GUI::AddWidget(container);

	auto fpsCounter =
	mf::Button::Create()
	->SetPosition(90, 0)
	->SetSize(200, 30)
	->SetText("0 FPS")
	->SetPositionPercentage(true, false);

	mf::GUI::AddWidget(fpsCounter);

	int fps = 0;
	sf::Clock fpsClock;
	while (isOpen)
	{
		fps++;
		if (fpsClock.getElapsedTime().asSeconds() > 1.0)
		{
			fpsCounter->SetText(std::to_string(fps) + " FPS");
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
		}
		window.clear(sf::Color::White);
		mf::GUI::Render();
		window.display();
	}
	window.close();
	mf::GUI::ClearWidgets();
}