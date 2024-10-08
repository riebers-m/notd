//
// Created by HP on 28.07.2024.
//

#include "SFMLRenderer.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <optional>
#include <spdlog/spdlog.h>

namespace sts {
    struct RGBA {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };

    std::optional<RGBA> convert_to_rgba(Color color) {
        switch (color) {
            case Color::RED:
                return RGBA{255, 0, 0, 255};
            case Color::GREEN:
                return RGBA{0, 255, 0, 255};
            case Color::BLUE:
                return RGBA{0, 0, 255, 255};
            case Color::YELLOW:
                return RGBA{255, 255, 0, 255};
            case Color::ORANGE:
                return RGBA{255, 165, 0, 255};
            case Color::PURPLE:
                return RGBA{128, 0, 128, 255};
            case Color::PINK:
                return RGBA{255, 192, 203, 255};
            case Color::CYAN:
                return RGBA{0, 255, 255, 255};
            case Color::MAGENTA:
                return RGBA{255, 0, 255, 255};
            case Color::LIME:
                return RGBA{0, 255, 0, 255};
            case Color::TEAL:
                return RGBA{0, 128, 128, 255};
            case Color::LAVENDER:
                return RGBA{230, 230, 250, 255};
            case Color::BROWN:
                return RGBA{165, 42, 42, 255};
            case Color::SILVER:
                return RGBA{192, 192, 192, 255};
            case Color::GOLD:
                return RGBA{255, 215, 0, 255};
            case Color::NAVY:
                return RGBA{0, 0, 128, 255};
            case Color::INDIGO:
                return RGBA{75, 0, 130, 255};
            case Color::MAROON:
                return RGBA{128, 0, 0, 255};
            case Color::OLIVE:
                return RGBA{128, 128, 0, 255};
            case Color::CORAL:
                return RGBA{255, 127, 80, 255};
            case Color::TURQUOISE:
                return RGBA{64, 224, 208, 255};
            case Color::PLUM:
                return RGBA{221, 160, 221, 255};
            case Color::SLATE:
                return RGBA{112, 128, 144, 255};
            case Color::CRIMSON:
                return RGBA{220, 20, 60, 255};
            case Color::STEEL:
                return RGBA{70, 130, 180, 255};
            case Color::BLACK:
                return RGBA{0, 0, 0, 255};
            case Color::WHITE:
                return RGBA{255, 255, 255, 255};
            case Color::GRAY:
                return RGBA{128, 128, 128, 255};
            case Color::AQUA:
                return RGBA{0, 255, 255, 255};
            case Color::VIOLET:
                return RGBA{238, 130, 238, 255};
        }
        return {};
    }
}

sts::SFMLRenderer::SFMLRenderer(sf::RenderWindow * renderer) : m_window{renderer} {}

void sts::SFMLRenderer::draw_filled_rect(int32_t x, int32_t y, int32_t width, int32_t height, Color color) {
    draw_filled_rect(Rect{width, height, x,y}, color);
}

void sts::SFMLRenderer::draw_filled_rect(Rect const & rect, Color color) {
    auto const rgba = convert_to_rgba(color);
    if (!rgba.has_value()) {
        spdlog::warn("invalid color value");
        return;
    }
    auto const [r, g, b, a] = rgba.value();

    sf::RectangleShape sf_rect{sf::Vector2f{static_cast<float>(rect.width), static_cast<float>(rect.height)}};
    sf_rect.setPosition(static_cast<float>(rect.x), static_cast<float>(rect.y));
    sf_rect.setFillColor(sf::Color{r, g, b, a});

    m_window->draw(sf_rect);
}
void sts::SFMLRenderer::draw_filled_circle(int32_t center_x, int32_t center_y, size_t radius, Color color) {
    auto const rgba = convert_to_rgba(color);
    if (!rgba.has_value()) {
        spdlog::warn("invalid color value");
        return;
    }
    auto const [r, g, b, a] = rgba.value();

    sf::CircleShape circle{static_cast<float>(radius)};
    auto const circle_x = static_cast<float>(center_x - static_cast<int32_t>(radius));
    auto const circle_y = static_cast<float>(center_y - static_cast<int32_t>(radius));

    circle.setPosition(circle_x, circle_y);
    circle.setFillColor(sf::Color{r, g, b, a});

    m_window->draw(circle);
}
void sts::SFMLRenderer::clear() {
    m_window->clear(sf::Color::Black);
}
void sts::SFMLRenderer::present() {
    m_window->display();
}
void sts::SFMLRenderer::set_render_color(Color color) {

}
