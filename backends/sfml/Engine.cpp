//
// Created by HP on 28.07.2024.
//

#include "Engine.hpp"
#include "Details.hpp"
#include "Exception.hpp"
#include "SFMLKeyCode.hpp"
#include "SFMLMouseButton.hpp"
#include "SFMLRenderer.hpp"

namespace sts {
    static std::unique_ptr<Details> m_details{nullptr};

    Engine::Engine() {
        // Setup code here
    }

    Engine::~Engine() {
        // Clean Up code here
    }

    Engine const &Engine::instance() {
        static auto engine = Engine{};
        return engine;
    }

    std::shared_ptr<Renderer> Engine::create_renderer(size_t window_width, size_t window_height,
                                                      std::string const &window_title, Engine const &engine) {
        if (!m_details) {
            m_details = std::make_unique<Details>();
        }

        if (m_details->get_window() == nullptr) {
            m_details->init_window(window_width, window_height, window_title);
        }

        if (sf::RenderWindow *window = m_details->get_window(); window != nullptr) {
            return std::make_shared<SFMLRenderer>(window);
        }
        throw EngineError(std::format("renderer not properly initialized"));
    }

    bool Engine::is_window_open() {
        if (sf::RenderWindow *window = m_details->get_window(); window) {
            if (!window->isOpen()) {
                return false;
            }
            sf::Event event{};
            while (window->pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed:
                        window->close();
                        return false;
                    default:
                        break;
                }
            }
            return true;
        }
        return false;
    }

    bool Engine::window_focused() {
        if (sf::RenderWindow const *const window = m_details->get_window(); window) {
            if (!window->isOpen()) {
                return false;
            }
            return window->hasFocus();
        }
        return false;
    }

    bool Engine::is_key_pressed(KeyCode key_code) {
        if (auto const sf_key = map_keycode(key_code); sf_key.has_value()) {
            return sf::Keyboard::isKeyPressed(sf_key.value());
        }
        return false;
    }

    bool Engine::is_mouse_pressed(MouseButton button) {
        if (auto const sf_key = map_mousebutton(button); sf_key.has_value()) {
            return sf::Mouse::isButtonPressed(sf_key.value());
        }
        return false;
    }

    std::optional<core::Vector2D> Engine::get_mouse_position() {
        if (sf::WindowBase *window = m_details->get_window(); window) {
            sf::Vector2i const pos = sf::Mouse::getPosition(*window);
            return core::Vector2D{static_cast<float>(pos.x), static_cast<float>(pos.y)};
        }
        return {};
    }

} // namespace sts
