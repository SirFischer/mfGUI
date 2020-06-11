#include "../../includes/mfGUI.hpp"

void CreateMainMenu(bool *isOpen)
{
	mf::GUI::ClearWidgets();

	mf::Button	*btn = mf::Button::Create(sf::Color::Blue, sf::Color::Cyan);
	btn->SetPosition(1300, 50)
	->SetSize(100, 50)
	->SetTextFont("assets/Bangers-Regular.ttf")
	->SetTextColor(sf::Color::Black)
	->SetText("Quit!")
	->SetClickEvent([isOpen] {
		*isOpen = false;
	});
	mf::GUI::AddWidget(btn);
	mf::GUI::AddWidget(mf::Image::Create("assets/photo-1542044896530-05d85be9b11a.jpeg")
	->SetSize(700.f, 500.f)
	->SetPosition(100.f, 50.f)
	->SetOutlineColor(sf::Color::Black)
	->SetOutlineThickness(3.f));

	mf::GUI::AddWidget(mf::Text::Create("assets/Bangers-Regular.ttf", "This is a test text widget to test the text wrapping algorithm...")
	->SetPosition(300, 300)
	->SetSize(200, 300)
	->SetOutlineColor(sf::Color::Black)
	->SetOutlineThickness(1.5f)
	->SetTextColor(sf::Color::Black));
}

int main()
{
	sf::RenderWindow	window(sf::VideoMode(1600, 900), "Sandbox", sf::Style::Default);
	mf::GUI::Init(&window);
	bool	isOpen = true;

	CreateMainMenu(&isOpen);

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
			mf::GUI::HandleEvent(event);
		}
		window.clear(sf::Color::White);
		mf::GUI::Render();
		window.display();
	}
	window.close();
	mf::GUI::ClearWidgets();
}