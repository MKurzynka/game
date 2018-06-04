#ifndef COMBAT_H
#define COMBAT_H
#include <math.h>
#include <vector>
#include "NPC.h"
#include "Projectile.h"
#include "Fireball.h"
#include "Monster.h"


class Combat : public sf::Drawable
{
    public:
        Combat();
        Combat(NPC& npc);
        void addProjectile(Projectile& projectile);
        void addFireball(Fireball& fireball);
        void update(double deltaVx, double deltaVy);
        unsigned int getNumberOfProjectiles();
        virtual ~Combat();

    protected:

    private:
        NPC* p_npc;
        unsigned int counter{0};
        std::vector<Projectile> projectiles;
        std::vector<Projectile>::iterator projectileIterator;
        std::vector<Fireball> fireballs;
        std::vector<Fireball>::iterator fireballIterator;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // COMBAT_H
