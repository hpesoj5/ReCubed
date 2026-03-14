#pragma once

#include "Globals.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

namespace UI::Components
{
    using sf::Vector2f;

    class Button
    {
    public:
        Button(std::string_view label="", const sf::Font& font=Globals::Text::DEFAULT_FONT);
        Button(const Vector2f& size, const Vector2f& pos, std::string_view label="", const sf::Font& font=Globals::Text::DEFAULT_FONT);

        // taken from sf::ReactangleShape, likely won't change
        inline const Vector2f& getSize() { return m_rect.getSize(); }
        inline const sf::Color& getFillColor() const { return m_rect.getFillColor(); }
        inline const sf::Color& getOutlineColor() const { return m_rect.getOutlineColor(); }
        inline float getOutlineThickness() const { return m_rect.getOutlineThickness(); }
        inline const Vector2f& getPosition() const { return m_rect.getPosition(); }

        inline void setSize(const Vector2f& size)
        {
            m_rect.setSize(size);
            m_rect.setOrigin(m_rect.getSize() / 2.f);
        }
        inline void setTexture(const sf::Texture *texture, bool resetRect=false) { m_rect.setTexture(texture, resetRect); }
        inline void setTextureRect(const sf::IntRect &rect) { m_rect.setTextureRect(rect); }
        inline void setFillColor(const sf::Color& color) { m_rect.setFillColor(color); }
        inline void setOutlineColor(const sf::Color& color) { m_rect.setOutlineColor(color); }
        inline void setOutlineThickness(float thickness) { m_rect.setOutlineThickness(thickness); }
        inline void setPosition(float x, float y) { m_rect.setPosition(x, y); }
        inline void setPosition(const Vector2f& pos) { m_rect.setPosition(pos); }

        void draw();

    private:
        sf::RectangleShape m_rect;
        sf::Text m_label;
    };
}
