#include "Globals.hpp"

sf::Vector2f round(const sf::Vector2f& vector)
{
    return sf::Vector2f{ std::round(vector.x), std::round(vector.y) };
}

void Globals::Window::centerText(sf::Text& text)
{
    auto textCenter { text.getGlobalBounds().getSize() / 2.f };
    auto localBounds { textCenter + text.getLocalBounds().getPosition() };
    auto rounded { round(localBounds) };
    text.setOrigin(rounded);
}

sf::Vector2f Globals::Animations::lerp(const sf::Vector2f& a, const sf::Vector2f& b, float t)
{
    return a + (b - a) * t;
}

float Globals::Animations::easeInOut(float t)
{
    return t < 0.5f ? 2.f * t * t : 1.f - std::pow(-2.f * t + 2.f, 2.f) / 2.f;
}
