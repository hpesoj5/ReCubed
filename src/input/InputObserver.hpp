#pragma once

#include "Globals.hpp"

namespace Input
{
    class InputObserver
    {
    public:
        virtual ~InputObserver() = default;
        virtual void onDirectionInput(Globals::Direction dir) = 0;
        // more virtual inputActions
    };
}
