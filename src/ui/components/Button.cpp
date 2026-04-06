#include "Button.hpp"
#include <string_view>

using sf::Vector2f;

namespace UI::Components
{
    Button::Button(ClickCallback onClick, std::string_view label, const sf::Font& font)
        : Label { label, font }
        , m_isActive { false }
        , m_onClick { onClick }
    {}

    void Button::setActive(bool active)
    {
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

    void Button::onMouseHover(const Vector2f& pos)
    {
        setActive(m_rect.getGlobalBounds().contains(pos));
    }

    bool Button::onMouseClick(const Vector2f& pos)
    {
        setActive(m_rect.getGlobalBounds().contains(pos));
        if (isActive())
        {
            m_isActive = false;
            m_onClick();
            return true;
        }
        return false;
    }
}
