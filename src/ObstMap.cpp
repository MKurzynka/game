#include "ObstMap.h"

ObstMap::ObstMap()
{
    //ctor
}
void ObstMap::loadSpriteSheets(std::string filePath)
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
void ObstMap::loadMapFromTxt(std::string filePath)
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
            if(tempVec.x == 0&& tempVec.y == 0)
            {
                tempVec.x = 15;
                tempVec.y = 2;
            }
            mapVec[loadCounter.x][loadCounter.y] = tempVec;
            //std::cout << mapVec[loadCounter.x][loadCounter.y].x << ",";
            //std::cout << mapVec[loadCounter.x][loadCounter.y].y << " ";
            if(openFile.peek() == '\n')
            {
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

void ObstMap::updateMap(double vx, double vy)
{

    for(int j = 0; j < N_TILES_IN_MAP; j++)
    {
        for(int i = 0; i < N_TILES_IN_MAP; i++)
        {
            spriteVector[i + j * N_TILES_IN_MAP].setPosition((i + vx) * TILE_SIZE, (j + vy) * TILE_SIZE);
            spriteVector[i + j * N_TILES_IN_MAP].setTextureRect(sf::IntRect((mapVec[i][j].x - 1) * TILE_SIZE, (mapVec[i][j].y - 1)* TILE_SIZE, TILE_SIZE, TILE_SIZE));

        }
    }

}
void ObstMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
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

ObstMap::~ObstMap()
{
    //dtor
}
