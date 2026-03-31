#include "MainMenu.hpp"
#include "input/InputHandler.hpp"
#include "states/IGameState.hpp"
#include "states/PlayingState.hpp"
#include "states/SettingsState.hpp"

namespace UI
{
    namespace Menu
    {
        MainMenu::MainMenu(TransitionCallback onTransition)
            : m_title { "ReCubed" }
            , m_startButton { [onTransition]() { onTransition(std::make_unique<PlayingState>(1, onTransition)); }, "Start" }
            , m_settingsButton { [onTransition]() { onTransition(std::make_unique<SettingsState>(onTransition)); }, "Settings" }
            , m_quitButton { [onTransition](){ onTransition(nullptr); }, "Quit" }
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
            input.subscribe(&m_quitButton);
        }

        void MainMenu::unsubscribeTo(Input::InputHandler& input)
        {
            input.unsubscribe(&m_title);
            input.unsubscribe(&m_startButton);
            input.unsubscribe(&m_quitButton);
        }

        void MainMenu::update(float dt)
        {

        }

        void MainMenu::draw(sf::RenderWindow& window)
        {
            m_title.draw(window);
            m_startButton.draw(window);
            m_quitButton.draw(window);
        }
    }
}
