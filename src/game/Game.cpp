#include "Globals.hpp"
#include <SFML/System/Vector2.hpp>
#include "Game.hpp"

Game::Game()
    : m_window { sf::RenderWindow(sf::VideoMode({ Globals::Window::WIDTH, Globals::Window::HEIGHT }), "ReCubed", sf::Style::Close) }
    , m_grid { Grid::Grid(9, 9) }
    , m_player { Player{ m_grid } }
    , r_player { ReversePlayer{ m_grid } }
{
    m_window.setVerticalSyncEnabled(true);

    m_player.setPosition(0, 0);
    r_player.setPosition(m_grid.getWidth() - 1, m_grid.getHeight() - 1);

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
    m_grid.draw(m_window);
    if (m_player.getPosition() == r_player.getPosition())
    {
        sf::RectangleShape combinedPlayer(Vector2f(Globals::Player::SIZE, Globals::Player::SIZE));
        combinedPlayer.setOrigin(combinedPlayer.getSize() / 2.f);
        combinedPlayer.setPosition(m_grid.coordsToVector2f(m_player.getPosition()));
        combinedPlayer.setFillColor(Globals::Player::COLOR + Globals::Player::REVERSE_COLOR);

        m_window.draw(combinedPlayer);
    }
    else
    {
        m_player.draw(m_window);
        r_player.draw(m_window);
    }
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
