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
        using UI::Components::Button;
        PauseMenu::PauseMenu(TransitionCallback setState, TransitionCallback pushState, PopStateCallback popState)
            : m_pausedTitle { "PAUSED" }
            , m_pauseButton { popState, "||" }
            , m_buttons {
                Button { popState, "Resume" },
                // Button { [pushState, popState]() { pushState(std::make_unique<SettingsState>(popState)); }, "Settings" },
                Button { [](){}, "Settings" },
                Button { [setState, pushState, popState]() { setState(std::make_unique<MainMenuState>(setState, pushState, popState)); }, "Quit" }
            }
            , m_resumeButton { m_buttons[0] }
            , m_settingsButton { m_buttons[1] }
            , m_quitButton { m_buttons[2] }
            , m_overlay { Vector2f(Globals::Window::WIDTH, Globals::Window::HEIGHT) }
            , m_lastMousePos {}
            , m_selectedIndex { 0 }
            , m_active { false }
        {
            m_pausedTitle.setPosition(Globals::UI::TITLE_POSITION);
            m_pausedTitle.setFillColor(sf::Color::Transparent);
            m_pausedTitle.setTextSize(Globals::Text::TITLE_SIZE);

            m_pauseButton.setSize(25.f, 25.f);
            m_pauseButton.setPosition(20.f, 20.f);
            m_pauseButton.setOutlineColor(Globals::Colors::FG);
            m_pauseButton.setOutlineThickness(2.f);
            m_pauseButton.setTextFillColor(Globals::Colors::FG);
            m_pauseButton.setTextStyle(sf::Text::Bold);
            m_pauseButton.setTextSize(15);

            m_resumeButton.setPosition(Globals::Window::WIDTH / 2.f, Globals::UI::BUTTON_TOP_YPOS);
            m_resumeButton.setOutlineColor(Globals::Colors::FG);
            m_resumeButton.setOutlineThickness(2.f);

            m_settingsButton.setPosition(Globals::Window::WIDTH / 2.f, Globals::UI::BUTTON_TOP_YPOS + Globals::UI::BUTTON_VERTICAL_GAP);
            m_settingsButton.setOutlineColor(Globals::Colors::FG);
            m_settingsButton.setOutlineThickness(2.f);

            m_quitButton.setPosition(Globals::Window::WIDTH / 2.f, Globals::UI::BUTTON_TOP_YPOS + 2 * Globals::UI::BUTTON_VERTICAL_GAP);
            m_quitButton.setOutlineColor(Globals::Colors::FG);
            m_quitButton.setOutlineThickness(2.f);

            m_overlay.setFillColor(sf::Color(255, 255, 255, 191));
        }

        void PauseMenu::subscribeTo(Input::InputHandler& input)
        {
            input.subscribe(this);
            input.subscribe(&m_pauseButton);
            for (auto& button : m_buttons)
                input.subscribe(&button);
        }

        void PauseMenu::unsubscribeFrom(Input::InputHandler& input)
        {
            for (auto it { m_buttons.rbegin() }; it != m_buttons.rend(); ++it)
                input.unsubscribe(&(*it));
            input.unsubscribe(&m_pauseButton);
            input.unsubscribe(this);
        }

        void PauseMenu::update(float /* dt */)
        {
            // for animations in the future
        }

        void PauseMenu::draw(sf::RenderWindow& window)
        {
            window.draw(m_overlay);
            m_pausedTitle.draw(window);
            m_pauseButton.draw(window);
            for (auto& button : m_buttons)
                button.draw(window);
        }

        void PauseMenu::onDirectionInput(Globals::Direction dir)
        {
            auto numButtons { m_buttons.size() };
            if (m_active)
            {
                switch (dir)
                {
                case Globals::Direction::Up:
                    m_selectedIndex = (m_selectedIndex + 2) % numButtons;
                    break;
                case Globals::Direction::Left:
                    m_selectedIndex = (m_selectedIndex + 2) % numButtons;
                    break;
                case Globals::Direction::Down:
                    m_selectedIndex = (m_selectedIndex + 1) % numButtons;
                    break;
                case Globals::Direction::Right:
                    m_selectedIndex = (m_selectedIndex + 1) % numButtons;
                    break;
                }
            }
            m_active = true;
            for (int i {}; i < 3; ++i)
            {
                if (i == m_selectedIndex) m_buttons[i].setActive(true);
                else m_buttons[i].setActive(false);
            }
        }

        void PauseMenu::onMouseHover(const Vector2f& pos)
        {
            if (pos != m_lastMousePos)
            {
                m_active = false;
                m_selectedIndex = 0;
                m_lastMousePos = pos;
            }
        }

        bool PauseMenu::onConfirm()
        {
            if (m_active)
                m_buttons[m_selectedIndex].runCallback();

            return m_active;
        }
    }
}
