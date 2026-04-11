#include "Globals.hpp"
#include "Label.hpp"
#include <string>
#include <string_view>

using sf::Vector2f;

namespace UI::Components
{
    Label::Label(std::string_view label, const sf::Font& font)
        : m_rect { sf::RectangleShape{ Globals::UI::LABEL_SIZE } }
        , m_label { sf::Text{ static_cast<std::string>(label), font, Globals::Text::DEFAULT_SIZE } }
    {
        m_rect.setOrigin(m_rect.getSize() / 2.f);
        m_rect.setFillColor(sf::Color::Transparent);
        m_label.setFillColor(Globals::Colors::FG);
        // m_rect.setOutlineColor(Globals::Colors::FG);
        // m_rect.setOutlineThickness(2.f);
        centerText();
    }

    void Label::centerText()
    {
        auto textCenter { m_label.getGlobalBounds().getSize() / 2.f };
        auto localBounds { textCenter + m_label.getLocalBounds().getPosition() };
        auto rounded { round(localBounds) };
        m_label.setOrigin(rounded);
        m_label.setPosition(m_rect.getPosition());
    }

    void Label::draw(sf::RenderWindow& window)
    {
        window.draw(m_rect);
        window.draw(m_label);
    }
}
