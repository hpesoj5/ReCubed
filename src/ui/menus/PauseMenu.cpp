#include "PauseMenu.hpp"
#include "input/InputHandler.hpp"
#include "states/IGameState.hpp"
#include "states/MainMenuState.hpp"
#include "states/SettingsState.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

namespace UI
{
    namespace Menu
    {
        PauseMenu::PauseMenu(TransitionCallback setState, TransitionCallback pushState, PopStateCallback popState)
            : m_pausedTitle { "PAUSED" }
            , m_pauseButton { popState, "||" }
            , m_resumeButton { popState, "Resume" }
            , m_settingsButton { [pushState, popState]() { pushState(std::make_unique<SettingsState>(popState)); }, "Settings" }
            , m_quitButton { [setState, pushState, popState]() { setState(std::make_unique<MainMenuState>(setState, pushState, popState)); }, "Quit" }
        {
            m_pausedTitle.setPosition(Globals::Window::WIDTH / 2.f, 75.f);
            m_pausedTitle.setTextSize(50);

            m_pauseButton.setSize(25.f, 25.f);
            m_pauseButton.setPosition(20.f, 20.f);
            m_pauseButton.setOutlineColor(Globals::Colors::FG);
            m_pauseButton.setOutlineThickness(2.f);
            m_pauseButton.setTextFillColor(Globals::Colors::FG);
            m_pauseButton.setTextStyle(sf::Text::Bold);
            m_pauseButton.setTextSize(15);

            m_resumeButton.setPosition(Globals::Window::WIDTH / 2.f, Globals::Window::HEIGHT - 150.f);
            m_resumeButton.setOutlineColor(Globals::Colors::FG);
            m_resumeButton.setOutlineThickness(2.f);
            m_quitButton.setPosition(Globals::Window::WIDTH / 2.f, Globals::Window::HEIGHT - 75.f);
            m_quitButton.setOutlineColor(Globals::Colors::FG);
            m_quitButton.setOutlineThickness(2.f);
        }

        void PauseMenu::subscribeTo(Input::InputHandler& input)
        {
            input.subscribe(&m_pauseButton);
            input.subscribe(&m_resumeButton);
            // input.subscribe(&m_settingsButton);
            input.subscribe(&m_quitButton);
        }

        void PauseMenu::unsubscribeFrom(Input::InputHandler& input)
        {
            input.unsubscribe(&m_quitButton);
            // input.unsubscribe(&m_settingsButton);
            input.unsubscribe(&m_resumeButton);
            input.unsubscribe(&m_pauseButton);
        }

        void PauseMenu::update(float /* dt */)
        {
            // for animations in the future
        }

        void PauseMenu::draw(sf::RenderWindow& window)
        {
            m_pausedTitle.draw(window);
            m_resumeButton.draw(window);
            // m_settingsButton.draw(window);
            m_quitButton.draw(window);
            m_pauseButton.draw(window);
        }
    }
}
