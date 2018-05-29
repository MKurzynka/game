#ifndef NPC_H
#define NPC_H
#include <vector>
#include <Monster.h>

class NPC
{
    public:
        NPC();
        virtual ~NPC();

    protected:

    private:
    std::vector<Monster> enemyVector;
};

#endif // NPC_H
