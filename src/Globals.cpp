#include "Globals.hpp"
#include <cmath>

sf::Vector2f round(const sf::Vector2f& vector)
{
    return sf::Vector2f{ std::round(vector.x), std::round(vector.y) };
}

// void centerText(sf::Text& text)
// {
//     auto textCenter { text.getGlobalBounds().getSize() / 2.f };
//     auto localBounds { textCenter + text.getLocalBounds().getPosition() };
//     auto rounded { round(localBounds) };
//     text.setOrigin(rounded);
// }
