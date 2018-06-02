#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.h"
#include "Player.h"
#include "Monster.h"
#include "const.h"
#include "NPC.h"
#include "ObstMap.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Tibia v2");
    TileMap tileMap;
    ObstMap obstMap;
    sf::Texture texture;
    tileMap.loadSpriteSheets("sprite_sheets/otsp_tiles_01.png");
    obstMap.loadSpriteSheets("sprite_sheets/otsp_town_02.png");
    texture.loadFromFile("sprites2.png");
    tileMap.loadMapFromTxt("sprite_sheets/first_layer.txt");
    obstMap.loadMapFromTxt("sprite_sheets/second_layer.txt");

    Player player(WINDOW_SIZE / 2, WINDOW_SIZE / 2, texture);
    Monster monster(50, 60, texture);
    Monster monster2(100, 60, texture);
    Monster monster3(70, 10, texture);
    window.setFramerateLimit(FRAME_LIMIT);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        tileMap.updateMap();
        obstMap.updateMap(tileMap.getVx(), tileMap.getVy());
        player.update();
        monster.update(tileMap.getDeltaVx(), tileMap.getDeltaVy(), tileMap.getVx(), tileMap.getVy());
       monster2.update(tileMap.getDeltaVx(), tileMap.getDeltaVy(), tileMap.getVx(), tileMap.getVy());
       monster3.update(tileMap.getDeltaVx(), tileMap.getDeltaVy(), tileMap.getVx(), tileMap.getVy());
       window.draw(tileMap);
       window.draw(obstMap);
       window.draw(player);
       window.draw(monster);
       window.draw(monster2);
       window.draw(monster3);
       window.display();
        window.clear();


    }

    return 0;
}
