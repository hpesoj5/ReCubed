#include "Globals.hpp"
#include "Game.hpp"
#include "States.hpp"
#include "save/SaveManager.hpp"
#include <iostream>

Game::Game()
    : m_window { sf::RenderWindow(sf::VideoMode({ Globals::Window::WIDTH, Globals::Window::HEIGHT }), "ReCubed", sf::Style::Close) }
    , m_inputHandler { m_window }
{
    m_window.setVerticalSyncEnabled(true);
}

Game::~Game()
{
    if (!m_stateStack.empty()) m_stateStack.back()->onExit(m_inputHandler);
}

void Game::setState(std::unique_ptr<IGameState> state)
{
    bool emptyStack { m_stateStack.empty() };
    if (!emptyStack)
        m_stateStack.back()->onExit(m_inputHandler);

    clearStateStack();
    if (!state)
    {
        m_window.close();
        std::cerr << "Window closed by \"Quit\" button\n";
        return;
    }
    m_stateStack.push_back(std::move(state));
    m_stateStack.back()->onEnter(m_inputHandler);

    if (!emptyStack)
    {
        Vector2f mousePos { sf::Mouse::getPosition(m_window) };
        m_inputHandler.notifyMousePosition(mousePos.x, mousePos.y);
    }
}

void Game::pushState(std::unique_ptr<IGameState> state)
{
    bool emptyStack { m_stateStack.empty() };
    if (!emptyStack)
        m_stateStack.back()->onExit(m_inputHandler);

    if (!state)
    {
        clearStateStack();
        m_window.close();
        std::cerr << "Window closed by \"Quit\" button\n";
        return;
    }

    m_stateStack.push_back(std::move(state));
    m_stateStack.back()->onEnter(m_inputHandler);

    if (!emptyStack)
    {
        Vector2f mousePos { sf::Mouse::getPosition(m_window) };
        m_inputHandler.notifyMousePosition(mousePos.x, mousePos.y);
    }
}

void Game::popState()
{
    if (m_stateStack.empty())
        return;

    m_stateStack.back()->onExit(m_inputHandler);
    m_stateStack.pop_back();

    if (!m_stateStack.empty())
        m_stateStack.back()->onEnter(m_inputHandler);

    else
        throw(std::runtime_error("State stack is empty, no current state to load"));

    Vector2f mousePos { sf::Mouse::getPosition(m_window) };
    m_inputHandler.notifyMousePosition(mousePos.x, mousePos.y);
}

void Game::start()
{
    Globals::Game::highestLevel = Save::SaveManager::load();
    pushState(std::make_unique<MainMenuState>([this](auto next) { setState(std::move(next)); }, [this](auto next) { pushState(std::move(next)); }, [this]() { popState(); }));  // bound to change
    sf::Clock clock;
    while (m_window.isOpen())
    {
        float dt { clock.restart().asSeconds() };
        m_inputHandler.handleEvents(m_window);

        if (!hasState())
        {
            std::cerr << "State stack empty, quitting game...\n";
            return;
        }

        update(dt);

        m_window.clear(Globals::Colors::BG);
        draw();
        m_window.display();
    }
}
