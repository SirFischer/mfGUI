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

	mf::Widget	*image = mf::Widget::Create()->SetPosition(sf::Vector2f(20, 20))->SetSize(sf::Vector2f(1060, 860));
	image->mBackground.SetBackground(sf::Color::Blue);
	image->mEventManager.AddEventListener( mf::eEvent::INSIDE, [image] {
		image->mBackground.SetBackground("assets/photo-1542044896530-05d85be9b11a.jpeg");
	});

	image->mEventManager.AddEventListener(mf::eEvent::OUTSIDE, [image] {
		image->mBackground.SetBackground(sf::Color::Blue);
	});

	image->mEventManager.AddEventListener(mf::eEvent::LEFT_CLICK, [image] {
		image->mBackground.SetBackground(sf::Color::Cyan);
		std::cout << "Clicked!" << std::endl;
	});

	image->mEventManager.AddEventListener(mf::eEvent::LEFT_CLICK_RELEASE, [image] {
		image->mBackground.SetBackground(sf::Color::Green);
	});
	
	mf::GUI::AddWidget(image->AddWidget((mf::Image::Create("assets/photo-1542044896530-05d85be9b11a.jpeg")->SetPosition(sf::Vector2f(30, 30))
	->SetSize(sf::Vector2f(1000, 800))
	->SetPositionType(mf::ePosition::RELATIVE))));

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
		window.clear(sf::Color::Red);
		mf::GUI::Render();
		window.display();
	}
}