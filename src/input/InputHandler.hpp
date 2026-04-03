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
        using ObserverList = std::vector<IInputObserver*>;
        void subscribe(IInputObserver* observer);
        void unsubscribe(IInputObserver* observer);
        void handleEvents(sf::RenderWindow& window);

        void notifyDirection(Globals::Direction dir);
        void notifyResetPosition();
        void notifyMousePosition(float x, float y);
        void notifyMouseClick();
        void notifyEscapePressed();

    private:
        // more notify function overloads in the future
        ObserverList m_observers;
    };
}
