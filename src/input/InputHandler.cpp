#include "InputHandler.hpp"

using Input::InputHandler;

void InputHandler::subscribe(InputObserver* observer)
{
    m_observers.push_back(observer);
}

void InputHandler::unsubscribe(InputObserver* observer)
{
    // erase-remove idiom
    m_observers.erase(
        std::remove(m_observers.begin(), m_observers.end(), observer),
        m_observers.end()
    );
}

void InputHandler::notifyDirection(Globals::Direction dir)
{
    for (InputObserver* observer : m_observers)
        observer->onDirectionInput(dir);
}

void InputHandler::handleEvents(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.scancode)
            {
                case sf::Keyboard::Scan::Up:    notifyDirection(Globals::Direction::Up);    break;
                case sf::Keyboard::Scan::Down:  notifyDirection(Globals::Direction::Down);  break;
                case sf::Keyboard::Scan::Left:  notifyDirection(Globals::Direction::Left);  break;
                case sf::Keyboard::Scan::Right: notifyDirection(Globals::Direction::Right); break;
                default: break;
            }
        }
    }
}
