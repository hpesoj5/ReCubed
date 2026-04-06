#include "Globals.hpp"
#include "LevelSelectMenu.hpp"
#include "States.hpp"
#include "input/InputHandler.hpp"
#include <SFML/Graphics.hpp>

namespace UI
{
    namespace Menu
    {
        LevelSelectMenu::LevelSelectMenu(TransitionCallback setState, TransitionCallback pushState, PopStateCallback popState)
            : m_title { "Select Level" }
            , m_lastMousePos {}
            , m_selectedIndex { 0 }
            , m_active { false }
        {
            m_title.setPosition(Globals::Text::TITLE_POSITION);
            m_title.setTextSize(Globals::Text::TITLE_SIZE);

            m_levelButtons.reserve(Globals::Game::NUM_LEVELS);
            for (int i { 1 }; i <= Globals::Game::NUM_LEVELS; ++i)
            {
                m_levelButtons.emplace_back(
                    [=]() {
                        setState(std::make_unique<PlayingState>(i, setState, pushState, popState));
                    }, std::to_string(i));
            }

            // decide where to place the buttons

            int cnt {};
            Vector2f pos { Globals::Buttons::TOP_LEFT_POS };
            for (auto& button : m_levelButtons)
            {
                button.setSize(Globals::Buttons::SIZE);
                button.setOutlineColor(Globals::Colors::FG);
                button.setOutlineThickness(2.f);
                button.setPosition(pos);
                button.centerText();

                if (++cnt % Globals::Buttons::NUM_COLUMNS == 0)
                    pos = { Globals::Buttons::TOP_LEFT_POS.x, pos.y + Globals::Buttons::SIZE.y + Globals::Buttons::GAP.y };
                else pos.x += Globals::Buttons::SIZE.x + Globals::Buttons::GAP.x;
            }
        }

        void LevelSelectMenu::subscribeTo(Input::InputHandler& input)
        {
            input.subscribe(this);
            for (auto& button : m_levelButtons)
                input.subscribe(&button);
        }

        void LevelSelectMenu::unsubscribeFrom(Input::InputHandler& input)
        {
            // no std::views::reverse because C++17
            for (auto it { m_levelButtons.rbegin() }; it != m_levelButtons.rend(); ++it)
                input.unsubscribe(&(*it));
            input.unsubscribe(this);
        }

        void LevelSelectMenu::update(float /* dt */)
        {

        }

        using Globals::Game::NUM_LEVELS;
        using Globals::Buttons::NUM_COLUMNS;
        void LevelSelectMenu::onDirectionInput(Globals::Direction dir)
        {
            if (m_active)
            {
                switch (dir)
                {
                case Globals::Direction::Up:
                    m_selectedIndex -= NUM_COLUMNS;
                    if (m_selectedIndex < 0)
                    {
                        int lastRowStart = ((NUM_LEVELS - 1) / NUM_COLUMNS) * NUM_COLUMNS;
                        m_selectedIndex = lastRowStart + m_selectedIndex + NUM_COLUMNS;
                        while (m_selectedIndex >= NUM_LEVELS)
                            m_selectedIndex -= NUM_COLUMNS;
                    }
                    break;
                case Globals::Direction::Down:
                    m_selectedIndex += NUM_COLUMNS;
                    if (m_selectedIndex >= NUM_LEVELS)
                        m_selectedIndex %= NUM_COLUMNS;
                    break;
                case Globals::Direction::Left:
                    m_selectedIndex = (m_selectedIndex + NUM_LEVELS - 1) % NUM_LEVELS;
                    break;
                case Globals::Direction::Right:
                    m_selectedIndex = (m_selectedIndex + 1) % NUM_LEVELS;
                    break;
                }
            }
            m_active = true;
            for (int i {}; i < NUM_LEVELS; ++i)
            {
                if (i == m_selectedIndex) m_levelButtons[i].setActive(true);
                else m_levelButtons[i].setActive(false);
            }
        }

        void LevelSelectMenu::draw(sf::RenderWindow& window)
        {
            m_title.draw(window);
            for (auto& button : m_levelButtons)
                button.draw(window);
        }

        void LevelSelectMenu::onMouseHover(const Vector2f& pos)
        {
            if (pos != m_lastMousePos)
            {
                m_active = false;
                m_selectedIndex = 0;
                m_lastMousePos = pos;
            }
        }

        bool LevelSelectMenu::onConfirm()
        {
            if (m_active)
                m_levelButtons[m_selectedIndex].runCallback();

            return m_active;
        }
    }
}
