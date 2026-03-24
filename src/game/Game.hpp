#pragma once

#include "States.hpp"
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

    void setState(std::unique_ptr<IGameState> state);
    void update(float dt) { m_state->update(dt); }

    void draw() { m_state->draw(m_window); }
    void start();

private:
    sf::RenderWindow m_window;
    Input::InputHandler m_inputHandler;
    std::unique_ptr<IGameState> m_state;

    Game();
};
