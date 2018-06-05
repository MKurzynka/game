#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "const.h"
#include "NPC.h"

class Projectile : public sf::Drawable
{
    public:
        Projectile();
        //Projectile(double vx, double vy, unsigned int direction, sf::Texture& texture, int attack, int speedScalar);
        Projectile(double vx, double vy, unsigned int direction, sf::Texture& texture, int attack, int speedScalar, float aoe,
                   int textureRow, int textureColumn, int maxTextureRow, int maxTextureColumn);
        sf::CircleShape getCirlceShape() const;
        sf::Sprite getSprite() const;
        bool isTerminated();
        double getDMG();
        void setNpc(NPC* npc);
        sf::Vector2f getPosition();
        void setTexture(sf::Texture& texture);
        void update(double deltaVx, double deltaVy);
        void setHit();
        virtual ~Projectile();

    protected:

    private:
        NPC* p_npc;
        int _attack{2};
        float _aoe{0};
        int _textureRow{13}, _textureColumn{9}, _maxTextureRow{13}, _maxTextureColumn{11};
        unsigned int projectileTimer{1};
        unsigned int duration{0};
        unsigned int _lifeTime{100};
        unsigned int hitTimer{0};
        int _speedScalar{10};

        int hit{0};
        sf::Texture _texture;
        sf::IntRect rectSourceSprite{_textureColumn * TILE_SIZE, _textureRow * TILE_SIZE, TILE_SIZE, TILE_SIZE};
        sf::Sprite sprite;
        sf::Vector2f speedVec{0, 0};
        sf::CircleShape projectile_shape;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif // PROJECTILE_H
