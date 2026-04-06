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

void InputHandler::notifyDirection(Globals::Direction dir)
{
    auto observers { m_observers };
    for (IInputObserver* observer : observers)
        observer->onDirectionInput(dir);
}

void InputHandler::notifyResetPosition()
{
    auto observers { m_observers };
    for (IInputObserver* observer : observers)
        observer->resetPosition();
}

void InputHandler::notifyMousePosition(float x, float y)
{
    Vector2f pos { x, y };
    auto observers { m_observers };
    for (IInputObserver* observer : observers)
        observer->onMouseHover(pos);
}

void InputHandler::notifyMouseClick(float x, float y)
{
    Vector2f pos { x, y };
    auto observers { m_observers };
    for (IInputObserver* observer : observers)
    {
        if (observer->onMouseClick(pos)) break;
    }
}

void InputHandler::notifyEscapePressed()
{
    auto observers { m_observers };
    for (IInputObserver* observer : observers)
    {
        if (observer->onEscapePressed()) break;
    }
}

void InputHandler::notifyConfirm()
{
    auto observers { m_observers };
    for (IInputObserver* observer : observers)
    {
        if (observer->onConfirm()) break;
    }
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
                case sf::Keyboard::Scan::Up:     notifyDirection(Globals::Direction::Up);    break;
                case sf::Keyboard::Scan::W:      notifyDirection(Globals::Direction::Up);    break;
                case sf::Keyboard::Scan::K:      notifyDirection(Globals::Direction::Up);    break;
                case sf::Keyboard::Scan::Down:   notifyDirection(Globals::Direction::Down);  break;
                case sf::Keyboard::Scan::S:      notifyDirection(Globals::Direction::Down);  break;
                case sf::Keyboard::Scan::J:      notifyDirection(Globals::Direction::Down);  break;
                case sf::Keyboard::Scan::Left:   notifyDirection(Globals::Direction::Left);  break;
                case sf::Keyboard::Scan::A:      notifyDirection(Globals::Direction::Left);  break;
                case sf::Keyboard::Scan::H:      notifyDirection(Globals::Direction::Left);  break;
                case sf::Keyboard::Scan::Right:  notifyDirection(Globals::Direction::Right); break;
                case sf::Keyboard::Scan::D:      notifyDirection(Globals::Direction::Right); break;
                case sf::Keyboard::Scan::L:      notifyDirection(Globals::Direction::Right); break;
                case sf::Keyboard::Scan::R:      notifyResetPosition();                      break;
                case sf::Keyboard::Scan::Escape: notifyEscapePressed();                      break;
                case sf::Keyboard::Scan::Enter:  notifyConfirm();                            break;
                case sf::Keyboard::Scan::Space:  notifyConfirm();                            break;
                default: break;
            }
        }
        if (event.type == sf::Event::MouseMoved)
            notifyMousePosition(event.mouseMove.x, event.mouseMove.y);
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                Vector2f pos { sf::Mouse::getPosition(m_window) };
                notifyMouseClick(pos.x, pos.y);
            }
        }
    }
}
