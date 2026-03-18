#include "Globals.hpp"
#include <SFML/System/Vector2.hpp>
#include "Game.hpp"

Game::Game()
    : m_window { sf::RenderWindow(sf::VideoMode({ Globals::Window::WIDTH, Globals::Window::HEIGHT }), "ReCubed", sf::Style::Close) }
    , m_player { Player{} }
    , r_player { ReversePlayer{} }
{
    m_window.setVerticalSyncEnabled(true);

    m_player.setPosition(0, 0);
    r_player.setPosition(Globals::Window::X_MAX, Globals::Window::Y_MAX);

    m_inputHandler.subscribe(&m_player);
    m_inputHandler.subscribe(&r_player);
}

Game::~Game()
{
    m_inputHandler.unsubscribe(&r_player);
    m_inputHandler.unsubscribe(&m_player);
}

void Game::draw()
{
    m_player.draw(m_window);
    r_player.draw(m_window);
}

void Game::start()
{

    while (m_window.isOpen())
    {
        m_inputHandler.handleEvents(m_window);

        m_window.clear(Globals::Window::BG_COLOR);

        draw();

        m_window.display();
    }
}
