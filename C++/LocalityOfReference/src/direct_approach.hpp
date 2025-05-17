#include <SFML/Graphics.hpp>

namespace lor
{
    class DirectApproach
    {
    public:
        void update(float deltaTime);
        void render(sf::RenderWindow &window);
    };
}