#ifndef FIREBALL_H
#define FIREBALL_H
#include "Projectile.h"

class Fireball : public Projectile
{
    public:
        Fireball();
        Fireball(double vx, double vy, unsigned int direction, sf::Texture& texture, int attack, int speedScalar,
                 int textureRow, int textureColumn, int maxTextureRow, int maxTextureColumn);
        virtual ~Fireball();

    protected:

    private:
        //unsigned int textureRow{0}, textureColumn{0}, maxTextureRow{0}, maxTextureColum{0};
        unsigned int duration{0};
        unsigned int lifeTime{100};
        unsigned int hitTimer{0};
        //int speedScalar{2};
};

#endif // FIREBALL_H
