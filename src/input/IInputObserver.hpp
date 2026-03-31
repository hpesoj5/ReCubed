#pragma once

#include "Globals.hpp"
#include <SFML/System/Vector2.hpp>

using sf::Vector2f;

namespace Input
{
    class IInputObserver
    {
    public:
        virtual ~IInputObserver() = default;
        virtual void onDirectionInput(Globals::Direction /* dir */) {}
        virtual void resetPosition() {}
        virtual void onMouseHover(const Vector2f& /* pos */) {}
        virtual void onMouseClick() {}
        // more virtual inputActions
    };
}
