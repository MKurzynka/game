#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "const.h"
using namespace sf;

class Player : public sf::Drawable
{
    public:
        Player();
        Player(float p_x, float p_y, Texture& texture);
        void update();
        virtual ~Player();

    protected:

    private:
        CircleShape player_shape;
        int moveTimer{0};
        Texture texture;
        IntRect rectSourceSprite{0, 0, 32, 32};
        Sprite sprite{texture, rectSourceSprite};
        const float player_radius{20};
        float player_x_velocity{0};
        float player_y_velocity{0};
        float left();
        float right();
        float top();
        float bottom();

        float hp;
        float att{20};
        float def;


        Vector2f player_velocity{player_x_velocity, player_y_velocity};
        void draw(RenderTarget& target, RenderStates states) const override;


};

#endif // PLAYER_H
