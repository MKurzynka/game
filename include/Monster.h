#ifndef MONSTER_H
#define MONSTER_H
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <TileMap.h>
#include "const.h"

using namespace sf;

class Monster : public sf::Drawable
{
    public:
        Monster();
        Monster(float p_x, float p_y, Texture& texture);
        void update(double deltaVx, double deltaVy, double vx, double vy);
        Vector2f getPosition();
        virtual ~Monster();

    protected:

    private:
        CircleShape monster_shape;
        int moveTimer{0};
        int aggroRadius{400};
        Texture texture;
        IntRect rectSourceSprite{0, 0, 32, 32};
        Sprite sprite{texture, rectSourceSprite};
        const float monster_radius{20};
        float hp{10};
        float att;
        float def;
        double homeRadius{60};

        bool aggroState{0};
        bool homeComming{0};
        bool isDead{0};

        void randomWalk();
        void aggro(double vx, double vy);

        Vector2f monster_position{0, 0};
        Vector2f monsterCurrentPosition{0, 0};
        Vector2f oldPosition{0, 0};
        Vector2f aggro_vel{0, 0};
        Vector2f randomWalk_vel{0, 0};
        void draw(RenderTarget& target, RenderStates states) const override;


};

#endif // MONSTER_H
