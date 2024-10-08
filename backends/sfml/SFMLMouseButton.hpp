//
// Created by HP on 10.08.2024.
//

#ifndef SFMLMOUSEBUTTON_HPP
#define SFMLMOUSEBUTTON_HPP

#include <SFML/Window/Mouse.hpp>
#include <optional>
#include "KeyCode.hpp"

namespace sts {
    std::optional<sf::Mouse::Button> map_mousebutton(MouseButton);
}



#endif //SFMLMOUSEBUTTON_HPP
