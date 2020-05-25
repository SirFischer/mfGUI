#include "../../includes/mfGUI.hpp"

void CreateSecondMenu(sf::RenderWindow *win);

void CreateMainMenu(sf::RenderWindow	*win)
{
	mf::GUI::ClearWidgets();
	mf::Widget	*image = mf::Widget::Create()->SetPosition(sf::Vector2f(20, 20))->SetSize(sf::Vector2f(1060, 860));
	
	mf::GUI::AddWidget(image->AddWidget((mf::Image::Create("assets/photo-1542044896530-05d85be9b11a.jpeg")->SetPosition(sf::Vector2f(30, 30))
	->SetSize(sf::Vector2f(1000, 800))
	->SetPositionType(mf::ePosition::RELATIVE))));

	mf::Button	*btn = mf::Button::Create(sf::Color::Blue, sf::Color::Cyan);
	btn->SetPosition(sf::Vector2f(1480, 20));
	btn->SetClickEvent([&win] {
		CreateSecondMenu(win);
	});
	mf::GUI::AddWidget(btn);
}

void CreateSecondMenu(sf::RenderWindow *win)
{
	mf::GUI::ClearWidgets();
	mf::Button *back = mf::Button::Create(sf::Color::Green, sf::Color::Red);
	back->SetClickEvent([&win] {
		CreateMainMenu(win);
	});
	mf::GUI::AddWidget(back);
	back = mf::Button::Create(sf::Color::Red, sf::Color::Green);
	back->SetClickEvent([&win] {
		std::cout << "Window Closed!" << std::endl;
		if (win->isOpen())
			win->close();
	});
	back->SetPosition(sf::Vector2f(0, 100));
	mf::GUI::AddWidget(back);
}


int main()
{
	sf::RenderWindow	window(sf::VideoMode(1600, 900), "Sandbox", sf::Style::Default);
	mf::GUI::Init(&window);


	CreateMainMenu(&window);

	int fps = 0;
	sf::Clock fpsClock;
	while (window.isOpen())
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
				window.close();
			mf::GUI::HandleEvent(event);
		}
		window.clear(sf::Color::White);
		mf::GUI::Render();
		window.display();
	}
	mf::GUI::ClearWidgets();
}