#include "Globals.hpp"
#include "States.hpp"
#include "input/InputHandler.hpp"
#include "levels/LevelBuilder.hpp"
#include "levels/LevelParser.hpp"
#include "states/IGameState.hpp"
#include "states/PauseState.hpp"
#include "save/SaveManager.hpp"
#include <SFML/Graphics.hpp>
#include <functional>

using sf::Vector2f;
using sf::Vector2i;

PlayingState::PlayingState(TransitionCallback setState, TransitionCallback pushState, PopStateCallback popState, int level)
    : m_grid { Grid::Grid{} } // in the future, size will depend on the level
    , m_player { Player{ m_grid } }
    , r_player { ReversePlayer{ m_grid } }
    , m_pauseButton { {}, "||" }
    , m_setState { setState }
    , m_pushState { pushState }
    , m_popState { popState }
    , m_level { level }
{
    std::string path { "src/levels/level_" + std::to_string(level) + ".dat" };
    Levels::LevelData data { Levels::LevelParser::parse(path) };

    m_grid = Grid::Grid(data.width, data.height, data.tiles);
    m_player.resetGoal();
    r_player.resetGoal(); m_player.setStartPosition(data.playerStart);
    r_player.setStartPosition(data.rPlayerStart);
    m_player.setPosition(data.playerStart);
    r_player.setPosition(data.rPlayerStart);
    m_player.setTargetPosition(data.playerStart);
    r_player.setTargetPosition(data.rPlayerStart);

    m_pauseButton.setSize(35.f, 35.f);
    m_pauseButton.setPosition(25.f, 25.f);
    // m_pauseButton.setFillColor(Globals::Colors::BG);
    m_pauseButton.setInactiveFillColor(Globals::Colors::BG);
    m_pauseButton.setActiveFillColor(Globals::Colors::FG);
    // m_pauseButton.setOutlineColor(Globals::Colors::FG);
    // m_pauseButton.setOutlineThickness(2.f);
    m_pauseButton.setTextFillColor(Globals::Colors::FG);
    m_pauseButton.setActiveTextColor(Globals::Colors::BG);
    m_pauseButton.setInactiveTextColor(Globals::Colors::FG);
    m_pauseButton.setTextStyle(sf::Text::Bold);
    m_pauseButton.setTextSize(15);
}

void PlayingState::onEnter(Input::InputHandler& input)
{
    std::function<void()> callback { [this]() { m_pushState(std::make_unique<PauseState>(m_setState, m_pushState, m_popState, this)); } };
    m_pauseButton.setCallback(callback);
    input.subscribe(this);
    input.subscribe(&m_player);
    input.subscribe(&r_player);
    input.subscribe(&m_pauseButton);
}

void PlayingState::onExit(Input::InputHandler& input)
{
    input.unsubscribe(&m_pauseButton);
    input.unsubscribe(&r_player);
    input.unsubscribe(&m_player);
    input.unsubscribe(this);
}

void PlayingState::update(float dt)
{
    m_player.update(dt);
    r_player.update(dt);

    if (!m_player.isAnimating() && !r_player.isAnimating() && m_player.isAtGoal() && r_player.isAtGoal())
    {
        Save::SaveManager::save(m_level);
        Globals::Game::highestLevel = Save::SaveManager::load();
        if (++m_level > Globals::Game::NUM_LEVELS)
            m_setState(std::make_unique<MainMenuState>(m_setState, m_pushState, m_popState));
        else
        {
            // unlock the corresponding level select button by logging it (persists after program exits as well
            m_setState(std::make_unique<PlayingState>(m_setState, m_pushState, m_popState, m_level));
        }
    }
}

void PlayingState::draw(sf::RenderWindow& window)
{
     m_grid.draw(window);
     if (m_player.getGlobalPosition() == r_player.getGlobalPosition())
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

     m_pauseButton.draw(window);
}

bool PlayingState::onEscapePressed()
{
    m_pushState(std::make_unique<PauseState>(m_setState, m_pushState, m_popState, this));
    return true;
}
