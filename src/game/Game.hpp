#pragma once

#include "states/IGameState.hpp"
#include "input/InputHandler.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class Game
{
public:
    static Game& getGame() { static Game game; return game; }

    Game(const Game& other) = delete;
    Game(Game&& other) = delete;
    Game& operator=(const Game& other) = delete;
    Game& operator=(Game&& other) = delete;
    ~Game();

    bool hasState() const { return !m_stateStack.empty(); }
    void setState(std::unique_ptr<IGameState> state);
    void pushState(std::unique_ptr<IGameState> state);
    void popState();
    void clearStateStack() { m_stateStack.clear(); }
    void update(float dt) { m_stateStack.back()->update(dt); }

    void draw() { m_stateStack.back()->draw(m_window); }
    void start();


private:
    sf::RenderWindow m_window;
    Input::InputHandler m_inputHandler;
    std::vector<std::unique_ptr<IGameState>> m_stateStack;

    Game();
};
