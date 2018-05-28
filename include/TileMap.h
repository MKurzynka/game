#ifndef TILEMAP_H
#define TILEMAP_H
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

class TileMap : public sf::Drawable
{
    public:
        TileMap();
        void loadSpriteSheets();
        void loadMapFromTxt();
        void updateMap();
        virtual ~TileMap();

    protected:

    private:
        int mapTimer{0};
        int positionLeft{0}, positionRight{0}, positionTop{0}, positionBottom{0};
        double vx{0}, vy{0};
        sf::Vector2i mapVec[20][20];
        sf::Vector2i loadCounter = sf::Vector2i(0,0);
        sf::Texture mapTexture;
        sf::Sprite mapSprite;
        sf::Image tileImage;
        std::vector<sf::Image> tileVector;
        std::vector<sf::Sprite> spriteVector;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // TILEMAP_H
