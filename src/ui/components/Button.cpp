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

    void Button::onMouseHover(const Vector2f& pos)
    {
        if (m_rect.getGlobalBounds().contains(pos))
        {
            setFillColor(Globals::Colors::FG);
            setTextFillColor(Globals::Colors::BG);
            m_isActive = true;
        }
        else
        {
            setFillColor(Globals::Colors::BG);
            setTextFillColor(Globals::Colors::FG);
            m_isActive = false;
        }
    }

    void Button::onMouseClick()
    {
        if (isActive()) m_onClick();
    }
}
