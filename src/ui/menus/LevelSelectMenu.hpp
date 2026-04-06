#pragma once

#include "states/IGameState.hpp"
#include "ui/Components.hpp"
#include <vector>

namespace UI::Menu
{
    class LevelSelectMenu final
    {
    public:
        LevelSelectMenu(TransitionCallback setState, TransitionCallback pushState, PopStateCallback popState);

        void subscribeTo(Input::InputHandler& input);
        void unsubscribeFrom(Input::InputHandler& input);

        void update(float /* dt */);
        void draw(sf::RenderWindow& window);

    private:
        UI::Components::Label m_title;
        std::vector<UI::Components::Button> m_levelButtons;

        // no page buttons for now
    };
}
