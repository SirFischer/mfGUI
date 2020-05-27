#include "../../includes/mfGUI.hpp"

void CreateSecondMenu(bool *isOpen);

void CreateMainMenu(bool *isOpen)
{
	mf::GUI::ClearWidgets();
	mf::Widget	*image = mf::Widget::Create()->SetPosition(sf::Vector2f(20, 20))->SetSize(sf::Vector2f(1060, 860));
	
	mf::GUI::AddWidget(image->AddWidget((mf::Image::Create("assets/photo-1542044896530-05d85be9b11a.jpeg")->SetPosition(sf::Vector2f(30, 30))
	->SetSize(sf::Vector2f(1000, 800))
	->SetPositionType(mf::ePosition::RELATIVE))));

	mf::Button	*btn = mf::Button::Create(sf::Color::Blue, sf::Color::Cyan);
	btn->SetPosition(sf::Vector2f(1480, 20));
	btn->SetClickEvent([isOpen] {
		CreateSecondMenu(isOpen);
	});
	btn->SetTextFont("assets/Bangers-Regular.ttf");
	btn->SetText("Quit!");
	mf::GUI::AddWidget(btn);
}

void CreateSecondMenu(bool *isOpen)
{
	mf::GUI::ClearWidgets();
	mf::Button *back = mf::Button::Create(sf::Color::Green, sf::Color::Red);
	back->SetClickEvent([isOpen] {
		CreateMainMenu(isOpen);
	});
	back->SetPosition(sf::Vector2f(500, 400));
	back->SetTextFont("assets/Bangers-Regular.ttf");
	back->SetText("No");
	back->SetTextPosition(sf::Vector2f(35, 5));
	mf::GUI::AddWidget(back);
	back = mf::Button::Create(sf::Color::Red, sf::Color::Green);
	back->SetClickEvent([isOpen] {
		std::cout << "Window Closed!" << std::endl;
		*isOpen = false;
	});
	back->SetPosition(sf::Vector2f(500, 500));
	back->SetTextFont("assets/Bangers-Regular.ttf");
	back->SetTextPosition(sf::Vector2f(35, 5));
	back->SetText("Yes");
	mf::GUI::AddWidget(back);
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