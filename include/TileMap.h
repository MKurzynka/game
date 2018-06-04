#ifndef TILEMAP_H
#define TILEMAP_H
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include "const.h"

class TileMap : public sf::Drawable
{
    public:
        TileMap();
        void loadSpriteSheets(std::string filePath);
        void loadMapFromTxt(std::string filePath);
        void updateMap();
        virtual ~TileMap();
        double getVx();
        double getVy();
        double getDeltaVx();
        double getDeltaVy();
        unsigned int getDirection();

    protected:

    private:
        int mapTimer{0};
        int positionLeft{0}, positionRight{0}, positionTop{0}, positionBottom{0};
        double vx{0}, vy{0};
        double vxOld{0}, vyOld{0};
        sf::Vector2i mapVec[N_TILES_IN_MAP][N_TILES_IN_MAP];
        sf::Vector2i loadCounter = sf::Vector2i(0,0);
        sf::Texture mapTexture;
        sf::Sprite mapSprite;
        std::vector<sf::Sprite> spriteVector;
        enum facingDirection{Up, Right, Down, Left};
        enum facingDirection direction{Down};
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // TILEMAP_H
