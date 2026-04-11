#include "Button.hpp"
#include "Globals.hpp"
#include <string_view>

using sf::Vector2f;

namespace UI::Components
{
    Button::Button(ClickCallback onClick, std::string_view label, const sf::Font& font)
        : Label { label, font }
        , m_onClick { onClick }
        , m_activeFillColor { Globals::Colors::FG }
        , m_inactiveFillColor { Globals::Colors::BG }
        , m_activeTextColor { Globals::Colors::BG }
        , m_inactiveTextColor { Globals::Colors::FG }
        , m_isActive { false }
        , m_isLocked { false }
    {
        setTexture(&Globals::Texture::ATLAS);
        setTextureRect(Globals::Texture::BUTTON);
        setFillColor(sf::Color::White);
    }

    void Button::setActive(bool active)
    {
        if (m_isLocked) return;
        m_isActive = active;

        if (active)
        {
            setTextureRect(Globals::Texture::BUTTON_ACTIVE);
            // setFillColor(m_activeFillColor);
            // setTextFillColor(m_activeTextColor);
        }
        else
        {
            setTextureRect(Globals::Texture::BUTTON);
            // setFillColor(m_inactiveFillColor);
            // setTextFillColor(m_inactiveTextColor);
        }
    }

    void Button::setLocked(bool locked)
    {
        m_isLocked = locked;
        if (locked)
        {
            setActive(false);
            // setOutlineColor(sf::Color(0, 0, 0, 63));
            // setFillColor(sf::Color(255, 255, 255, 191));
        }
        else
        {
            // setOutlineColor(Globals::Colors::BG);
            // setFillColor(Globals::Colors::BG);
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
