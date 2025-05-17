#include "direct_approach.hpp"

#include <SFML/Graphics/CircleShape.hpp>

#include "config.hpp"
namespace lor
{
    Circle::Circle(float x, float y, bool light) : position_(x, y),
                                                   current_color_direction_(light ? -1 : 1),
                                                   current_direction_(light ? 1.0f : -1.0f)
    {
    }

    void Circle::updateColor()
    {
        if (current_color_ < 0 || current_color_ > 255)
        {
            current_color_direction_ *= -1;
        }
        current_color_ += current_color_direction_;
    }

    void Circle::updatePosition()
    {
        if (position_.x < 0 || position_.x > SCREEN_WIDTH)
        {
            current_direction_ *= -1.0f;
        }
        position_ += sf::Vector2f(current_direction_, 0.0f);
    }

    DirectApproach::DirectApproach()
    {
        circles_.reserve(NB_OF_CIRCLES);
        for (unsigned int i = 0; i < NB_OF_CIRCLES; ++i)
        {
            float current_x = i % 2 == 0 ? 0.0f : static_cast<float>(SCREEN_WIDTH);

            circles_.emplace_back(current_x, i * CIRCLE_SIZE, i % 2 == 0);
        }
    }

    void DirectApproach::update(float deltaTime)
    {
        for (auto &circle : circles_)
        {
            circle.updatePosition();
            circle.updateColor();
        }
    }

    void DirectApproach::render(sf::RenderWindow &window)
    {
        for (auto &circle : circles_)
        {
            sf::CircleShape c;
            c.setFillColor(sf::Color(circle.currentColor(), circle.currentColor(), circle.currentColor()));
            c.setPosition(circle.position());
            window.draw(c);
        }
    }
}