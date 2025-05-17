#include <concepts>
#include <iostream>

#include <SFML/Graphics.hpp>

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
        void run()
        {
            ZoneScoped;
            window_{sf::VideoMode(800, 600), "Locality of Reference Example"};
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
                exampleToRun.render(window_);
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
                    window.close();
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