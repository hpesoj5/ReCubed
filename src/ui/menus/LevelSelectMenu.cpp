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
            for (auto& button : m_levelButtons)
                input.subscribe(&button);
        }

        void LevelSelectMenu::unsubscribeFrom(Input::InputHandler& input)
        {
            // no std::views::reverse because C++17
            for (auto it { m_levelButtons.rbegin() }; it != m_levelButtons.rend(); ++it)
                input.unsubscribe(&(*it));
        }

        void LevelSelectMenu::update(float /* dt */)
        {

        }

        void LevelSelectMenu::draw(sf::RenderWindow& window)
        {
            m_title.draw(window);
            for (auto& button : m_levelButtons)
                button.draw(window);
        }
    }
}
