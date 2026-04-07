#include "Button.hpp"
#include <string_view>

using sf::Vector2f;

namespace UI::Components
{
    Button::Button(ClickCallback onClick, std::string_view label, const sf::Font& font)
        : Label { label, font }
        , m_isActive { false }
        , m_isLocked { false }
        , m_onClick { onClick }
    {}

    void Button::setActive(bool active)
    {
        if (m_isLocked) return;
        m_isActive = active;

        if (active)
        {
            setFillColor(Globals::Colors::FG);
            setTextFillColor(Globals::Colors::BG);
        }
        else
        {
            setFillColor(Globals::Colors::BG);
            setTextFillColor(Globals::Colors::FG);
        }
    }

    void Button::setLocked(bool locked)
    {
        m_isLocked = locked;
        if (locked)
        {
            setActive(false);
            setOutlineColor(sf::Color(0, 0, 0, 63));
            setFillColor(sf::Color(255, 255, 255, 191));
        }
        else
        {
            setOutlineColor(Globals::Colors::BG);
            setFillColor(Globals::Colors::BG);
        }
    }

    void Button::onMouseHover(const Vector2f& pos)
    {
        setActive(m_rect.getGlobalBounds().contains(pos));
    }

    bool Button::onMouseClick(const Vector2f& pos)
    {
        setActive(m_rect.getGlobalBounds().contains(pos));
        if (isActive() && !isLocked())
        {
            m_isActive = false;
            m_onClick();
            return true;
        }
        return false;
    }

    void Button::draw(sf::RenderWindow& window)
    {
        if (isLocked())
        {
            window.draw(m_label);
            window.draw(m_rect);
        }
        else Label::draw(window);
    }
}
