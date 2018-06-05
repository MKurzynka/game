#include "NPC.h"

NPC::NPC()
{
    texture.loadFromFile("sprites2.png");
     texture2.loadFromFile("sprite_sheets/otsp_creatures_02.png");
    srand(time(NULL));
}
NPC::NPC(Player* p_player)
{
    pPlayer = p_player;
    texture.loadFromFile("sprites2.png");
     texture2.loadFromFile("sprite_sheets/otsp_creatures_02.png");
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

    if(!(monsterTimer % SPAWN_TIME_OF_BUG_MONSTERS) && enemyVector.size() < NUMBER_OF_BUG_MONSTERS)
    {
        hx = (rand() % BUG_MONSTER_X) + BUG_MONSTER_AREA_X + vx * TILE_SIZE;
        hy = (rand() % BUG_MONSTER_Y) + BUG_MONSTER_AREA_Y + vy * TILE_SIZE;
        Monster monster(hx, hy, texture2, pPlayer);
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
