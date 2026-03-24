#include "Button.hpp"
#include "Globals.hpp"
#include <string>
#include <string_view>

using sf::Vector2f;

namespace UI::Components
{
    Button::Button(std::string_view label, const sf::Font& font)
        : m_rect { sf::RectangleShape{} }
        , m_label { sf::Text{ static_cast<std::string>(label), font, Globals::Text::DEFAULT_SIZE } }
    {}

    Button::Button(const Vector2f& size, const Vector2f& pos, std::string_view label, const sf::Font& font)
        : m_rect { sf::RectangleShape(size) }
        , m_label { sf::Text{ static_cast<std::string>(label), font, Globals::Text::DEFAULT_SIZE } }
    {
        m_rect.setOrigin(size / 2.f);
        m_rect.setPosition(pos);

        centerLabel();
        m_label.setPosition(pos);
    }

    void Button::centerLabel()
    {
        auto textCenter { m_label.getGlobalBounds().getSize() / 2.f };
        auto localBounds { textCenter + m_label.getLocalBounds().getPosition() };
        auto rounded { round(localBounds) };
        m_label.setOrigin(rounded);
    }

    void Button::draw()
    {

    }
}
