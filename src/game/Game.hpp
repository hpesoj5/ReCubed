#pragma once

#include "Globals.hpp"
#include "grid/Grid.hpp"
#include "entities/Player.hpp"
#include "input/InputHandler.hpp"
// #include "UI.hpp"
#include <SFML/Graphics.hpp>

class Game
{
public:
    static Game& getGame() { static Game game; return game; }

    Game(const Game& other) = delete;
    Game(Game&& other) = delete;
    Game& operator=(const Game& other) = delete;
    Game& operator=(Game&& other) = delete;
    ~Game();

    void draw();
    void start();

private:
    sf::RenderWindow m_window;
    Input::InputHandler m_inputHandler;

    Grid m_grid;
    Player m_player;
    ReversePlayer r_player;

    Game();
};
