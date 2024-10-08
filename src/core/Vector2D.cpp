//
// Created by HP on 06.08.2024.
//
#include <cmath>
#include "core/Vector2D.hpp"

namespace core {
    // Vector addition
    Vector2D add(Vector2D const& v1, Vector2D const& v2) {
        return Vector2D(v1.x + v2.x, v1.y + v2.y);
    }

    // Vector subtraction
    Vector2D subtract(Vector2D const& v1, Vector2D const& v2) {
        return Vector2D(v1.x - v2.x, v1.y - v2.y);
    }

    // Scalar multiplication
    Vector2D multiply(Vector2D const& v, float scalar) {
        return Vector2D(v.x * scalar, v.y * scalar);
    }

    // Scalar multiplication
    std::optional<Vector2D> divide(Vector2D const& v, float scalar) {
        if(scalar <= 0.0001) {
            return {};
        }
        return Vector2D(v.x / scalar, v.y / scalar);
    }

    // Vector length (magnitude)
    float magnitude(Vector2D const& v) {
        return std::sqrt(v.x * v.x + v.y * v.y);
    }

    // Dot product
    float dot(Vector2D const& v1, Vector2D const& v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }

    // Normalize Vector
    std::optional<Vector2D> normalize(Vector2D const& v) {
        return divide(v, magnitude(v));
    }

    Vector2D set_limit(Vector2D const& v,float limit) {
        if(auto const mag = magnitude(v);mag > limit) {
            auto const multiplier = limit / mag;
            return multiply(v, multiplier);
        }
        return v;
    }

}
