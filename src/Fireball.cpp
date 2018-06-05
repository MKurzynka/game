#include "Fireball.h"

Fireball::Fireball()
{
    //ctor
}

Fireball::Fireball(double vx, double vy, unsigned int direction, sf::Texture& texture, int attack, int speedScalar, float aoe,
                   int textureRow, int textureColumn, int maxTextureRow, int maxTextureColumn) :
                       Projectile(vx, vy, direction, texture, attack, speedScalar, aoe, textureRow, textureColumn, maxTextureRow,
                        maxTextureColumn)
{
    //ctor
}
Fireball::~Fireball()
{
    //dtor
}
