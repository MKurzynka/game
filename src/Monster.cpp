#include "Monster.h"
#include <iostream>

Monster::Monster()
{

}
Monster::Monster(float p_x, float p_y, Texture& texture)
{
    monster_position.x = p_x;
    monster_position.y = p_y;
    monster_shape.setPosition(p_x, p_y);
    monster_shape.setRadius(this->monster_radius);
    monster_shape.setFillColor(sf::Color::Blue);
    monster_shape.setOrigin(this->monster_radius, this->monster_radius);
    sprite.setPosition(p_x, p_y);
    sprite.setTexture(texture);
    srand(time(NULL));
}

void Monster::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}
void Monster::aggro(double deltaVx, double deltaVy)
{
       monsterCurrentPosition = monster_shape.getPosition();

       double aggroDist;

       aggroDist = std::sqrt(((monsterCurrentPosition.x - 160) * (monsterCurrentPosition.x - 160))
                             + ((monsterCurrentPosition.y - 160) * (monsterCurrentPosition.y - 160)));
       if(aggroDist < aggroRadius)
       {
           aggroState = 1;
           moveTimer++;
           if(fabs(monsterCurrentPosition.x - 160) < 1)
            aggro_vel.x = 0;
            else
             aggro_vel.x = -(monsterCurrentPosition.x - 160) / fabs((monsterCurrentPosition.x - 160)) * 1;

           if(fabs(monsterCurrentPosition.y - 160) < 1)
            aggro_vel.y = 0;
            else
            aggro_vel.y = -(monsterCurrentPosition.y - 160) / fabs((monsterCurrentPosition.y - 160)) * 1;
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
       monsterCurrentPosition.x += aggro_vel.x + deltaVx * 32;
       monsterCurrentPosition.y += aggro_vel.y + deltaVy * 32;
       monster_position.x = monster_position.x + deltaVx * 32;
       monster_position.y = monster_position.y + deltaVy * 32;
       //std::cout << aggro_vel.x << std::endl;
       if(aggro_vel.x < 0)
       {
            if(moveTimer % 3 == 0)
            {
                if(rectSourceSprite.left == 64)
                    rectSourceSprite.left = 0;
                else
                    rectSourceSprite.left += 32;
                rectSourceSprite.top = 32;
                sprite.setTextureRect(rectSourceSprite);
            }
       }else if(aggro_vel.x > 0)
        {
            if(moveTimer % 3 == 0)
            {
                if(rectSourceSprite.left == 64)
                    rectSourceSprite.left = 0;
                else
                    rectSourceSprite.left += 32;
                rectSourceSprite.top = 64;
                sprite.setTextureRect(rectSourceSprite);
            }
       }else if( aggro_vel.y > 0)
       {
           if(moveTimer % 3 == 0)
            {
            if(rectSourceSprite.left == 64)
               rectSourceSprite.left = 0;
            else
                rectSourceSprite.left += 32;
            rectSourceSprite.top = 0;
            sprite.setTextureRect(rectSourceSprite);
            }
       }else if(aggro_vel.y < 0)
       {
            if(moveTimer % 3 == 0)
            {
            if(rectSourceSprite.left == 64)
               rectSourceSprite.left = 0;
            else
                rectSourceSprite.left += 32;
            rectSourceSprite.top = 96;
            sprite.setTextureRect(rectSourceSprite);
            }
       }
       //std::cout << monsterCurrentPosition.x << std::endl;

}

void Monster::randomWalk()
{
    if(!aggroState)
    {
    if(monsterCurrentPosition.x - monster_position.x > 40)
    {
        randomWalk_vel.x = -1;
        homeComming = 1;
    }else if(monsterCurrentPosition.x - monster_position.x < -40)
    {
        randomWalk_vel.x = 1;
        homeComming = 1;
    }else if(monsterCurrentPosition.y - monster_position.y > 40)
    {
        randomWalk_vel.y = -1;
        homeComming = 1;
    }else if(monsterCurrentPosition.y - monster_position.y < -40)
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
                if(rectSourceSprite.left == 64)
                    rectSourceSprite.left = 0;
                else
                    rectSourceSprite.left += 32;
                rectSourceSprite.top = 32;
                sprite.setTextureRect(rectSourceSprite);
            }
       }else if(randomWalk_vel.x > 0)
        {
            if(moveTimer % 3 == 0)
            {
                if(rectSourceSprite.left == 64)
                    rectSourceSprite.left = 0;
                else
                    rectSourceSprite.left += 32;
                rectSourceSprite.top = 64;
                sprite.setTextureRect(rectSourceSprite);
            }
       }else if(randomWalk_vel.y > 0)
       {
           if(moveTimer % 3 == 0)
            {
            if(rectSourceSprite.left == 64)
               rectSourceSprite.left = 0;
            else
                rectSourceSprite.left += 32;
            rectSourceSprite.top = 0;
            sprite.setTextureRect(rectSourceSprite);
            }
       }else if(randomWalk_vel.y < 0)
       {
            if(moveTimer % 3 == 0)
            {
            if(rectSourceSprite.left == 64)
               rectSourceSprite.left = 0;
            else
                rectSourceSprite.left += 32;
            rectSourceSprite.top = 96;
            sprite.setTextureRect(rectSourceSprite);
            }
       }
    if(moveTimer % 60 == 0 && !aggroState)
    {
    randomWalk_vel.y = 0;
       randomWalk_vel.x = 0;
    }
    if(moveTimer % 40 == 0 && !aggroState)
    {
        int dir, h;
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
    }
    else if(aggroState)
    {
       randomWalk_vel.y = 0;
       randomWalk_vel.x = 0;
    }
    //std::cout << randomWalk_vel.x << std::endl;
}

void Monster::update(double deltaVx, double deltaVy, double vx, double vy)
{
    moveTimer > 200 ? moveTimer = 1 : moveTimer++;
    aggro(deltaVx, deltaVy);
    randomWalk();
    std::cout << monster_position.x << std::endl;
    monster_shape.setPosition(monsterCurrentPosition.x + randomWalk_vel.x,monsterCurrentPosition.y + randomWalk_vel.y);
    sprite.setPosition(monsterCurrentPosition.x + randomWalk_vel.x, monsterCurrentPosition.y + randomWalk_vel.y);

}
Monster::~Monster()
{
    //dtor
}
