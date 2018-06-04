#ifndef ICEBALL_H
#define ICEBALL_H
#include "Projectile.h"

class Iceball : public Projectile
{
    public:
        Iceball();
        //Iceball(double vx, double vy, unsigned int direction, sf::Texture& texture, int attack);
        virtual ~Iceball();

    protected:

    private:
        int textureRow{11}, textureColumn{12}, maxTextureRow{12}, maxTextureColum{4};
        int attack{4};
        unsigned int duration{0};
        unsigned int lifeTime{100};
        unsigned int hitTimer{0};
        int speedScalar{2};
};

#endif // ICEBALL_H
