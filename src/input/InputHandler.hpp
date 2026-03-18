#pragma once

#include "Globals.hpp"
#include "InputObserver.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Input
{
    class InputHandler
    {
    public:
        void subscribe(InputObserver* observer);
        void unsubscribe(InputObserver* observer);
        void handleEvents(sf::RenderWindow& window);

    private:
        void notifyDirection(Globals::Direction dir);
        // more notify function overloads in the future
        std::vector<InputObserver*> m_observers;
    };
}
