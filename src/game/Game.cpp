#include "Globals.hpp"
#include "Game.hpp"
#include "States.hpp"

Game::Game()
    : m_window { sf::RenderWindow(sf::VideoMode({ Globals::Window::WIDTH, Globals::Window::HEIGHT }), "ReCubed", sf::Style::Close) }
{
    m_window.setVerticalSyncEnabled(true);
}

Game::~Game()
{
    if (m_state) m_state->onExit(m_inputHandler);
}

void Game::setState(std::unique_ptr<IGameState> state)
{
    if (m_state) m_state->onExit(m_inputHandler);
    m_state = std::move(state);
    m_state->onEnter(m_inputHandler);
}

void Game::start()
{
    setState(std::make_unique<PlayingState>(1, [this](auto next) { setState(std::move(next)); } ));
    sf::Clock clock;
    while (m_window.isOpen())
    {
        float dt { clock.restart().asSeconds() };
        m_inputHandler.handleEvents(m_window);
        update(dt);

        m_window.clear(Globals::Colors::BG);
        draw();
        m_window.display();
    }
}
