#include "TileMap.h"
#include <fstream>
#include <iostream>
#include <string>


TileMap::TileMap()
{
    //ctor
}

void TileMap::loadSpriteSheets(std::string filePath)
{
    std::ifstream openFile(filePath);
    if(openFile.is_open())
    {
        this->mapTexture.loadFromFile(filePath);
        this->spriteVector.resize(N_TILES_IN_MAP * N_TILES_IN_MAP);
        this->mapSprite.setTexture(mapTexture);

        for(int i = 0; i < N_TILES_IN_MAP * N_TILES_IN_MAP; i++)
        {
            this->spriteVector[i].setTexture(mapTexture);
        }


        std::cout << "Succesfully loaded map sprites" << std::endl;
    }
    else
    {
        std::cout << "Failed to load map sprites!" << std::endl;
    }
    openFile.close();
}
void TileMap::loadMapFromTxt(std::string filePath)
{

    std::ifstream openFile(filePath);
    if(openFile.is_open())
    {
        std::cout << "Succesfully loaded first layer map matrix" << std::endl;
        while(!openFile.eof())
        {
            int xSpriteCoord{-1}, ySpriteCoord{-1};
            openFile >>  xSpriteCoord;
            openFile >>  ySpriteCoord;
            sf::Vector2i tempVec;
            tempVec.x = xSpriteCoord + 1;
            tempVec.y = ySpriteCoord + 1;
            mapVec[loadCounter.x][loadCounter.y] = tempVec;
            //std::cout << mapVec[loadCounter.x][loadCounter.y].x << ",";
            //std::cout << mapVec[loadCounter.x][loadCounter.y].y << " ";
            if(openFile.peek() == '\n')
            {
                std::cout << std::endl;
                loadCounter.x = 0;
                loadCounter.y++;
            }
            else
                loadCounter.x++;
        }

    }
    else
    {
        std::cout << "Failed to load first layer map matrix" << std::endl;
    }
    openFile.close();


}
void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
     for(int j = 0; j < N_TILES_IN_MAP; j++)
    {
        for(int i = 0; i < N_TILES_IN_MAP; i++)
        {
            target.draw(spriteVector[i + j * N_TILES_IN_MAP], states);
            //std::cout << mapVec[i][j].x <<std::endl;
            //std::cout << mapVec[i][j].y << std::endl;
        }
    }

}
unsigned int TileMap::getDirection()
{
    return static_cast<unsigned int>(direction);
}
void TileMap::updateMap()
{
    //std::cout<<vx<<","<<vy<<std::endl;
    mapTimer++;
    if(mapTimer > 200)
        mapTimer = 0;


        vxOld = vx;
        vyOld = vy;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        direction = Left;
        positionLeft++;
        vx = -positionRight * PLAYER_SPEED_FACTOR + positionLeft * PLAYER_SPEED_FACTOR;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        direction = Right;
        positionRight++;
        vx = positionLeft * PLAYER_SPEED_FACTOR  - positionRight * PLAYER_SPEED_FACTOR;


    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        direction = Up;
        positionTop++;
        vy = -positionBottom * PLAYER_SPEED_FACTOR + positionTop * PLAYER_SPEED_FACTOR;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        direction = Down;
        positionBottom++;
        vy = positionTop * PLAYER_SPEED_FACTOR  - positionBottom * PLAYER_SPEED_FACTOR;
    }
    for(int j = 0; j < N_TILES_IN_MAP; j++)
    {
        for(int i = 0; i < N_TILES_IN_MAP; i++)
        {
            this->spriteVector[i + j * N_TILES_IN_MAP].setPosition((i + vx) * TILE_SIZE, (j + vy) * TILE_SIZE);
            this->spriteVector[i + j * N_TILES_IN_MAP].setTextureRect(sf::IntRect((mapVec[i][j].x - 1) * TILE_SIZE, (mapVec[i][j].y - 1)* TILE_SIZE, TILE_SIZE, TILE_SIZE));
        }
    }
}
double TileMap::getVx()
{
    return vx;
}
double TileMap::getVy()
{
    return vy;
}
double TileMap::getDeltaVx()
{
    return vx - vxOld;
}
double TileMap::getDeltaVy()
{
    return vy - vyOld;
}
TileMap::~TileMap()
{
    //dtor
}
