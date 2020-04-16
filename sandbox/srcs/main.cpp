#include "../../includes/mfGUI.hpp"

// class game
// {

// mfGUI::Button::create

// };

// void init()
// {
// 	mfGUI::init(mWindow);

// }

// void update()
// {
// 	mfGUI::HandleEvents(event);
// }

// void render()
// {
// 	mfGUI::render();
// }

int main()
{
	sf::RenderWindow	window(sf::VideoMode(1600, 900), "Sandbox", sf::Style::Default);
	mf::GUI::Init(&window);

	mf::GUI::AddWidget(mf::Image::Create("assets/photo-1542044896530-05d85be9b11a.jpeg")->SetPosition(sf::Vector2f(window.getSize().x / 2 - 500, 200))
	->SetSize(sf::Vector2f(1000, 800))
	->SetPositionType(mf::ePosition::ABSOLUTE));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			mf::GUI::HandleEvent(event);
		}
		window.clear(sf::Color::Red);
		mf::GUI::Render();
		window.display();
	}
}