#pragma once

#include "Globals.hpp"
#include "grid/Grid.hpp"
#include "entities/Player.hpp"
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

    void start();

private:
    sf::RenderWindow m_window;

    Grid m_grid;
    Player m_player;
    ReversePlayer r_player;

    Game()
        : m_window { sf::RenderWindow(sf::VideoMode({ Globals::Window::WIDTH, Globals::Window::HEIGHT }), "ReCubed", sf::Style::Close) }
        , m_player { Player{} }
        , r_player { ReversePlayer{} }
    {
        m_window.setVerticalSyncEnabled(true);
    }
};
