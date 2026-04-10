#include "Globals.hpp"
#include <cmath>
#include <iostream>

sf::Vector2f round(const sf::Vector2f& vector)
{
    return sf::Vector2f{ std::round(vector.x), std::round(vector.y) };
}

namespace Globals
{
    namespace Animations
    {
        float PLAYER_DURATION { 0.1f };
    }

    namespace LevelButtons
    {
        const sf::Vector2f SIZE { SIZE_1D, SIZE_1D };
        const sf::Vector2f GAP { GAP_1D, GAP_1D };
        const sf::Vector2f TOP_LEFT_POS { (static_cast<float>(Window::WIDTH) - TOTAL_WIDTH + SIZE_1D) / 2.f, 200.f };
    }

    namespace Colors
    {
        const sf::Color BG { 255, 255, 255 };
        const sf::Color FG { 0, 0, 0 };
        const sf::Color GRID_LINE { 0, 0, 0, 63 };

        const sf::Color WALL { 0, 0, 0 };
        const sf::Color EMPTY { sf::Color::Transparent };
        const sf::Color PLAYER { 0, 0, 255 };
        const sf::Color RPLAYER { 255, 0, 0 };
        const sf::Color PLAYER_OUTLINE { 0, 0, 0 };
        const sf::Color GOAL { 0, 0, 255, 63 };
        const sf::Color RGOAL { 255, 0, 0, 63 };
    }

    namespace Text
    {
        sf::Font DEFAULT_FONT;
        sf::Font DEFAULT_FONT_ITALIC;
    }

    namespace Texture
    {
        sf::Texture ATLAS;
    }

    namespace UI
    {
        const sf::Vector2f TITLE_POSITION { Globals::Window::WIDTH / 2.f, 85.f };
        const sf::Vector2f LABEL_SIZE { 175, 50 };
    }

    void Window::centerText(sf::Text& text)
    {
        auto textCenter { text.getGlobalBounds().getSize() / 2.f };
        auto localBounds { textCenter + text.getLocalBounds().getPosition() };
        auto rounded { round(localBounds) };
        text.setOrigin(rounded);
    }

    sf::Vector2f Animations::lerp(const sf::Vector2f& a, const sf::Vector2f& b, float t)
    {
        return a + (b - a) * t;
    }

    float Animations::easeInOut(float t)
    {
        return t < 0.5f ? 2.f * t * t : 1.f - std::pow(-2.f * t + 2.f, 2.f) / 2.f;
    }

    void Text::loadFont(sf::Font& font, const std::string& filepath)
    {
        if (!font.loadFromFile(filepath))
        {
            std::cerr << "Couldn't load font from " << filepath << '\n';
        }
    }

    void Text::loadFonts()
    {
        Globals::Text::loadFont(Globals::Text::DEFAULT_FONT, "src/assets/OpenSans.ttf");
        Globals::Text::loadFont(Globals::Text::DEFAULT_FONT_ITALIC, "src/assets/OpenSansItalic.ttf");
    }

    void Texture::loadTexture()
    {
        auto filepath { "src/assets/1-Bit/Tileset/tilest-table-8-8.png" };
        if (!ATLAS.loadFromFile(filepath))
        {
            std::cerr << "Couldn't load texture from " << filepath << '\n';
        }
    }
}
