//
// Created by HP on 06.08.2024.
//

#include <catch2/catch_test_macros.hpp>
#include "core/Vector2D.hpp"

TEST_CASE("AddVector", "[Vector2D]") {
    auto const v3 = core::add(core::Vector2D{1, 1}, core::Vector2D{2, 2});
    REQUIRE(v3.x == 3);
    REQUIRE(v3.y == 3);

    auto const v4 = core::add(core::Vector2D{-1, -1}, core::Vector2D{2, 2});
    REQUIRE(v4.x == 1);
    REQUIRE(v4.y == 1);
}

TEST_CASE("SubVector", "[Vector2D]") {
    auto const v3 = core::subtract(core::Vector2D{1, 1}, core::Vector2D{2, 2});
    REQUIRE(v3.x == -1);
    REQUIRE(v3.y == -1);
}

TEST_CASE("MultiplyVector", "[Vector2D]") {
    auto const v3 = core::multiply(core::Vector2D{2, 3}, 3);
    REQUIRE(v3.x == 6);
    REQUIRE(v3.y == 9);
}

TEST_CASE("DivideVector", "[Vector2D]") {
    auto const v3 = core::divide(core::Vector2D{4, 8}, 2);
    if (!v3.has_value()) {
        FAIL();
    }

    REQUIRE(v3.value().x == 2);
    REQUIRE(v3.value().y == 4);

    if (auto const v4 = core::divide(core::Vector2D{1, 1}, 0.000001); v4.has_value()) {
        FAIL();
    }
}

TEST_CASE("MagnitudeVector", "[Vector2D]") {
    auto const v3 = core::magnitude(core::Vector2D{3, 4});
    REQUIRE(v3 == 5);
}

TEST_CASE("DotVector", "[Vector2D]") {
    auto const v3 = core::dot(core::Vector2D{3, 3}, core::Vector2D{2, 2});
    REQUIRE(v3 == 12);
}

TEST_CASE("NormalizeVector", "[Vector2D]") {
    auto const vec = core::Vector2D{3, 4};
    auto const m1 = core::magnitude(vec);
    REQUIRE(m1 == 5);
    if (auto const vec2 = core::normalize(vec); vec2.has_value()) {
        auto const m2 = core::magnitude(vec2.value());
        REQUIRE(m2 == 1);
    } else {
        FAIL();
    }
}

TEST_CASE("SetLimit", "[Vector2D]") {
    auto const v = core::set_limit(core::Vector2D{3, 4}, 5);
    REQUIRE(v.x == 3);
    REQUIRE(v.y == 4);

    auto const v2 = core::set_limit(core::Vector2D{4, 4}, 5);
    REQUIRE(core::magnitude(v2) == 5);
}
