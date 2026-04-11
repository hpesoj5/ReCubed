#include "Globals.hpp"
#include "grid/Grid.hpp"
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
        const sf::Color BG { 12, 16, 24 };
        const sf::Color FG { 251, 247, 243 };
        const sf::Color GRID_LINE { 0, 0, 0, 63 };

        const sf::Color WALL { FG };
        const sf::Color EMPTY { sf::Color::Transparent };
        const sf::Color PLAYER { 0, 0, 255 };
        const sf::Color RPLAYER { 255, 0, 0 };
        const sf::Color PLAYER_OUTLINE { FG };
        const sf::Color GOAL { 0, 170, 255 };
        const sf::Color RGOAL { 255, 85, 127 };
    }

    namespace Text
    {
        sf::Font DEFAULT_FONT;
        sf::Font DEFAULT_FONT_ITALIC;
    }

    namespace Texture
    {
        sf::Texture ATLAS;

        // const sf::IntRect EMPTY    { 0 , 80, 16, 16 };
        const sf::IntRect WALL     { 152, 40, 16, 16 };
        const sf::IntRect GOAL     { 152, 8, 24, 24 };
        const sf::IntRect RGOAL    { 152, 8, 24, 24 };
        const sf::IntRect BORDERT  { 96, 40, 8, 8 };
        const sf::IntRect BORDERB  { 128, 24, 8, 8 };
        const sf::IntRect BORDERL  { 120, 16, 8, 8 };
        const sf::IntRect BORDERR  { 136, 16, 8, 8 };
        const sf::IntRect BORDERTL { 88, 40, 8, 8 };
        const sf::IntRect BORDERTR { 104, 40, 8, 8 };
        const sf::IntRect BORDERBL { 120, 24, 8, 8 };
        const sf::IntRect BORDERBR { 136, 24, 8, 8 };

        const sf::IntRect PLAYER { 0, 64, 16, 16 };
        const sf::IntRect RPLAYER { 16, 48, 16, 16 };

        const sf::IntRect BUTTON { 64, 144, 24, 24 };
        const sf::IntRect BUTTON_ACTIVE { 96, 144, 24, 24 };
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

    void Texture::loadTextures()
    {
        auto filepath { "src/assets/Tileset.png" };
        if (!ATLAS.loadFromFile(filepath))
        {
            std::cerr << "Couldn't load texture from " << filepath << '\n';
            return;
        }
    }

    using Grid::Tile::Tile;
    const sf::IntRect* Texture::getTileTextureRect(Tile tile)
    {
        switch (tile)
        {
        case Tile::Empty:    return nullptr;
        case Tile::Wall:     return &WALL;
        case Tile::Goal:     return &GOAL;
        case Tile::RGoal:    return &RGOAL;
        case Tile::BorderT:  return &BORDERT;
        case Tile::BorderB:  return &BORDERB;
        case Tile::BorderL:  return &BORDERL;
        case Tile::BorderR:  return &BORDERR;
        case Tile::BorderTL: return &BORDERTL;
        case Tile::BorderTR: return &BORDERTR;
        case Tile::BorderBL: return &BORDERBL;
        case Tile::BorderBR: return &BORDERBR;
        default: return nullptr;
        }
    }
}
