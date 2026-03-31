#pragma once

#include "states/IGameState.hpp"
#include "ui/Components.hpp"
#include <SFML/System/Vector2.hpp>
#include <functional>
#include <memory>

using sf::Vector2f;
namespace Input { class InputHandler; }

namespace UI::Menu
{
    class MainMenu final
    {
    public:
        using TransitionCallback = std::function<void(std::unique_ptr<IGameState>)>;
        MainMenu(TransitionCallback onTransition);
        void subscribeTo(Input::InputHandler& input);
        void unsubscribeTo(Input::InputHandler& input);
        void update(float dt);
        void draw(sf::RenderWindow& window);

    private:
        UI::Components::Label m_title;
        UI::Components::Button m_startButton;
        UI::Components::Button m_settingsButton;
        UI::Components::Button m_quitButton;
    };
}
