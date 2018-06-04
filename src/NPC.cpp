#include "NPC.h"

NPC::NPC()
{
    texture.loadFromFile("sprites2.png");
    srand(time(NULL));
}

void NPC::update(double deltaVx, double deltaVy, double vx, double vy)
{
    m_deltaVx = deltaVx;
    m_deltaVy = deltaVy;
    m_vx = vx;
    m_vy = vy;
    monsterTimer++;

    std::vector<Monster>::const_iterator enemyVectorIterator;
    int counter{0};
    for(enemyVectorIterator = enemyVector.begin(); enemyVectorIterator != enemyVector.end();)
    {
        //std::cout<<enemyVector[counter].getHp()<<std::endl;
        if(enemyVector[counter].isDead())
        {

            enemyVectorIterator = enemyVector.erase(enemyVectorIterator);
        }
        else
        {
            enemyVector[counter].update(m_deltaVx, m_deltaVy, m_vx, m_vy);
            enemyPositionVector[counter] = enemyVector[counter].getPosition();
            enemyVectorIterator++;
            counter++;
        }


    }
    if(monsterTimer >= 1000)
        monsterTimer = 1;

    if(!(monsterTimer % 50) && enemyVector.size() < 2)
    {
        hx = rand() % 100;
        hy = rand() % 100;
        Monster monster(hx, hy, texture);
        enemyVector.push_back(monster);
        enemyPositionVector.push_back(monster.getPosition());
    }
}

std::vector<Monster> NPC::getEnemyVector()
{
    return enemyVector;
}

std::vector<sf::Vector2f> NPC::getPositionVector()
{
    return enemyPositionVector;
}


void NPC::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    std::vector<Monster>::const_iterator enemyVectorIterator;
    int counter{0};
    for(enemyVectorIterator = enemyVector.begin(); enemyVectorIterator != enemyVector.end(); enemyVectorIterator++)
    {
        target.draw(enemyVector[counter].getSprite(), states);
        counter++;
    }
}
NPC::~NPC()
{
    //dtor
}
