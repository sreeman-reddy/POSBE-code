/*
 * Nicholas Schneider
 * schnei54@purdue.edu
 * March 17, 2016
 * baseball project version 1.0
 */

#include "fielder.h"
#include "player.h"
#include <math.h>
#include <string>

//This class will be used in later versions when there is a GUI
//Mainly was designed to hold the players location in the outfield

Fielder::Fielder(QString name, int position, std::string handiness, int age, int number, std::string nationality)
    : Player (name, position, handiness, age, number, nationality)

{
    playerName = name;
}
