#include "Monster.h"
#include <iostream>
#include "Player.h"

Monster::Monster()
{
    //std::cout << "monster" << std::endl;

}
Monster::Monster(float p_x, float p_y, Texture& texture, Player* p_player)
{
    pPlayer = p_player;
    monster_position.x = p_x;
    monster_position.y = p_y;
    monster_shape.setPosition(p_x, p_y);
    monster_shape.setRadius(this->monster_radius);
    monster_shape.setFillColor(sf::Color::Blue);
    monster_shape.setOrigin(this->monster_radius, this->monster_radius);
    sprite.setPosition(p_x - monster_radius, p_y - monster_radius);
    sprite.setTexture(texture);
    srand(time(NULL));
}


Sprite Monster::getSprite() const
{
    return sprite;
}

void Monster::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    target.draw(monster_shape, states);
}

void Monster::gotDMG(double dmg)
{
    hp = hp - dmg;
}

double Monster::getHp()
{
    return hp;
}

bool Monster::isDead()
{
    //std::cout<<dead<<std::endl;
    return dead;
}
bool Monster::isGoingToBeDead()
{
    if(hp<=0 && !firstIsDead)
    {
       pPlayer->addExp(10);
       rectSourceSprite.left = 13*32;
       firstIsDead = 1;
       monster_shape.setPosition(-200, -200);
    }


    return (hp <= 0) ? 1 : 0;
}

sf::CircleShape Monster::getMonsterShape() const
{
    return monster_shape;
}

void Monster::aggro(double deltaVx, double deltaVy)
{
    if(!isGoingToBeDead())
     {
         monsterCurrentPosition = monster_shape.getPosition();

       double aggroDist;

       aggroDist = std::sqrt(((monsterCurrentPosition.x - WINDOW_SIZE / 2) * (monsterCurrentPosition.x - WINDOW_SIZE / 2))
                             + ((monsterCurrentPosition.y - WINDOW_SIZE / 2) * (monsterCurrentPosition.y - WINDOW_SIZE / 2)));
       if(aggroDist < aggroRadius)
       {
           aggroState = 1;
           moveTimer++;
           if(fabs(monsterCurrentPosition.x - WINDOW_SIZE / 2) < 1)
            aggro_vel.x = 0;
            else
             aggro_vel.x = -(monsterCurrentPosition.x - WINDOW_SIZE / 2) / fabs((monsterCurrentPosition.x - WINDOW_SIZE / 2)) * 1;

           if(fabs(monsterCurrentPosition.y - WINDOW_SIZE / 2) < 1)
            aggro_vel.y = 0;
            else
            aggro_vel.y = -(monsterCurrentPosition.y - WINDOW_SIZE / 2) / fabs((monsterCurrentPosition.y - WINDOW_SIZE / 2)) * 1;
       }
       else
       {
           aggroState = 0;
           aggro_vel.x = 0;
           aggro_vel.y = 0;
       }
       //std::cout << monsterCurrentPosition.x << std::endl;
       //std::cout << aggro_vel.x << std::endl;
       //std::cout << deltaVx << std::endl;
       monsterCurrentPosition.x += aggro_vel.x + deltaVx * TILE_SIZE;
       monsterCurrentPosition.y += aggro_vel.y + deltaVy * TILE_SIZE;
       monster_position.x = monster_position.x + deltaVx * TILE_SIZE;
       monster_position.y = monster_position.y + deltaVy * TILE_SIZE;
       //std::cout << aggro_vel.x << std::endl;
       if(aggro_vel.x < 0)
       {
            if(moveTimer % 3 == 0)
            {
                if(rectSourceSprite.left >= 12 * 32 || rectSourceSprite.left < 10 * 32)
                    rectSourceSprite.left = 10 * 32;
                else
                    rectSourceSprite.left += 32;
                //rectSourceSprite.top = 32;
                sprite.setTextureRect(rectSourceSprite);
            }
       }
       else if(aggro_vel.x > 0)
        {
            if(moveTimer % 3 == 0)
            {
            if(rectSourceSprite.left >= 6 * 32 || rectSourceSprite.left < 4 * 32)
                    rectSourceSprite.left = 4 * 32;
                else
                    rectSourceSprite.left += 32;
                //rectSourceSprite.top = 64;
                sprite.setTextureRect(rectSourceSprite);
            }
        }

       else if( aggro_vel.y > 0)
        {

           if(moveTimer % 3 == 0)
            {
            if(rectSourceSprite.left >= 3*32)
               rectSourceSprite.left = 1*32;
            else
                rectSourceSprite.left += 32;
            sprite.setTextureRect(rectSourceSprite);
            }
       }
        else if(aggro_vel.y < 0)
       {
            if(moveTimer % 3 == 0)
            {
            if(rectSourceSprite.left >= 9*32 || rectSourceSprite.left < 7*32)
               rectSourceSprite.left = 7*32;
            else
                rectSourceSprite.left += 32;
            sprite.setTextureRect(rectSourceSprite);
            }
        }
       //std::cout << monsterCurrentPosition.x << std::endl;

}
}



void Monster::randomWalk()
{
    if(!isGoingToBeDead())

    {if(!aggroState)
    {
    if(monsterCurrentPosition.x - monster_position.x > homeRadius)
    {
        randomWalk_vel.x = -1;
        homeComming = 1;
    }else if(monsterCurrentPosition.x - monster_position.x < -homeRadius)
    {
        randomWalk_vel.x = 1;
        homeComming = 1;
    }else if(monsterCurrentPosition.y - monster_position.y > homeRadius)
    {
        randomWalk_vel.y = -1;
        homeComming = 1;
    }else if(monsterCurrentPosition.y - monster_position.y < -homeRadius)
    {
        randomWalk_vel.y = 1;
        homeComming = 1;
    }else
    {
        homeComming = 0;
    }

//std::cout << monsterCurrentPosition.x << std::endl;
    if(randomWalk_vel.x < 0)
       {

            if(moveTimer % 3 == 0)
            {
                if(rectSourceSprite.left >= 12 * 32 || rectSourceSprite.left < 10 * 32)
                    rectSourceSprite.left = 10 * 32;
                else
                    rectSourceSprite.left += 32;
                //rectSourceSprite.top = 32;
                sprite.setTextureRect(rectSourceSprite);
            }
       }else if(randomWalk_vel.x > 0)
        {
            if(moveTimer % 3 == 0)
            {
            if(rectSourceSprite.left >= 6 * 32 || rectSourceSprite.left < 4 * 32)
                    rectSourceSprite.left = 4 * 32;
                else
                    rectSourceSprite.left += 32;
                //rectSourceSprite.top = 64;
                sprite.setTextureRect(rectSourceSprite);
            }
        }
       else if(randomWalk_vel.y > 0)
       {

           if(moveTimer % 3 == 0)
            {
            if(rectSourceSprite.left >= 3*32)
               rectSourceSprite.left = 1*32;
            else
                rectSourceSprite.left += 32;
            sprite.setTextureRect(rectSourceSprite);
            }
       }
       else if(randomWalk_vel.y < 0)
        {
            if(moveTimer % 3 == 0)
            {
            if(rectSourceSprite.left >= 9*32 || rectSourceSprite.left < 7*32)
               rectSourceSprite.left = 7*32;
            else
                rectSourceSprite.left += 32;
            sprite.setTextureRect(rectSourceSprite);
            }
        }
       }
    if(moveTimer % 60 == 0 && !aggroState)
    {
    randomWalk_vel.y = 0;
       randomWalk_vel.x = 0;
    }
    if(moveTimer % 40 == 0 && !aggroState)
    {

        h = rand();
        dir = h % 5;
        if(dir == 0)
        {
            randomWalk_vel.y = 0;
            randomWalk_vel.x = 1;
        }
        else if(dir == 1)
        {
            randomWalk_vel.y = 0;
            randomWalk_vel.x = -1;
        }
        else if(dir == 2)
        {
            randomWalk_vel.y = 1;
            randomWalk_vel.x = 0;
        }
        else if(dir == 3)
        {
            randomWalk_vel.y = -1;
            randomWalk_vel.x = 0;
        }
        else
        {
           randomWalk_vel.y = 0;
           randomWalk_vel.x = 0;
        }
    }

    else if(aggroState)
    {
       randomWalk_vel.y = 0;
       randomWalk_vel.x = 0;
    }
    //std::cout << randomWalk_vel.x << std::endl;
}
}

sf::Vector2f Monster::getPosition()
{
    Vector2f position{monsterCurrentPosition.x, monsterCurrentPosition.y};
    return position;
}

void Monster::update(double deltaVx, double deltaVy, double vx, double vy)
{
    //sf::Vector2f pos;
    //pos = getPosition();
    //std::cout<<pos.x<<","<<pos.y<<std::endl;
    if(isGoingToBeDead())
    {
        deadTimer--;
        if(deadTimer % 100 == 0)
            rectSourceSprite.left += 32;
        sprite.setTextureRect(rectSourceSprite);
        if(deadTimer <= 0)
            dead = 1;

        //monster_shape.move(deltaVx * TILE_SIZE, deltaVy * TILE_SIZE);
        monsterCurrentPosition.x = -200;
        monsterCurrentPosition.y = -200;
        monster_shape.setPosition(-200, -200);
        sprite.move(deltaVx * TILE_SIZE, deltaVy * TILE_SIZE);
    }
    else
    {
        moveTimer > 200 ? moveTimer = 1 : moveTimer++;
        aggro(deltaVx, deltaVy);
        randomWalk();
        //std::cout << monster_position.x << std::endl;
        monster_shape.setPosition(monsterCurrentPosition.x + randomWalk_vel.x,monsterCurrentPosition.y + randomWalk_vel.y);
        sprite.setPosition(monsterCurrentPosition.x + randomWalk_vel.x, monsterCurrentPosition.y + randomWalk_vel.y);

    }
}

Monster::~Monster()
{
    //std::cout<<"dead"<<std::endl;
}
