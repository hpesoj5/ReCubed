#include "PlayingState.hpp"
#include "input/InputHandler.hpp"
#include "levels/LevelBuilder.hpp"
#include "levels/LevelParser.hpp"
#include <SFML/Graphics.hpp>

using sf::Vector2f;
using sf::Vector2i;

PlayingState::PlayingState(int level, TransitionCallback onTransition)
    : m_grid { Grid::Grid{} } // in the future, size will depend on the level
    , m_level { level }
    , m_player { Player{ m_grid } }
    , r_player { ReversePlayer{ m_grid } }
    , m_onTransition { onTransition }
{
    std::string path { "src/levels/level_" + std::to_string(level) + ".data" };
    Levels::LevelData data { Levels::LevelParser::parse(path) };

    m_grid = Grid::Grid(data.width, data.height, data.tiles);
    m_player.resetGoal();
    r_player.resetGoal();
    m_player.setStartPosition(data.playerStart);
    r_player.setStartPosition(data.rPlayerStart);
    m_player.setPosition(data.playerStart);
    r_player.setPosition(data.rPlayerStart);

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
    if (m_player.isAtGoal() && r_player.isAtGoal())
        m_onTransition(std::make_unique<PlayingState>(Globals::Game::nextLevel(m_level), m_onTransition));
}

void PlayingState::draw(sf::RenderWindow& window)
{
     m_grid.draw(window);
     if (m_player.getPosition() == r_player.getPosition())
     {
        sf::RectangleShape combinedPlayer(Vector2f(Globals::Player::SIZE, Globals::Player::SIZE));
        combinedPlayer.setOrigin(combinedPlayer.getSize() / 2.f);
        combinedPlayer.setPosition(m_grid.coordsToVector2f(m_player.getPosition()));
        combinedPlayer.setFillColor(Globals::Colors::PLAYER + Globals::Colors::RPLAYER);
        combinedPlayer.setOutlineThickness(-2.f);
        combinedPlayer.setOutlineColor(Globals::Colors::PLAYER_OUTLINE);

        window.draw(combinedPlayer);
     }
     else
     {
         m_player.draw(window);
         r_player.draw(window);
     }
}
