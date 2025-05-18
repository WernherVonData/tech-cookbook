#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace lor
{
    class CpuCacheApproach
    {
    public:
        CpuCacheApproach();
        void update(float deltaTime);
        void render(sf::RenderWindow &window);

    private:
        std::vector<sf::Vector2f> positions_;
        std::vector<int> colors_;
        std::vector<sf::CircleShape> shapes_;
    };
}