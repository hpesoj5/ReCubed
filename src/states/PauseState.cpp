#include "PauseState.hpp"
#include "input/InputHandler.hpp"
#include "states/IGameState.hpp"

PauseState::PauseState(TransitionCallback setState, TransitionCallback pushState, PopStateCallback popState)
    : m_menu { setState, pushState, popState }
    , m_popState { popState }
{}

void PauseState::onEnter(Input::InputHandler& input)
{
    input.subscribe(this);
    m_menu.subscribeTo(input);
}

void PauseState::onExit(Input::InputHandler& input)
{
    m_menu.unsubscribeFrom(input);
    input.unsubscribe(this);
}

bool PauseState::onEscapePressed()
{
    m_popState();
    return true;
}
