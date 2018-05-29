#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.h"
#include "Player.h"
#include "Monster.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(320, 320), "Tibia v2");
    TileMap tileMap;
    tileMap.loadSpriteSheets();
    sf::Texture texture;
    tileMap.loadMapFromTxt();
    	texture.loadFromFile("sprites2.png");
        //std::cout << "Unable to load texture" << std::endl;

    Player player(320 / 2, 320 / 2, texture);
    Monster monster(50, 60, texture);
    Monster monster2(100, 60, texture);
    Monster monster3(70, 10, texture);
    window.setFramerateLimit(30);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        tileMap.updateMap();
        player.update();
        monster.update(tileMap.getDeltaVx(), tileMap.getDeltaVy(), tileMap.getVx(), tileMap.getVy());
       monster2.update(tileMap.getDeltaVx(), tileMap.getDeltaVy(), tileMap.getVx(), tileMap.getVy());
       monster3.update(tileMap.getDeltaVx(), tileMap.getDeltaVy(), tileMap.getVx(), tileMap.getVy());
       window.draw(tileMap);
       window.draw(player);
       window.draw(monster);
       window.draw(monster2);
       window.draw(monster3);
       window.display();
        window.clear();


    }

    return 0;
}
