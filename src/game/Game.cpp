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
    if (!m_stateStack.empty()) m_stateStack.back()->onExit(m_inputHandler);
}

#include <iostream>
void Game::setState(std::unique_ptr<IGameState> state)
{
    if (!m_stateStack.empty())
        m_stateStack.back()->onExit(m_inputHandler);

    m_stateStack.clear();
    if (!state)
    {
        m_window.close();
        std::cerr << "Window closed by \"Quit\" button\n";
        return;
    }
    m_stateStack.push_back(std::move(state));
    m_stateStack.back()->onEnter(m_inputHandler);
}

void Game::pushState(std::unique_ptr<IGameState> state)
{
    if (!m_stateStack.empty())
        m_stateStack.back()->onExit(m_inputHandler);

    m_stateStack.push_back(std::move(state));
    m_stateStack.back()->onEnter(m_inputHandler);
}

void Game::popState()
{
    if (m_stateStack.empty())
        return;

    m_stateStack.back()->onExit(m_inputHandler);
    m_stateStack.pop_back();

    if (!m_stateStack.empty())
        m_stateStack.back()->onEnter(m_inputHandler);
}

void Game::start()
{
    setState(std::make_unique<MainMenuState>([this](auto next) { setState(std::move(next)); } ));  // bound to change
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
