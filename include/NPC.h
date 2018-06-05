#ifndef NPC_H
#define NPC_H
#include <vector>
#include <Monster.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>

class Player;

class NPC : public sf::Drawable
{
    public:

        NPC();
        NPC(Player* p_player);
        std::vector<sf::Vector2f> getPositionVector();
        std::vector<Monster> getEnemyVector();
        std::vector<Monster> enemyVector;
        void update(double deltaVx, double deltaVy, double vx, double vy);
        virtual ~NPC();

    protected:

    private:
    Player* pPlayer;
    int hx{0}, hy{0};
    double m_deltaVx{0}, m_deltaVy{0}, m_vx{0}, m_vy{0};
    unsigned int monsterTimer{1};
    sf::Texture texture;
    sf::Texture texture2;
    std::vector<sf::Vector2f> enemyPositionVector;
    void spawnMonster();
    void destroyMonster();
    void draw(RenderTarget& target, RenderStates states) const override;

};

#endif // NPC_H
