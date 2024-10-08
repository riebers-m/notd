//
// Created by HP on 01.08.2024.
//

#include "Details.hpp"
#include "Exception.hpp"

namespace sts {
    void Details::init_window(size_t width, size_t height,
                                      std::string const &title) {
        if(m_window = std::make_unique<sf::RenderWindow>();!m_window) {
            throw EngineError("creating render window failed: out of memory");
        }
        m_window->create(sf::VideoMode(width, height), title);
    }

    sf::RenderWindow *Details::get_window() const {
        return m_window.get();
    }
}