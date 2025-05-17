#include <concepts>
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "config.hpp"

namespace lor
{
    const constexpr unsigned int COUNTER_LIMIT = 1000000;

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
        Exampler(const std::string &window_title) : window_(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), window_title.c_str()) {}

        void run()
        {
            if (!window_.isOpen())
            {
                std::cerr << "Failed to open a game window\n";
            }
            window_.setFramerateLimit(60);
            window_open_ = true;
            T exampleToRun;
            unsigned int counter = 0;
            sf::Clock clock;
            while (window_open_ && counter < COUNTER_LIMIT)
            {
                processEvents();
                float deltaTime = clock.restart().asSeconds();
                exampleToRun.update(deltaTime);
                window_.clear();
                exampleToRun.render(window_);
                window_.display();
            }
        }

    private:
        bool window_open_ = false;
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
                    if (event.key.code == sf::Keyboard::Escape && window_open_)
                    {
                        window_open_ = false;
                    }
                    break;
                default:
                    break;
                }
            }
        }
    };
}