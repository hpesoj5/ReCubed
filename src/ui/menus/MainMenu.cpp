#include "MainMenu.hpp"
#include "input/InputHandler.hpp"
#include "states/IGameState.hpp"
#include "states/PlayingState.hpp"
#include "states/SettingsState.hpp"

namespace UI
{
    namespace Menu
    {
        MainMenu::MainMenu(TransitionCallback setState, TransitionCallback pushState, PopStateTransitionCallback popState)
            : m_title { "ReCubed" }
            , m_startButton { [setState, pushState, popState]() { setState(std::make_unique<PlayingState>(1, setState, pushState, popState)); }, "Start" }
            , m_settingsButton { [pushState, popState]() { pushState(std::make_unique<SettingsState>(popState)); }, "Settings" }
            , m_quitButton { [setState](){ setState(nullptr); }, "Quit" }
        {
            m_title.setPosition(Globals::Window::WIDTH / 2.f, 75.f);
            m_title.setTextSize(50);

            m_startButton.setPosition(Globals::Window::WIDTH / 2.f, Globals::Window::HEIGHT - 150.f);
            m_startButton.setOutlineColor(Globals::Colors::FG);
            m_startButton.setOutlineThickness(2.f);
            m_quitButton.setPosition(Globals::Window::WIDTH / 2.f, Globals::Window::HEIGHT - 75.f);
            m_quitButton.setOutlineColor(Globals::Colors::FG);
            m_quitButton.setOutlineThickness(2.f);
        }

        void MainMenu::subscribeTo(Input::InputHandler& input)
        {
            input.subscribe(&m_title);
            input.subscribe(&m_startButton);
            // input.subscribe(&m_settingsButton);
            input.subscribe(&m_quitButton);
        }

        void MainMenu::unsubscribeFrom(Input::InputHandler& input)
        {
            input.unsubscribe(&m_title);
            input.unsubscribe(&m_startButton);
            // input.unsubscribe(&m_settingsButton);
            input.unsubscribe(&m_quitButton);
        }

        void MainMenu::update(float /* dt */)
        {
            // for any animations in the future
            // will call update on each button if they are animating
        }

        void MainMenu::draw(sf::RenderWindow& window)
        {
            m_title.draw(window);
            m_startButton.draw(window);
            m_quitButton.draw(window);
        }
    }
}
