//
// Created by HP on 10.08.2024.
//

#include "SFMLMouseButton.hpp"
#include <unordered_map>

namespace sts {
    std::unordered_map<MouseButton, sf::Mouse::Button> const key_map = {
            {MouseButton::Left, sf::Mouse::Left},
            {MouseButton::Middle, sf::Mouse::Middle},
            {MouseButton::Right, sf::Mouse::Right},
    };

    std::optional<sf::Mouse::Button> map_mousebutton(MouseButton button) {
        if(auto const sf_button = key_map.find(button); sf_button != key_map.end()) {
            return sf_button->second;
        }
        return {};
    }
} // namespace sts
