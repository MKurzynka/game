#include "TileMap.h"
#include <fstream>
#include <iostream>
#include <string>


TileMap::TileMap()
{
    //ctor
}

void TileMap::loadSpriteSheets()
{
    std::string mapLocation;
    std::ifstream openFile("sprite_sheets/otsp_tiles_01.png");
    if(openFile.is_open())
    {
        this->mapTexture.loadFromFile("sprite_sheets/otsp_tiles_01.png");
        //this->tileImage.loadFromFile("sprite_sheets/otsp_tiles_01.png");
        int width{16}, height{62};
        this->spriteVector.resize(width * height);
        this->mapSprite.setTexture(mapTexture);

        this->tileVector.resize(width * height);
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                this->spriteVector[16 * i + j].setTexture(mapTexture);
                this->tileVector[16 * i + j].create(32, 32);
                //this->tileVector[16 * i + j].copy(this->tileImage,
                  //                                 0, 0, sf::IntRect(j * 64, i * 64, (j + 1) * 64, (i + 1) * 64));
         this->tileVector[16 * i + j].copy(this->tileImage,
                                                0, 0, sf::IntRect(j * 32, i * 32,  32, 32));
            }

        }
        /*for(int i = 0; i < 10; i++)
        {
            this->mapTexture.update(tileVector[0], i * 64, 64);
        }*/
        std::cout << "Succesfully loaded map sprites" << std::endl;
    }
    else
    {
        std::cout << "Failed to load map sprites!" << std::endl;
    }
    openFile.close();
    //this->s
}
void TileMap::loadMapFromTxt()
{
   //std::ifstream openFile("sprite_sheets/firstLayer.txt");
    std::ifstream openFile("sprite_sheets/first_layer.txt");
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
            std::cout << mapVec[loadCounter.x][loadCounter.y].x << ",";
            std::cout << mapVec[loadCounter.x][loadCounter.y].y << " ";
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
     for(int j = 0; j < 20; j++)
    {
        for(int i = 0; i < 20; i++)
        {
            target.draw(spriteVector[i + j * 20], states);
            //std::cout << mapVec[i][j].x <<std::endl;
            //std::cout << mapVec[i][j].y << std::endl;
        }
    }
    //target.draw(player_shape, states);

}
void TileMap::updateMap()
{
    mapTimer++;
    if(mapTimer > 200)
        mapTimer = 0;


        vxOld = vx;
        vyOld = vy;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        //vxOld = vx;
        positionLeft++;
        vx = -positionRight * 0.1 + positionLeft * 0.1;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        //vxOld = vx;
        positionRight++;
        vx = positionLeft * 0.1  - positionRight * 0.1;


    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        //vyOld = vy;
        positionTop++;
        vy = -positionBottom * 0.1 + positionTop * 0.1;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        //vyOld = vy;
       positionBottom++;
        vy = positionTop * 0.1  - positionBottom * 0.1;
    }
    for(int j = 0; j < 20; j++)
    {
        for(int i = 0; i < 20; i++)
        {
            //std::cout << mapVec[i][j].x <<" , ";
              //  std::cout << mapVec[i][j].y << std::endl;
                this->mapSprite.setPosition(i * 32, j * 32);
                this->mapSprite.setTextureRect(sf::IntRect(mapVec[i][j].x * 32, mapVec[i][j].y * 32, 32, 32));
                this->spriteVector[i + j * 20].setPosition((i + vx) * 32, (j + vy) * 32);
                this->spriteVector[i + j * 20].setTextureRect(sf::IntRect((mapVec[i][j].x - 1) * 32, (mapVec[i][j].y - 1)* 32, 32, 32));
            //}
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
