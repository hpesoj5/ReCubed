#pragma once

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
