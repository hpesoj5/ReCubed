#pragma once

#include "Globals.hpp"

namespace Input
{
    class IInputObserver
    {
    public:
        virtual ~IInputObserver() = default;
        virtual void onDirectionInput(Globals::Direction dir) = 0;
        // more virtual inputActions
    };
}
