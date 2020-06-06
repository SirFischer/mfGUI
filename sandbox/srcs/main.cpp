#include "../../includes/mfGUI.hpp"

void CreateMainMenu(bool *isOpen, bool *isRecreate)
{
	mf::GUI::ClearWidgets();

	mf::Button	*btn = mf::Button::Create(sf::Color::Blue, sf::Color::Cyan);
	btn->SetPosition(sf::Vector2f(1480, 20))
	->SetTextFont("assets/Bangers-Regular.ttf")
	->SetText("Quit!")
	->SetClickEvent([isOpen, isRecreate] {
		*isRecreate = true;
		std::cout << "I was reset!" << std::endl;
	});
	mf::GUI::AddWidget(btn);
}


int main()
{
	sf::RenderWindow	window(sf::VideoMode(1600, 900), "Sandbox", sf::Style::Default);
	mf::GUI::Init(&window);
	bool	isOpen = true;
	bool	isRecreate = false;

	CreateMainMenu(&isOpen, &isRecreate);

	

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
			if (isRecreate)
			{
				CreateMainMenu(&isOpen, &isRecreate);
				isRecreate = false;
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