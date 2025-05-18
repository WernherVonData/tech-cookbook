#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace lor
{
    class Circle
    {
    public:
        Circle(float x, float y);
        void updateColor();
        void updatePosition();

        const int currentColor() const { return current_color_; }
        const sf::Vector2f position() const { return shape_.getPosition(); }
        const sf::CircleShape &shape() const { return shape_; }

    private:
        sf::CircleShape shape_;
        int current_color_;
    };

    class DirectApproach
    {
    public:
        DirectApproach();
        void update(float deltaTime);
        void render(sf::RenderWindow &window);

    private:
        std::vector<Circle> circles_;
    };
}