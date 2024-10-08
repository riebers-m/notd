//
// Created by HP on 04.08.2024.
//

#ifndef SFMLKEYCODE_HPP
#define SFMLKEYCODE_HPP

#include <optional>
#include <SFML/Window/Keyboard.hpp>
#include "KeyCode.hpp"

namespace sts {
    std::optional<sf::Keyboard::Key> map_keycode(KeyCode);
}
#endif //KEYCODE_HPP
