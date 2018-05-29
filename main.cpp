#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Player.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 640), "Tibia v2");
    TileMap tileMap;
    tileMap.loadSpriteSheets();
    sf::Texture texture;
    tileMap.loadMapFromTxt();
    	texture.loadFromFile("sprites2.png");
        //std::cout << "Unable to load texture" << std::endl;

    Player player(320 / 2, 320 / 2, texture);

    window.setFramerateLimit(60);
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
       window.draw(tileMap);
       window.draw(player);
       window.display();
        window.clear();

    }

    return 0;
}
