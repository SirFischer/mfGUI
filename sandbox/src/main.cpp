#include "../../include/mfGUI.hpp"

std::shared_ptr<mf::Container>  CreateMainMenu()
{
	auto container = mf::Container::Create();
	container->SetSize(80.f, 80.f);
	container->SetSizePercentage(true, true);
	container->SetPosition(5.f, 20.f);
	container->SetPositionPercentage(true, false);
	container->GetBackground()->SetBackground(sf::Color::Red);

	auto button = mf::Button::Create();
	container->AddWidget(button);
	button->SetPosition(5, 5);
	button->GetBackground()->SetBackground(sf::Color::White);
	button->GetBackground()->SetOutlineColor(sf::Color::Red);
	button->GetBackground()->SetOutlineThickness(1.f);
	button->AddEventListener(mf::eEvent::ENTERED, [button](){
		std::cout << "entered" << "\n";
		button->GetBackground()->SetBackground(sf::Color::Green);
	});
	button->AddEventListener(mf::eEvent::EXITED, [button](){
		std::cout << "exited" << "\n";
		button->GetBackground()->SetBackground(sf::Color::White);
	});
	button->GetText()->SetString("Button");
	button->SetClickEvent([](){std::cout << "test" << "\n";});

	auto image = mf::Image::Create();
	container->AddWidget(image);
	image->SetPosition(5, 60);
	image->SetSize(200, 200);
	image->SetImage("assets/photo-1542044896530-05d85be9b11a.jpeg");

	auto slider = mf::Slider::Create();
	container->AddWidget(slider);
	slider->SetPosition(5, 270);
	slider->SetSize(200, 30);
	slider->GetBackground()->SetOutlineColor(sf::Color::Red);

	return (container);
}

int main()
{
	sf::RenderWindow	window(sf::VideoMode(1600, 900), "Sandbox", sf::Style::Default);

	mf::GUI::Init(&window);
	bool	isOpen = true;

	auto container = CreateMainMenu();
	mf::GUI::AddWidget(container);

	auto fpsCounter = mf::Button::Create();
	fpsCounter->SetPosition(90, 0);
	fpsCounter->SetSize(200, 30);
	fpsCounter->GetText()->SetString("0 FPS");
	fpsCounter->SetPositionPercentage(true, false);

	mf::GUI::AddWidget(fpsCounter);

	int fps = 0;
	sf::Clock fpsClock;
	while (isOpen)
	{
		fps++;
		if (fpsClock.getElapsedTime().asSeconds() > 1.0)
		{
			fpsCounter->GetText()->SetString(std::to_string(fps) + " FPS");
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