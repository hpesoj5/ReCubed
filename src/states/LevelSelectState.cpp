#include "LevelSelectState.hpp"
#include "input/InputHandler.hpp"

void LevelSelectState::onEnter(Input::InputHandler& input)
{
    input.subscribe(this);
    m_menu.subscribeTo(input);
}

void LevelSelectState::onExit(Input::InputHandler& input)
{
    m_menu.unsubscribeFrom(input);
    input.unsubscribe(this);
}

bool LevelSelectState::onEscapePressed()
{
    m_popState();
    return true;
}
