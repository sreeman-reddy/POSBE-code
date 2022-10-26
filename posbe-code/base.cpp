#include "base.h"


Base::Base()
{
    //playerOnBase = NULL;
}

bool Base::isEmpty(){
    return empty;
}

void Base::setPlayer(Player &player){
    playerOnBase = player;
    empty = false;
}

void Base::startInning(){
    empty = true;
}

void Base::setTrue(){
    empty = true;
}

