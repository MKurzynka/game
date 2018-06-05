#ifndef MONSTER_H
#define MONSTER_H
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <TileMap.h>
#include "const.h"

using namespace sf;

class Player;

class Monster : public sf::Drawable
{
    public:
        Monster();
        Monster(float p_x, float p_y, Texture& texture, Player* p_player);
        void update(double deltaVx, double deltaVy, double vx, double vy);
        double getHp();
        Sprite getSprite() const;
        sf::CircleShape getMonsterShape() const;
        void gotDMG(double dmg);
        bool isDead();
        bool isGoingToBeDead();
        Vector2f getPosition();
        virtual ~Monster();

    protected:

    private:
        Player* pPlayer;
        CircleShape monster_shape;
        double hp{10};
        bool dead{0};
        int deadTimer{400};
        int dir{0}, h{0};
        int moveTimer{0};
        int aggroRadius{100};
        Texture texture;
        IntRect rectSourceSprite{32, 0, 32, 32};
        Sprite sprite{texture, rectSourceSprite};
        float monster_radius{15};
        double homeRadius{60};
        bool firstIsDead{0};

        bool aggroState{0};
        bool homeComming{0};


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
