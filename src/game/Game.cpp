#include "Globals.hpp"
#include "Game.hpp"

void Game::start()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        m_window.clear(Globals::DEFAULT_BG_COLOR);

        m_window.display();
    }
}
