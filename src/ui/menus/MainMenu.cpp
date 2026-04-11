#include "MainMenu.hpp"
#include "Globals.hpp"
#include "input/InputHandler.hpp"
#include "states/IGameState.hpp"
#include "States.hpp"

namespace UI
{
    namespace Menu
    {
        using UI::Components::Button;
        MainMenu::MainMenu(TransitionCallback setState, TransitionCallback pushState, PopStateCallback popState)
            : m_setState { setState }
            , m_title { "ReCubed" }
            , m_buttons {
                Button { [setState, pushState, popState]() { pushState(std::make_unique<LevelSelectState>(setState, pushState, popState)); }, "Start" },
                // Button { [pushState, popState]() { pushState(std::make_unique<SettingsState>(popState)); }, "Settings" },
                Button { [](){}, "Settings" },
                Button { [setState](){ setState(nullptr); }, "Quit" }
            }
            , m_startButton { m_buttons[0] }
            , m_settingsButton { m_buttons[1] }
            , m_quitButton { m_buttons[2] }
            , m_lastMousePos {}
            , m_selectedIndex { 0 }
            , m_active { false }
        {
            m_title.setPosition(Globals::UI::TITLE_POSITION);
            m_title.setTextSize(Globals::Text::TITLE_SIZE);

            m_startButton.setPosition(Globals::Window::WIDTH / 2.f, Globals::UI::BUTTON_TOP_YPOS);
            // m_startButton.setOutlineColor(Globals::Colors::FG);
            // m_startButton.setOutlineThickness(2.f);

            m_settingsButton.setPosition(Globals::Window::WIDTH / 2.f, Globals::UI::BUTTON_TOP_YPOS + Globals::UI::BUTTON_VERTICAL_GAP);
            // m_settingsButton.setOutlineColor(Globals::Colors::FG);
            // m_settingsButton.setOutlineThickness(2.f);

            m_quitButton.setPosition(Globals::Window::WIDTH / 2.f, Globals::UI::BUTTON_TOP_YPOS + 2 * Globals::UI::BUTTON_VERTICAL_GAP);
            // m_quitButton.setOutlineColor(Globals::Colors::FG);
            // m_quitButton.setOutlineThickness(2.f);
        }

        void MainMenu::subscribeTo(Input::InputHandler& input)
        {
            input.subscribe(this);
            for (auto& button : m_buttons)
                input.subscribe(&button);
        }

        void MainMenu::unsubscribeFrom(Input::InputHandler& input)
        {
            for (auto it { m_buttons.rbegin() }; it != m_buttons.rend(); ++it)
                input.unsubscribe(&(*it));
            input.unsubscribe(this);
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
            m_settingsButton.draw(window);
            m_quitButton.draw(window);
        }

        void MainMenu::onDirectionInput(Globals::Direction dir)
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

        void MainMenu::onMouseHover(const Vector2f& pos)
        {
            if (pos != m_lastMousePos)
            {
                m_active = false;
                m_selectedIndex = 0;
                m_lastMousePos = pos;
            }
        }

        bool MainMenu::onEscapePressed()
        {
            m_setState(nullptr);
            return true;
        }

        bool MainMenu::onConfirm()
        {
            if (m_active)
                m_buttons[m_selectedIndex].runCallback();

            return m_active;
        }
    }
}
