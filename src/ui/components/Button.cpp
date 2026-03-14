#include "Button.hpp"
#include "Globals.hpp"
#include <string>
#include <string_view>

namespace UI::Components
{
    Button::Button(std::string_view label, const sf::Font& font)
        : m_rect { sf::RectangleShape{} }
        , m_label { sf::Text{ static_cast<std::string>(label), font, Globals::DEFAULT_TEXT_SIZE } }
    {}

    Button::Button(const Vector2f& size, const Vector2f& pos, std::string_view label, const sf::Font& font)
        : m_rect { sf::RectangleShape(size) }
        , m_label { sf::Text{ static_cast<std::string>(label), font, Globals::DEFAULT_TEXT_SIZE } }
    {
        m_rect.setOrigin(size / 2.f);
        m_rect.setPosition(pos);

        centerText(m_label);
        m_label.setPosition(pos);
    }

    void Button::draw()
    {

    }
}
