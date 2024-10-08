//
// Created by HP on 04.08.2024.
//

#include <unordered_map>
#include "SFMLKeyCode.hpp"

namespace sts {
const std::unordered_map<KeyCode, sf::Keyboard::Key> keyMap = {
    {KeyCode::A, sf::Keyboard::A}, {KeyCode::B, sf::Keyboard::B}, {KeyCode::C, sf::Keyboard::C},
    {KeyCode::D, sf::Keyboard::D}, {KeyCode::E, sf::Keyboard::E}, {KeyCode::F, sf::Keyboard::F},
    {KeyCode::G, sf::Keyboard::G}, {KeyCode::H, sf::Keyboard::H}, {KeyCode::I, sf::Keyboard::I},
    {KeyCode::J, sf::Keyboard::J}, {KeyCode::K, sf::Keyboard::K}, {KeyCode::L, sf::Keyboard::L},
    {KeyCode::M, sf::Keyboard::M}, {KeyCode::N, sf::Keyboard::N}, {KeyCode::O, sf::Keyboard::O},
    {KeyCode::P, sf::Keyboard::P}, {KeyCode::Q, sf::Keyboard::Q}, {KeyCode::R, sf::Keyboard::R},
    {KeyCode::S, sf::Keyboard::S}, {KeyCode::T, sf::Keyboard::T}, {KeyCode::U, sf::Keyboard::U},
    {KeyCode::V, sf::Keyboard::V}, {KeyCode::W, sf::Keyboard::W}, {KeyCode::X, sf::Keyboard::X},
    {KeyCode::Y, sf::Keyboard::Y}, {KeyCode::Z, sf::Keyboard::Z}, {KeyCode::Num0, sf::Keyboard::Num0},
    {KeyCode::Num1, sf::Keyboard::Num1}, {KeyCode::Num2, sf::Keyboard::Num2}, {KeyCode::Num3, sf::Keyboard::Num3},
    {KeyCode::Num4, sf::Keyboard::Num4}, {KeyCode::Num5, sf::Keyboard::Num5}, {KeyCode::Num6, sf::Keyboard::Num6},
    {KeyCode::Num7, sf::Keyboard::Num7}, {KeyCode::Num8, sf::Keyboard::Num8}, {KeyCode::Num9, sf::Keyboard::Num9},
    {KeyCode::Escape, sf::Keyboard::Escape}, {KeyCode::LControl, sf::Keyboard::LControl},
    {KeyCode::LShift, sf::Keyboard::LShift}, {KeyCode::LAlt, sf::Keyboard::LAlt},
    {KeyCode::LSystem, sf::Keyboard::LSystem}, {KeyCode::RControl, sf::Keyboard::RControl},
    {KeyCode::RShift, sf::Keyboard::RShift}, {KeyCode::RAlt, sf::Keyboard::RAlt},
    {KeyCode::RSystem, sf::Keyboard::RSystem}, {KeyCode::Menu, sf::Keyboard::Menu},
    {KeyCode::LBracket, sf::Keyboard::LBracket}, {KeyCode::RBracket, sf::Keyboard::RBracket},
    {KeyCode::Semicolon, sf::Keyboard::Semicolon}, {KeyCode::Comma, sf::Keyboard::Comma},
    {KeyCode::Period, sf::Keyboard::Period}, {KeyCode::Quote, sf::Keyboard::Quote},
    {KeyCode::Slash, sf::Keyboard::Slash}, {KeyCode::Backslash, sf::Keyboard::Backslash},
    {KeyCode::Tilde, sf::Keyboard::Tilde}, {KeyCode::Equal, sf::Keyboard::Equal},
    {KeyCode::Hyphen, sf::Keyboard::Hyphen}, {KeyCode::Space, sf::Keyboard::Space},
    {KeyCode::Enter, sf::Keyboard::Enter}, {KeyCode::Backspace, sf::Keyboard::Backspace},
    {KeyCode::Tab, sf::Keyboard::Tab}, {KeyCode::PageUp, sf::Keyboard::PageUp},
    {KeyCode::PageDown, sf::Keyboard::PageDown}, {KeyCode::End, sf::Keyboard::End},
    {KeyCode::Home, sf::Keyboard::Home}, {KeyCode::Insert, sf::Keyboard::Insert},
    {KeyCode::Delete, sf::Keyboard::Delete}, {KeyCode::Add, sf::Keyboard::Add},
    {KeyCode::Subtract, sf::Keyboard::Subtract}, {KeyCode::Multiply, sf::Keyboard::Multiply},
    {KeyCode::Divide, sf::Keyboard::Divide}, {KeyCode::Left, sf::Keyboard::Left},
    {KeyCode::Right, sf::Keyboard::Right}, {KeyCode::Up, sf::Keyboard::Up},
    {KeyCode::Down, sf::Keyboard::Down}, {KeyCode::Numpad0, sf::Keyboard::Numpad0},
    {KeyCode::Numpad1, sf::Keyboard::Numpad1}, {KeyCode::Numpad2, sf::Keyboard::Numpad2},
    {KeyCode::Numpad3, sf::Keyboard::Numpad3}, {KeyCode::Numpad4, sf::Keyboard::Numpad4},
    {KeyCode::Numpad5, sf::Keyboard::Numpad5}, {KeyCode::Numpad6, sf::Keyboard::Numpad6},
    {KeyCode::Numpad7, sf::Keyboard::Numpad7}, {KeyCode::Numpad8, sf::Keyboard::Numpad8},
    {KeyCode::Numpad9, sf::Keyboard::Numpad9}, {KeyCode::F1, sf::Keyboard::F1},
    {KeyCode::F2, sf::Keyboard::F2}, {KeyCode::F3, sf::Keyboard::F3},
    {KeyCode::F4, sf::Keyboard::F4}, {KeyCode::F5, sf::Keyboard::F5},
    {KeyCode::F6, sf::Keyboard::F6}, {KeyCode::F7, sf::Keyboard::F7},
    {KeyCode::F8, sf::Keyboard::F8}, {KeyCode::F9, sf::Keyboard::F9},
    {KeyCode::F10, sf::Keyboard::F10}, {KeyCode::F11, sf::Keyboard::F11},
    {KeyCode::F12, sf::Keyboard::F12}, {KeyCode::F13, sf::Keyboard::F13},
    {KeyCode::F14, sf::Keyboard::F14}, {KeyCode::F15, sf::Keyboard::F15},
    {KeyCode::Pause, sf::Keyboard::Pause}
};

    std::optional<sf::Keyboard::Key> map_keycode(KeyCode key_code) {
        if(auto sf_key = keyMap.find(key_code);sf_key != keyMap.cend()) {
            return sf_key->second;
        }
        return {};
    }
}