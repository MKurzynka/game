#include "Projectile.h"

Projectile::Projectile()
{

}

Projectile::Projectile(double vx, double vy, unsigned int direction, sf::Texture& texture, int attack, int speedScalar,
                   int textureRow, int textureColumn, int maxTextureRow, int maxTextureColumn)
{
    std::cout << "projectile" << std::endl;
    _attack = attack;
    _speedScalar = speedScalar;
    _textureRow = textureRow;
    _textureColumn = textureColumn;
    _maxTextureRow = maxTextureRow;
    _maxTextureColumn = maxTextureColumn;
    rectSourceSprite.left = textureColumn * 32;
    rectSourceSprite.top = textureRow * 32;
    sprite.setTexture(texture);
    sprite.setTextureRect(rectSourceSprite);
    projectile_shape.setRadius(10.0);
    projectile_shape.setFillColor(sf::Color::Green);
    if(direction == 0)
    {
        projectile_shape.setPosition(vx , vy - TILE_SIZE / 2);
        sprite.setPosition(vx , vy - TILE_SIZE / 2);
        //projectile_shape.setOrigin(vx, vy - TILE_SIZE / 2);
        speedVec.y = -_speedScalar;
    }
    else if(direction == 1)
    {
        projectile_shape.setPosition(vx + TILE_SIZE / 2, vy);
        sprite.setPosition(vx + TILE_SIZE / 2, vy);
        //projectile_shape.setOrigin(vx + TILE_SIZE / 2, vy);
        speedVec.x = _speedScalar;
    }
    else if(direction == 2)
    {
        projectile_shape.setPosition(vx, vy + TILE_SIZE / 2);
        sprite.setPosition(vx, vy + TILE_SIZE / 2);
        //projectile_shape.setOrigin(vx, vy + TILE_SIZE / 2);
        speedVec.y = _speedScalar;
    }
    else
    {
        projectile_shape.setPosition(vx - TILE_SIZE / 2, vy);
        sprite.setPosition(vx - TILE_SIZE / 2, vy);
        //projectile_shape.setOrigin(vx - TILE_SIZE / 2, vy);
        speedVec.x = -_speedScalar;
    }
}
void Projectile::setTexture(sf::Texture& texture)
{
    _texture = texture;
}

sf::CircleShape Projectile::getCirlceShape() const
{
    return projectile_shape;
}
sf::Vector2f Projectile::getPosition()
{
    return projectile_shape.getPosition();
}
bool Projectile::isTerminated()
{
    bool sum = (hit == 2);
    return sum;
}

double Projectile::getDMG()
{
    return _attack;
}

void Projectile::update(double deltaVx, double deltaVy)
{
    std::cout<<"update"<<std::endl;
    if(duration > 90)
    {
        setHit();
        duration = 0;
    }
    projectileTimer++;
        projectileTimer > 100 ? hit = 2 : projectileTimer;

    if(hit == 1)
    {
        if(projectileTimer % 2 == 0)
       rectSourceSprite.left += TILE_SIZE;
       if(rectSourceSprite.left > 8 * TILE_SIZE)
        rectSourceSprite.left = 0;
       sprite.setTextureRect(rectSourceSprite);

       projectile_shape.move(deltaVx * TILE_SIZE, deltaVy * TILE_SIZE);
        sprite.move(deltaVx * TILE_SIZE, deltaVy * TILE_SIZE);
    }
    else
    {
        if(projectileTimer % 2 == 0)
        {
            rectSourceSprite.left += TILE_SIZE;
            if(rectSourceSprite.left > _maxTextureColumn * TILE_SIZE)
                rectSourceSprite.left = _textureColumn * TILE_SIZE;
            sprite.setTextureRect(rectSourceSprite);
        }

        projectile_shape.move(deltaVx * TILE_SIZE + speedVec.x, deltaVy * TILE_SIZE + speedVec.y);
        sprite.move(deltaVx * TILE_SIZE + speedVec.x, deltaVy * TILE_SIZE + speedVec.y);
        duration++;
    }
}

void Projectile::setHit()
{
    hit = 1;
    rectSourceSprite.left = 0;
    sprite.setTextureRect(rectSourceSprite);
    projectileTimer = 0;
    projectile_shape.setPosition(-1000000, -100000);

}

sf::Sprite Projectile::getSprite() const
{
    return sprite;
}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

Projectile::~Projectile()
{
    //dtor
}