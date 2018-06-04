#include "Combat.h"

Combat::Combat()
{
    //ctor
}
Combat::Combat(NPC& npc)
{
    p_npc = &npc;
}

void Combat::addProjectile(Projectile& projectile)
{
    projectiles.push_back(projectile);

}

void Combat::addFireball(Fireball& fireball)
{
    fireballs.push_back(fireball);
}

void Combat::update(double deltaVx, double deltaVy)
{
    std::vector<sf::Vector2f> enemyPositionTempVector;
    std::vector<sf::Vector2f>::iterator enemyPositionTempVectorIterator;
    enemyPositionTempVector = p_npc->getPositionVector();


    counter = 0;
    for(fireballIterator = fireballs.begin(); fireballIterator != fireballs.end();)
    {
        fireballs[counter].update(deltaVx, deltaVy);
        counter++;
            if(fireballIterator->isTerminated())
            {
                fireballIterator = fireballs.erase(fireballIterator);
            }else
            fireballIterator++;
    }
    counter = 0;
    //if(enemyPositionTempVector.begin() == enemyPositionTempVector.end())
    //{
       for(projectileIterator = projectiles.begin(); projectileIterator != projectiles.end();)
        {
            projectiles[counter].update(deltaVx, deltaVy);
            counter++;
            if(projectileIterator->isTerminated())
            {
                projectileIterator = projectiles.erase(projectileIterator);
            }else
            projectileIterator++;
        }
    //}
    unsigned int counterPos{0};
    for(enemyPositionTempVectorIterator = enemyPositionTempVector.begin(); enemyPositionTempVectorIterator != enemyPositionTempVector.end();)
    {
        counter = 0;
        for(projectileIterator = projectiles.begin(); projectileIterator != projectiles.end();)
        {

            //std::cout << counter << std::endl;
            //projectiles[counter].update(deltaVx, deltaVy);
            double x_dist{0}, y_dist{0};
            sf::Vector2f projectilePosition;
            projectilePosition = projectiles[counter].getPosition();
            x_dist = fabs(projectilePosition.x - enemyPositionTempVector[counterPos].x);
            y_dist = fabs(projectilePosition.y - enemyPositionTempVector[counterPos].y);
            if(sqrt(x_dist * x_dist + y_dist * y_dist) < 16)
            {
                projectiles[counter].setHit();
                p_npc->enemyVector[counterPos].gotDMG(projectiles[counter].getDMG());

            }
            counter++;
            if(projectileIterator->isTerminated())
            {
                projectileIterator = projectiles.erase(projectileIterator);
            }else
            projectileIterator++;
        }
        for(fireballIterator = fireballs.begin(); fireballIterator != fireballs.end(); )
        {
            double x_dist{0}, y_dist{0};
            sf::Vector2f projectilePosition;
            projectilePosition = fireballs[counter].getPosition();
            x_dist = fabs(projectilePosition.x - enemyPositionTempVector[counterPos].x);
            y_dist = fabs(projectilePosition.y - enemyPositionTempVector[counterPos].y);
            if(sqrt(x_dist * x_dist + y_dist * y_dist) < 16)
            {
                fireballs[counter].setHit();
                p_npc->enemyVector[counterPos].gotDMG(fireballs[counter].getDMG());

            }
            counter++;
            if(fireballIterator->isTerminated())
            {
                fireballIterator = fireballs.erase(fireballIterator);
            }else
            fireballIterator++;
        }

        counterPos++;
        enemyPositionTempVectorIterator++;
    }

    /*counter = 0;
    for(projectileIterator = projectiles.begin(); projectileIterator != projectiles.end();)
    {
        projectiles[counter].update(deltaVx, deltaVy);
        unsigned int counterPos{0};
        for(enemyPositionTempVectorIterator = enemyPositionTempVector.begin(); enemyPositionTempVectorIterator != enemyPositionTempVector.end();)
        {
            double x_dist{0}, y_dist{0};
            sf::Vector2f projectilePosition;
            projectilePosition = projectiles[counter].getPosition();
            x_dist = fabs(projectilePosition.x - enemyPositionTempVector[counterPos].x);
            y_dist = fabs(projectilePosition.y - enemyPositionTempVector[counterPos].y);
            if(sqrt(x_dist * x_dist + y_dist * y_dist) < 16)
            {
                projectiles[counter].setHit();
                std::cout<<projectiles[counter].getDMG()<<std::endl;
                p_npc->enemyVector[counterPos].gotDMG(projectiles[counter].getDMG());
                std::cout<< p_npc->enemyVector[counterPos].getHp() <<std::endl;
            }
            counterPos++;
            enemyPositionTempVectorIterator++;
        }
        counter++;
        if(projectileIterator->isTerminated())
        {
            projectileIterator = projectiles.erase(projectileIterator);
        }else
        projectileIterator++;
    }*/

}

void Combat::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    std::vector<Projectile>::const_iterator constProjectileIterator;
    int counterI = 0;
    for(constProjectileIterator = projectiles.begin(); constProjectileIterator != projectiles.end(); constProjectileIterator++)
    {
        target.draw(projectiles[counterI].getSprite(), states);
        counterI++;
    }
    std::vector<Fireball>::const_iterator constFireballIterator;
    counterI = 0;
    for(constFireballIterator = fireballs.begin(); constFireballIterator != fireballs.end(); constFireballIterator++)
    {
        target.draw(fireballs[counterI].getSprite(), states);
        counterI++;
    }
}

Combat::~Combat()
{
    //dtor
}
