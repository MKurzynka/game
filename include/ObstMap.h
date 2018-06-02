#ifndef OBSTMAP_H
#define OBSTMAP_H
#include "TileMap.h"
#include <iostream>
class ObstMap : public TileMap
{
    public:
        ObstMap();
        void loadSpriteSheets(std::string filePath);
        void loadMapFromTxt(std::string filePath);
        void updateMap(double vx, double vy);
        virtual ~ObstMap();

    protected:

    private:
        sf::Vector2i mapVec[N_TILES_IN_MAP][N_TILES_IN_MAP];
        sf::Vector2i loadCounter = sf::Vector2i(0,0);
        sf::Texture mapTexture;
        sf::Sprite mapSprite;
        std::vector<sf::Sprite> spriteVector;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // OBSTMAP_H
