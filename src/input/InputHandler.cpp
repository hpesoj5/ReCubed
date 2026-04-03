#include "InputHandler.hpp"
#include "input/IInputObserver.hpp"
#include <SFML/Window/Keyboard.hpp>

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

void InputHandler::notifyDirection(const ObserverList& observers, Globals::Direction dir)
{
    for (IInputObserver* observer : observers)
        observer->onDirectionInput(dir);
}

void InputHandler::notifyResetPosition(const ObserverList& observers)
{
    for (IInputObserver* observer : observers)
        observer->resetPosition();
}

void InputHandler::notifyMousePosition(const ObserverList& observers, float x, float y)
{
    Vector2f pos { x, y };
    for (IInputObserver* observer : observers)
        observer->onMouseHover(pos);
}

void InputHandler::notifyMouseClick(const ObserverList& observers)
{
    for (IInputObserver* observer : observers)
    {
        if (observer->onMouseClick()) break;
    }
}

void InputHandler::notifyEscapePressed(const ObserverList& observers)
{
    for (IInputObserver* observer : observers)
    {
        if (observer->onEscapePressed()) break;
    }
}

void InputHandler::handleEvents(sf::RenderWindow& window)
{
    auto observers { m_observers };
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.scancode)
            {
                case sf::Keyboard::Scan::Up:     notifyDirection(observers, Globals::Direction::Up);    break;
                case sf::Keyboard::Scan::W:      notifyDirection(observers, Globals::Direction::Up);    break;
                case sf::Keyboard::Scan::K:      notifyDirection(observers, Globals::Direction::Up);    break;
                case sf::Keyboard::Scan::Down:   notifyDirection(observers, Globals::Direction::Down);  break;
                case sf::Keyboard::Scan::S:      notifyDirection(observers, Globals::Direction::Down);  break;
                case sf::Keyboard::Scan::J:      notifyDirection(observers, Globals::Direction::Down);  break;
                case sf::Keyboard::Scan::Left:   notifyDirection(observers, Globals::Direction::Left);  break;
                case sf::Keyboard::Scan::A:      notifyDirection(observers, Globals::Direction::Left);  break;
                case sf::Keyboard::Scan::H:      notifyDirection(observers, Globals::Direction::Left);  break;
                case sf::Keyboard::Scan::Right:  notifyDirection(observers, Globals::Direction::Right); break;
                case sf::Keyboard::Scan::D:      notifyDirection(observers, Globals::Direction::Right); break;
                case sf::Keyboard::Scan::L:      notifyDirection(observers, Globals::Direction::Right); break;
                case sf::Keyboard::Scan::R:      notifyResetPosition(observers); break;
                case sf::Keyboard::Scan::Escape: notifyEscapePressed(observers); break;
                default: break;
            }
        }
        if (event.type == sf::Event::MouseMoved)
            notifyMousePosition(observers, event.mouseMove.x, event.mouseMove.y);
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
                notifyMouseClick(observers);
        }
    }
}
