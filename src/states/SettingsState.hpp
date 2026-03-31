#pragma once

#include "IGameState.hpp"
#include <functional>
#include <memory>

class SettingsState : public IGameState
{
public:
    using TransitionCallback = std::function<void(std::unique_ptr<IGameState>)>;
    SettingsState(TransitionCallback onTransition) : m_onTransition { onTransition } {}

    void onEnter(Input::InputHandler& /* input */) override {}
    void onExit(Input::InputHandler& /* input */) override {}
    void update(float /* dt */) override {}
    void draw(sf::RenderWindow& /* window */) override {}

private:
    TransitionCallback m_onTransition;
};
