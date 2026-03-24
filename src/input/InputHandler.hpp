#pragma once

#include "Globals.hpp"
#include "IInputObserver.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Input
{
    class InputHandler
    {
    public:
        void subscribe(IInputObserver* observer);
        void unsubscribe(IInputObserver* observer);
        void handleEvents(sf::RenderWindow& window);

    private:
        void notifyDirection(Globals::Direction dir);
        // more notify function overloads in the future
        std::vector<IInputObserver*> m_observers;
    };
}
