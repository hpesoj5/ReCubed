#pragma once

#include "Globals.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <functional>

namespace UI::Components
{
    using sf::Vector2f;

    class Label
    {
    public:
        using HoverCallback = std::function<void(const Vector2f& pos)>;
        Label(std::string_view label="Default Label", const sf::Font& font=Globals::Text::DEFAULT_FONT);
        // taken from sf::ReactangleShape, likely won't change
        // const Vector2f& getSize() { return m_rect.getSize(); }
        // const sf::Color& getTextFillColor() const { return m_label.getFillColor(); }
        // const sf::Color& getTextOutlineColor() const { return m_label.getOutlineColor(); }
        // float getTextOutlineThickness() const { return m_label.getOutlineThickness(); }
        // const sf::Color& getFillColor() const { return m_rect.getFillColor(); }
        // const sf::Color& getOutlineColor() const { return m_rect.getOutlineColor(); }
        // float getOutlineThickness() const { return m_rect.getOutlineThickness(); }
        // const Vector2f& getPosition() const { return m_rect.getPosition(); }

        void setSize(const Vector2f& size)
        {
            m_rect.setSize(size);
            m_rect.setOrigin(m_rect.getSize() / 2.f);
        }
        void setSize(float x, float y) { setSize(Vector2f(x, y)); }
        void setTexture(const sf::Texture *texture, bool resetRect=false) { m_rect.setTexture(texture, resetRect); }
        void setTextureRect(const sf::IntRect &rect) { m_rect.setTextureRect(rect); }
        void setTextStyle(sf::Text::Style style) { m_label.setStyle(style); }
        void setTextFont(const sf::Font& font) { m_label.setFont(font); centerText(); }
        void setTextSize(unsigned int size) { m_label.setCharacterSize(size); centerText(); }
        void setTextFillColor(const sf::Color& color) { m_label.setFillColor(color); }
        void setTextOutlineColor(const sf::Color& color) { m_label.setOutlineColor(color); }
        void setTextOutlineThickness(float thickness) { m_label.setOutlineThickness(thickness); }
        void setFillColor(const sf::Color& color) { m_rect.setFillColor(color); }
        void setOutlineColor(const sf::Color& color) { m_rect.setOutlineColor(color); }
        void setOutlineThickness(float thickness) { m_rect.setOutlineThickness(thickness); }
        void setPosition(float x, float y) { m_rect.setPosition(x, y); m_label.setPosition(x, y); }
        void setPosition(const Vector2f& pos) { m_rect.setPosition(pos); m_label.setPosition(pos); }

        void centerText();
        virtual void draw(sf::RenderWindow& window);

    protected:
        sf::RectangleShape m_rect;
        sf::Text m_label;
    };
}
