#pragma once

#include "Globals.hpp"

namespace Input
{
    class IInputObserver
    {
    public:
        virtual ~IInputObserver() = default;
        virtual void onDirectionInput(Globals::Direction dir) {}
        virtual void resetPosition() {}
        // more virtual inputActions
    };
}
