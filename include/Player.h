#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "const.h"
#include <iostream>
#include "Combat.h"
#include "Projectile.h"
#include <math.h>
#include "NPC.h"

using namespace sf;

class Player : public sf::Drawable
{
    public:
        Player();
        Player(float p_x, float p_y, Texture& texture);
        void setNpc(NPC* npc);
        float getPlayerMagicAttack();
        void lvlUp();
        void addExp(double gainedExp);
        void update(double vx, double vy,  unsigned int direction, Combat& combat, sf::Texture& projectileTexture);
        virtual ~Player();

    protected:

    private:
        NPC* p_npc;
        unsigned int coolDownTime{0};
        unsigned int fireballCoolDownTime{0};
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

        int level{0};
        double experience{0};
        float hp;
        float magicAttack{1};
        float coolDownReduction{1};
        float def;


        Vector2f player_velocity{player_x_velocity, player_y_velocity};
        double nextLvlExp(int lvl);
        void draw(RenderTarget& target, RenderStates states) const override;


};

#endif // PLAYER_H
