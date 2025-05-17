#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

namespace lor
{
    class Circle
    {
    public:
        Circle(float x, float y, bool light);
        void updateColor();
        void updatePosition();

        const int currentColor() const { return current_color_; }
        const sf::Vector2f position() const { return position_; }

    private:
        sf::Vector2f position_;
        int current_color_direction_;
        float current_direction_;
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