#pragma once

#include <functional>
#include <memory>

namespace Input { class InputHandler; }
namespace sf { class RenderWindow; }

class IGameState
{
public:
    virtual ~IGameState() = default;
    virtual void onEnter(Input::InputHandler& input) = 0;
    virtual void onExit(Input::InputHandler& input) = 0;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

using TransitionCallback = std::function<void(std::unique_ptr<IGameState>)>;
using PopStateTransitionCallback = std::function<void()>;
