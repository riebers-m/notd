//
// Created by HP on 28.07.2024.
//

#ifndef DETAILS_HPP
#define DETAILS_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

namespace sts {
    class Details {
    public:
        Details() = default;
        ~Details() = default;

        Details(Details const &) = delete;
        Details &operator=(Details const &) noexcept = delete;
        Details(Details &&) = delete;
        Details &&operator=(Details &&) noexcept = delete;

        void init_window(size_t width, size_t height, std::string const &title);

        [[nodiscard]] sf::RenderWindow *get_window() const;

    private:
        std::unique_ptr<sf::RenderWindow> m_window{nullptr};
    };
} // namespace sts
#endif //DETAILS_HPP
