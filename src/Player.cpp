#include "Player.h"
#include <iostream>

Player::Player()
{
    //ctor
}

Player::Player(float p_x,float p_y, Texture& texture)
{

    player_shape.setPosition(p_x, p_y);
    player_shape.setRadius(this->player_radius);
    player_shape.setFillColor(sf::Color::Blue);
    player_shape.setOrigin(this->player_radius, this->player_radius);
    //sprite.scale(sf::Vector2f(0.1,0.1));

    sprite.setPosition(p_x, p_y);
    //sprite.setOrigin(player_radius, player_radius);
    sprite.setTexture(texture);

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
    //target.draw(player_shape, states);

}
void Player::update()
{
    moveTimer ++;
    if(moveTimer > 200)
        moveTimer = 0;

    player_shape.move(this->player_velocity);
    sprite.move(player_velocity);
    player_velocity.x = 0;
    player_velocity.y = 0;
    if(sf::Keyboard::isKeyPressed(Keyboard::Key::Left))
    {
        //if(left() > 0)
           // player_velocity.x = -2;
        //else
            player_velocity.x = 0;
    if(moveTimer % 3 == 0)

        {if(rectSourceSprite.left == 64)
           rectSourceSprite.left = 0;
        else
            rectSourceSprite.left += 32;
        rectSourceSprite.top = 32;
        sprite.setTextureRect(rectSourceSprite);
        }

    }
    if(sf::Keyboard::isKeyPressed(Keyboard::Key::Right))
    {
        //if(right() < 600)
            //player_velocity.x = 2;
        //else
            player_velocity.x = 0;
        if(moveTimer % 3 == 0)
        {
        if(rectSourceSprite.left == 64)
           rectSourceSprite.left = 0;
        else
            rectSourceSprite.left += 32;
        rectSourceSprite.top = 64;
        sprite.setTextureRect(rectSourceSprite);
        }

    }
    if(sf::Keyboard::isKeyPressed(Keyboard::Key::Up))
    {
        //if(top() > 0)
           // player_velocity.y = -2;
       // else
            player_velocity.y = 0;

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
    if(sf::Keyboard::isKeyPressed(Keyboard::Key::Down))
    {
        //if(bottom() < 600)
           // player_velocity.y = 2;
        //else
            player_velocity.y = 0;
        if(moveTimer % 3 == 0)
        {
        if(rectSourceSprite.left == 64)
           rectSourceSprite.left = 0;
        else
            rectSourceSprite.left += 32;
        rectSourceSprite.top = 0;
        sprite.setTextureRect(rectSourceSprite);
        }

    }

}

float Player::left()
{
    return this->player_shape.getPosition().x - player_shape.getRadius();
}
float Player::right()
{
    return this->player_shape.getPosition().x + player_shape.getRadius();
}
float Player::top()
{
    return this->player_shape.getPosition().y - player_shape.getRadius();
}
float Player::bottom()
{
    return this->player_shape.getPosition().y + player_shape.getRadius();
}


Player::~Player()
{
    //dtor
}
