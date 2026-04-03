#pragma once

#include "IGameState.hpp"

class SettingsState : public IGameState
{
public:
    SettingsState(PopStateCallback /* onExitMenu */) {}

    void onEnter(Input::InputHandler& /* input */) override {}
    void onExit(Input::InputHandler& /* input */) override {}
    void update(float /* dt */) override {}
    void draw(sf::RenderWindow& /* window */) override {}

private:
};
