#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.h"
#include "Player.h"
#include "Monster.h"
#include "const.h"
#include "NPC.h"
#include "ObstMap.h"
#include "Projectile.h"
#include "Combat.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Tibia v2");
    TileMap tileMap;
    ObstMap obstMap;
    sf::Texture texture;
    sf::Texture texture2;
    sf::Texture projectileTexture;
    tileMap.loadSpriteSheets("sprite_sheets/otsp_tiles_01.png");
    obstMap.loadSpriteSheets("sprite_sheets/otsp_town_02.png");
    texture.loadFromFile("sprites2.png");
    texture2.loadFromFile("sprite_sheets/otsp_creatures_02.png");
    projectileTexture.loadFromFile("sprite_sheets/otsp_misc_01.png");

    tileMap.loadMapFromTxt("sprite_sheets/first_layer.txt");
    obstMap.loadMapFromTxt("sprite_sheets/second_layer.txt");

//    Projectile projectile(100, 100, 1);
    Player player(WINDOW_SIZE / 2, WINDOW_SIZE / 2, texture);
    NPC npc(&player);
    player.setNpc(&npc);
    Combat combat(npc);

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
        player.update(tileMap.getVx(), tileMap.getDeltaVy(), tileMap.getDirection(), combat, projectileTexture);
        combat.update(tileMap.getDeltaVx(), tileMap.getDeltaVy());
        npc.update(tileMap.getDeltaVx(), tileMap.getDeltaVy(), tileMap.getVx(), tileMap.getVy());

        //projectile.update(tileMap.getDeltaVx(), tileMap.getDeltaVy());
       window.draw(tileMap);
       //window.draw(obstMap);


       //window.draw(projectile);
       window.draw(combat);
       window.draw(npc);
       window.draw(player);

       window.display();
        window.clear();


    }

    return 0;
}
