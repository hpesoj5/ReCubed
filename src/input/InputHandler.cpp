#include "InputHandler.hpp"

using Input::InputHandler;

void InputHandler::subscribe(IInputObserver* observer)
{
    m_observers.push_back(observer);
}

void InputHandler::unsubscribe(IInputObserver* observer)
{
    // erase-remove idiom
    m_observers.erase(
        std::remove(m_observers.begin(), m_observers.end(), observer),
        m_observers.end()
    );
}

void InputHandler::notifyDirection(Globals::Direction dir)
{
    for (IInputObserver* observer : m_observers)
        observer->onDirectionInput(dir);
}

void InputHandler::notifyResetPosition()
{
    for (IInputObserver* observer : m_observers)
        observer->resetPosition();
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
                case sf::Keyboard::Scan::W:     notifyDirection(Globals::Direction::Up);    break;
                case sf::Keyboard::Scan::K:     notifyDirection(Globals::Direction::Up);    break;
                case sf::Keyboard::Scan::Down:  notifyDirection(Globals::Direction::Down);  break;
                case sf::Keyboard::Scan::S:     notifyDirection(Globals::Direction::Down);  break;
                case sf::Keyboard::Scan::J:     notifyDirection(Globals::Direction::Down);  break;
                case sf::Keyboard::Scan::Left:  notifyDirection(Globals::Direction::Left);  break;
                case sf::Keyboard::Scan::A:     notifyDirection(Globals::Direction::Left);  break;
                case sf::Keyboard::Scan::H:     notifyDirection(Globals::Direction::Left);  break;
                case sf::Keyboard::Scan::Right: notifyDirection(Globals::Direction::Right); break;
                case sf::Keyboard::Scan::D:     notifyDirection(Globals::Direction::Right); break;
                case sf::Keyboard::Scan::L:     notifyDirection(Globals::Direction::Right); break;
                case sf::Keyboard::Scan::R:     notifyResetPosition();
                default: break;
            }
        }
    }
}
