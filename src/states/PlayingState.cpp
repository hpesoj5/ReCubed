#include "PlayingState.hpp"
#include "input/InputHandler.hpp"
#include <SFML/Graphics.hpp>

PlayingState::PlayingState(int level)
    : m_grid { Grid::Grid(9, 9) } // in the future, size will depend on the level
    , m_player { Player{ m_grid } }
    , r_player { ReversePlayer{ m_grid } }
{
    m_player.setPosition(0, 0);
    r_player.setPosition(m_grid.getWidth() - 1, m_grid.getHeight() - 1);

    m_grid.setWall(3, 6);
    m_grid.setGoal(4, 5);
    m_grid.setRGoal(2, 8);
}

void PlayingState::onEnter(Input::InputHandler& input)
{
    input.subscribe(&m_player);
    input.subscribe(&r_player);
}

void PlayingState::onExit(Input::InputHandler& input)
{
    input.unsubscribe(&r_player);
    input.unsubscribe(&m_player);
}

void PlayingState::update(float dt)
{

}

void PlayingState::draw(sf::RenderWindow& window)
{
     m_grid.draw(window);
     if (m_player.getPosition() == r_player.getPosition())
     {
        sf::RectangleShape combinedPlayer(Vector2f(Globals::Player::SIZE, Globals::Player::SIZE));
        combinedPlayer.setOrigin(combinedPlayer.getSize() / 2.f);
        combinedPlayer.setPosition(m_grid.coordsToVector2f(m_player.getPosition()));
        combinedPlayer.setFillColor(Globals::Player::COLOR + Globals::Player::REVERSE_COLOR);

        window.draw(combinedPlayer);
     }
     else
     {
         m_player.draw(window);
         r_player.draw(window);
     }
}
