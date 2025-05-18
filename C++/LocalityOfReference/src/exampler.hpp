#include <concepts>
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <plog/Log.h>
#include <tracy/Tracy.hpp>

#include "config.hpp"

namespace lor
{
    const constexpr unsigned int COUNTER_LIMIT = 5000;

    template <typename T>
    concept ExamplerRequirements = requires(T t, float time, sf::RenderWindow &w) {
        { t.update(time) } -> std::same_as<void>;
        { t.render(w) } -> std::same_as<void>;
    };

    template <typename T>
        requires ExamplerRequirements<T>
    class Exampler
    {
    public:
        Exampler(const std::string &window_title) : window_title_(window_title),
                                                    window_(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), window_title.c_str()) {}

        void run()
        {
            PLOGI << "Examples starts running";
            if (!window_.isOpen())
            {
                std::cerr << "Failed to open a game window\n";
                return; // Exit if window fails to open
            }
            window_.setFramerateLimit(60);
            T exampleToRun;
            unsigned int counter = 0;
            sf::Clock clock;
            PLOGI << "Loop is starting";
            while (window_.isOpen() && counter < COUNTER_LIMIT)
            {
                ZoneScopedC(tracy::Color::Red1);
                if ((counter + 1) % 100 == 0)
                {
                    PLOGI << (counter + 1) << " out of " << COUNTER_LIMIT;
                }
                processEvents();
                float deltaTime = clock.restart().asSeconds();
                exampleToRun.update(deltaTime);
                window_.clear(sf::Color::Black);
                exampleToRun.render(window_);
                window_.display();
                ++counter;
            }
            if (window_.isOpen())
            {
                window_.close();
            }
        }

    private:
        const std::string window_title_;
        sf::RenderWindow window_;

        void processEvents()
        {
            sf::Event event;
            while (window_.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window_.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        window_.close();
                    }
                    break;
                default:
                    break;
                }
            }
        }
    };
}