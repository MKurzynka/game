#include "Player.h"

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
    sprite.setPosition(p_x, p_y);
    sprite.setTexture(texture);

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}
void Player::update(double vx, double vy, unsigned int direction, Combat& combat, sf::Texture& projectileTexture)
{
    moveTimer ++;
    if(moveTimer > 200)
        moveTimer = 0;
    if(coolDownTime > 0)
        coolDownTime--;
    if(fireballCoolDownTime > 0)
        fireballCoolDownTime--;

    player_shape.move(this->player_velocity);
    sprite.move(player_velocity);
    player_velocity.x = 0;
    player_velocity.y = 0;
    if(sf::Keyboard::isKeyPressed(Keyboard::Key::Space) && coolDownTime == 0)
    {
        coolDownTime = 10;
        std::cout<< "spacja" << std::endl;
        Projectile projectile(WINDOW_SIZE / 2, WINDOW_SIZE / 2, direction, projectileTexture, 6, 20, 11, 0, 11, 11);
        combat.addProjectile(projectile);
    }

    if(sf::Keyboard::isKeyPressed(Keyboard::Key::V) && fireballCoolDownTime == 0)
    {
        fireballCoolDownTime = 30;
        std::cout<< "fireball" << std::endl;
        Fireball fireball(WINDOW_SIZE / 2, WINDOW_SIZE / 2, direction, projectileTexture, 10, 3, 13, 9, 13, 11);
        combat.addFireball(fireball);
    }
    if(sf::Keyboard::isKeyPressed(Keyboard::Key::Left))
    {
        player_velocity.x = 0;
        if(moveTimer % 3 == 0)
        {
            if(rectSourceSprite.left == 64)
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
    if(sf::Keyboard::isKeyPressed(Keyboard::Key::Space))
    {

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
