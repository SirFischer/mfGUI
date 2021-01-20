#include "../../includes/mfGUI.hpp"

void CreateMainMenu(bool *isOpen, bool *isFullscreen)
{
	mf::GUI::ClearWidgets();

	mf::Button	*btn = mf::Button::Create(sf::Color::Blue, sf::Color::Cyan);
	btn->SetPosition(80, 10)
	->SetSize(100, 50)
	->SetTextFont("assets/Bangers-Regular.ttf")
	->SetTextColor(sf::Color::Black)
	->SetText("Quit!")
	->SetPositionPercentage(true)
	->SetClickEvent([isOpen] {
		*isOpen = false;
	});
	mf::GUI::AddWidget(btn);

	btn = mf::Button::Create(sf::Color::Blue, sf::Color::Cyan);
	btn->SetPosition(80, 50)
	->SetSize(100, 50)
	->SetTextFont("assets/Bangers-Regular.ttf")
	->SetTextColor(sf::Color::Black)
	->SetText("FullScreen")
	->SetPositionPercentage(true)
	->SetClickEvent([isFullscreen] {
		*isFullscreen = true;
	});
	mf::GUI::AddWidget(btn);
	
	mf::Image *img = mf::Image::Create("assets/photo-1542044896530-05d85be9b11a.jpeg");
	mf::GUI::AddWidget(img
	->SetSize(50.f, 50.f)
	->SetPosition(20.f, 20.f)
	->SetOutlineColor(sf::Color::Black)
	->SetOutlineThickness(3.f)
	->SetSizePercentage(true)
	->SetPositionPercentage(true));

	mf::Text	*textWidget = 
	mf::Text::Create("assets/Bangers-Regular.ttf", "This is a test text widget to test the text wrapping algorithm...")
	->SetPosition(30, 30)
	->SetSize(80, 80)
	->SetOutlineColor(sf::Color::Black)
	->SetOutlineThickness(1.0f)
	->SetTextColor(sf::Color::Black)
	->SetSizePercentage(true)
	->EnableEdit();
	img->AddWidget(textWidget);

}

int main()
{
	sf::RenderWindow	window(sf::VideoMode(1600, 900), "Sandbox", sf::Style::Default);
	mf::GUI::Init(&window);
	bool	isOpen = true;
	bool	isFullscreen = false;
	bool	wasFullscreen = false;

	CreateMainMenu(&isOpen, &isFullscreen);

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
				window.setView(sf::View(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), sf::Vector2f(window.getSize())));
			}
			mf::GUI::HandleEvent(event);
			if(isFullscreen)
			{
				window.close();
				window.create(sf::VideoMode(1600, 900), "Sandbox", (wasFullscreen) ? sf::Style::Default : sf::Style::Fullscreen);
				wasFullscreen = !wasFullscreen;
				isFullscreen = false;
			}
		}
		window.clear(sf::Color::White);
		mf::GUI::Render();
		window.display();
	}
	window.close();
	mf::GUI::ClearWidgets();
}