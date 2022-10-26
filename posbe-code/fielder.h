/*
 * Nicholas Schneider
 * schnei54@purdue.edu
 * March 17, 2016
 * baseball project version 1.0
 */

/* this is basically a useless class. When I was coding this part of the project
 * I was going to define players that are not pitchers as fielders. Than use
 * the fielder class to build a class called field and that would be the location
 * of all the feilders and what the stadium looks like. I still plan to do that
 * however that was not relevant for the scope of this project.
 */

#ifndef FIELDER
#define FIELDER
#include "player.h"
#include <string>

class Fielder : public Player {

public:
    Fielder(QString name, int position, std::string handiness, int age, int number, std::string nationality);

};

#endif // FIELDER

