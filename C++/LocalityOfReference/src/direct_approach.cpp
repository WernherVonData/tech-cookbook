#include "direct_approach.hpp"

#include <plog/Log.h>
#include <tracy/Tracy.hpp>

#include "config.hpp"
namespace lor
{
    namespace
    {
        const tracy::Color::ColorType ZONE_COLOR = tracy::Color::Blue;
    }
    Circle::Circle(float x, float y) : current_color_(255)
    {
        shape_.setPosition(x, y);
        shape_.setRadius(CIRCLE_SIZE);
    }

    void Circle::updateColor()
    {
        ++current_color_;
        if (current_color_ > 255)
        {
            current_color_ = 0;
        }
        shape_.setFillColor(sf::Color(current_color_, current_color_, current_color_));
    }

    void Circle::updatePosition()
    {
        if (shape_.getPosition().x > static_cast<float>(SCREEN_WIDTH))
        {
            shape_.setPosition(sf::Vector2f(0.0f, shape_.getPosition().y));
        }
        else
        {
            [[likely]] shape_.setPosition(shape_.getPosition() + sf::Vector2f(1.0f, 0.0f));
        }
    }

    DirectApproach::DirectApproach()
    {
        circles_.reserve(NB_OF_CIRCLES);
        for (unsigned int i = 0; i < NB_OF_CIRCLES; ++i)
        {
            circles_.emplace_back(0, static_cast<float>(i * CIRCLE_SIZE));
        }
    }

    void DirectApproach::update(float deltaTime)
    {
        ZoneScopedC(ZONE_COLOR);
        for (auto &circle : circles_)
        {
            circle.updatePosition();
            circle.updateColor();
        }
    }

    void DirectApproach::render(sf::RenderWindow &window)
    {
        ZoneScopedC(ZONE_COLOR);
        for (const auto &circle : circles_)
        {
            window.draw(circle.shape());
        }
    }
}