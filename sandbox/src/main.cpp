#include "../../include/mfGUI.hpp"

std::shared_ptr<mf::List>	createList()
{
	std::shared_ptr<mf::List> list = mf::List::Create();
	list->SetPosition(0, 50);
	list->SetSize(100, 90);
	list->SetSizePercentage(true, true);
	list->GetBackground()->SetBackground(sf::Color(200, 200, 250));
	list->SetItemSpacing(5);
	list->SetItemDirection(mf::eDirection::VERTICAL);
	list->SetContentOffset(sf::Vector2f(10, 10));
	list->SetContentOverflow(mf::List::eOverflow::NOWRAP);

	return list;
}

std::shared_ptr<mf::Button>	createButton()
{
	std::shared_ptr<mf::Button> button = mf::Button::Create();
	button->SetSize(100, 40);
	button->GetText()->SetString("Button");
	button->GetText()->SetPos({5, 0});
	button->GetBackground()->SetBackground(sf::Color::Red);
	button->GetBackground()->SetOutlineColor(sf::Color::Black);
	button->GetBackground()->SetOutlineThickness(1);
	button->AddEventListener(mf::eEvent::ENTERED, [button]()
	{
		button->GetBackground()->SetBackground(sf::Color::Transparent);
	});
	button->AddEventListener(mf::eEvent::EXITED, [button]()
	{
		button->GetBackground()->SetBackground(sf::Color::Red);
	});

	return button;
}

std::shared_ptr<mf::Text>	createText()
{
	std::shared_ptr<mf::Text> text = mf::Text::Create();
	text->SetSize(100, 40);
	text->GetText()->SetString("Text");

	return text;
}

std::shared_ptr<mf::Image>	createImage()
{
	std::shared_ptr<mf::Image> image = mf::Image::Create();
	image->SetSize(100, 100);
	image->SetImage("./assets/photo-1542044896530-05d85be9b11a.jpeg");

	return image;
}

std::shared_ptr<mf::Slider>	createSlider()
{
	std::shared_ptr<mf::Slider> slider = mf::Slider::Create();
	slider->SetSize(100, 20);
	slider->SetDirection(mf::eDirection::HORIZONTAL);
	slider->SetValue(0.5);
	slider->GetButton()->GetBackground()->SetBackground(sf::Color::Red);
	slider->GetButton()->GetBackground()->SetOutlineColor(sf::Color::Black);
	slider->GetButton()->GetBackground()->SetOutlineThickness(1);
	slider->GetButton()->AddEventListener(mf::eEvent::ENTERED, [slider]()
	{
		slider->GetButton()->GetBackground()->SetBackground(sf::Color::Transparent);
	});
	slider->GetButton()->AddEventListener(mf::eEvent::EXITED, [slider]()
	{
		slider->GetButton()->GetBackground()->SetBackground(sf::Color::Red);
	});

	return slider;
}

std::shared_ptr<mf::Checkbox>	createCheckbox()
{
	std::shared_ptr<mf::Checkbox> checkbox = mf::Checkbox::Create();

	return checkbox;
}


std::shared_ptr<mf::Text>	createFPSCounter()
{
	std::shared_ptr<mf::Text> fpsCounter = mf::Text::Create();
	fpsCounter->SetPosition(10, 10);
	fpsCounter->SetSize(200, 30);
	fpsCounter->GetText()->SetString("0 FPS");

	return fpsCounter;
}


int main()
{
	sf::RenderWindow	window(sf::VideoMode(1600, 900), "Sandbox", sf::Style::Default);

	mf::GUI::Init(&window);
	bool	isOpen = true;


	auto fpsCounter = createFPSCounter();
	mf::GUI::AddWidget(fpsCounter);

	auto list = createList();
	mf::GUI::AddWidget(list);

	auto button = createButton();
	list->AddWidget(button);

	auto text = createText();
	list->AddWidget(text);

	auto image = createImage();
	list->AddWidget(image);

	auto slider = createSlider();
	list->AddWidget(slider);

	auto checkbox = createCheckbox();
	list->AddWidget(checkbox);
	
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