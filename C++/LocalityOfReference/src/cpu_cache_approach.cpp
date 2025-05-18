#include "cpu_cache_approach.hpp"

#include <tracy/Tracy.hpp>

#include "config.hpp"

namespace lor
{
    namespace
    {
        const tracy::Color::ColorType ZONE_COLOR = tracy::Color::Green1;
    }

    CpuCacheApproach::CpuCacheApproach()
    {
        positions_.reserve(NB_OF_CIRCLES);
        colors_.reserve(NB_OF_CIRCLES);
        shapes_.reserve(NB_OF_CIRCLES);
        for (unsigned int i = 0; i < NB_OF_CIRCLES; ++i)
        {
            positions_.emplace_back(0, static_cast<float>(i * CIRCLE_SIZE));
            colors_.emplace_back(255);
            shapes_.emplace_back();
            shapes_[i].setRadius(CIRCLE_SIZE);
        }
    }

    void CpuCacheApproach::update(float deltaTime)
    {
        ZoneScopedC(ZONE_COLOR);
        for (auto &position : positions_)
        {
            if (position.x > static_cast<float>(SCREEN_WIDTH))
            {
                position = sf::Vector2f(0.0f, position.y);
            }
            else
            {
                [[likely]] position += sf::Vector2f(1.0f, 0.0f);
            }
        }

        for (auto &color : colors_)
        {
            ++color;
            if (color > 255)
            {
                color = 0;
            }
        }
    }

    void CpuCacheApproach::render(sf::RenderWindow &window)
    {
        ZoneScopedC(ZONE_COLOR);
        for (unsigned int i = 0; i < NB_OF_CIRCLES; ++i)
        {
            shapes_[i].setPosition(positions_[i]);
            shapes_[i].setFillColor(sf::Color(colors_[i], colors_[i], colors_[i]));
            window.draw(shapes_[i]);
        }
    }
}