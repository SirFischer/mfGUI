#include "Button.hpp"

namespace mf
{

Button::Button()
{

}

Button::~Button()
{

}

Button      *Button::Create(std::string tPathIdle, std::string tPathHover)
{
    Button *btn = new Button();
    btn->mBackground.SetBackground(tPathIdle);
    btn->SetSize(sf::Vector2f(100, 50));
    btn->mEventManager.AddEventListener(eEvent::EXITED, [btn, tPathIdle] {
        btn->mBackground.SetBackground(tPathIdle);
    });
    btn->mEventManager.AddEventListener(eEvent::ENTERED, [btn, tPathHover] {
        btn->mBackground.SetBackground(tPathHover);
    });
    return (btn);
}

Button      *Button::Create(sf::Color tIdle, sf::Color tHover)
{
    Button *btn = new Button();
    btn->mBackground.SetBackground(tIdle);
    btn->SetSize(sf::Vector2f(100, 50));
    btn->mEventManager.AddEventListener(eEvent::EXITED, [btn, tIdle] {
        btn->mBackground.SetBackground(tIdle);
    });
    btn->mEventManager.AddEventListener(eEvent::ENTERED, [btn, tHover] {
        btn->mBackground.SetBackground(tHover);
    });
    return (btn);
}


} // namespace mf
