/*
 * Nicholas Schneider
 * schnei54@purdue.edu
 * March 17, 2016
 * baseball project version 1.0
 */

/* the ERA part of this program is to create a baseline for the pitching stats.
 * we will use these values to normalize the batters data. See the player class
 * under create batting averages
 */

#ifndef ERA_H
#define ERA_H
#include <string>
#include <stdio.h>
#include <iostream>
//#include "team.h"
//#include "player.h"
//#include "pitcher.h"
//#include "fielder.h"


class Era
{
public:
    Era();
    Era (int);
    Era (std::string);

    double eraAtBats;
    double eraHomeRun;
    double eraTriples;
    double eraDouble;
    double eraSingle;
    double eraStrikeOut;
    double eraWalk;
    double eraHitByPitch;
    double eraHits;

    double eraHomeRunPercent;
    double eraTriplePercent;
    double eraDoublePercent;
    double eraSinglePercent;
    double eraStrikeOutPercent;
    double eraWalkPercent;
    double eraHitByPitchPercent;

};

#endif // ERA_H
