#ifndef BASE_H
#define BASE_H
#include "player.h"
//#include "team.h"


class Base
{
    Player * playerOnBase;
    bool empty;

public:
    Base();
    void isEmpty();
    void setPlayer(Player &player);
    void startInning();
    void setTrue();
};

#endif // BASE_H
