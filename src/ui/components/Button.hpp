#pragma once

#include "Globals.hpp"
#include "Label.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <functional>

namespace UI::Components
{
    using sf::Vector2f;

    class Button final : public Label
    {
    public:
        using ClickCallback = std::function<void()>;
        Button(ClickCallback onClick, std::string_view label="", const sf::Font& font=Globals::Text::DEFAULT_FONT);

        void onMouseHover(const Vector2f& pos) override;
        bool onMouseClick() override;

        bool isActive() const { return m_isActive; }

        void setCallback(ClickCallback onClick) { m_onClick = onClick; }

    private:
        bool m_isActive;
        ClickCallback m_onClick;
    };
}
