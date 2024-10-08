//
// Created by HP on 06.08.2024.
//

#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <optional>

namespace core {
    struct Vector2D {
        float x{};
        float y{};

        explicit Vector2D(float x = 0, float y = 0) : x{x}, y{y} {}
    };

    Vector2D add(Vector2D const &v1, Vector2D const &v2);

    // Vector subtraction
    Vector2D subtract(Vector2D const &v1, Vector2D const &v2);

    // Scalar multiplication
    Vector2D multiply(Vector2D const &v, float scalar);

    // Scalar multiplication
    std::optional<Vector2D> divide(Vector2D const &v, float scalar);

    // Vector length (magnitude)
    float magnitude(Vector2D const &v);

    // Dot product
    float dot(Vector2D const &v1, Vector2D const &v2);

    // Normalize Vector
    std::optional<Vector2D> normalize(Vector2D const &v);

    // Set limit for vector magitude
    Vector2D set_limit(Vector2D const&, float limit);
} // namespace core

#endif // VECTOR2D_HPP
