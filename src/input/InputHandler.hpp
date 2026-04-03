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
        ObserverList getObserverListCopy() const { return m_observers; }
        void subscribe(IInputObserver* observer);
        void unsubscribe(IInputObserver* observer);
        void handleEvents(sf::RenderWindow& window);

        void notifyDirection(const ObserverList& observers, Globals::Direction dir);
        void notifyResetPosition(const ObserverList& observers);
        void notifyMousePosition(const ObserverList& observers, float x, float y);
        void notifyMouseClick(const ObserverList& observers);
        void notifyEscapePressed(const ObserverList& observers);

    private:
        // more notify function overloads in the future
        ObserverList m_observers;
    };
}
