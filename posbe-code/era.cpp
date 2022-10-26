/*
 * Nicholas Schneider
 * schnei54@purdue.edu
 * March 17, 2016
 * baseball project version 1.0
 */

#include "era.h"

//Era is the class where the league stats for that year are held. See thesis for exact equations
//This is crucial to the output

Era::Era()
{
    eraAtBats = 183628;
    eraHits = 42106;
    eraHomeRun = 4909;
    eraTriples = 939;
    eraDouble = 8242;
    eraSingle = eraHits - eraHomeRun - eraTriples - eraDouble;
    eraWalk = 14073;
    eraHitByPitch = 1602;
    eraStrikeOut = 37446;

    eraHomeRunPercent = eraHomeRun/eraAtBats;
    eraTriplePercent = eraTriples/eraAtBats;
    eraDoublePercent = eraDouble/eraAtBats;
    eraSinglePercent = eraSingle/eraAtBats;
    eraWalkPercent = eraWalk/eraAtBats;
    eraHitByPitchPercent = eraHitByPitch/eraAtBats;
    eraStrikeOutPercent = eraStrikeOut/eraAtBats;

    /*std::cout << "ERA Stats \n";
    std::cout << "single percent = " << eraSinglePercent << std::endl;
    std::cout << "double percent = " << eraDoublePercent << std::endl;
    std::cout << "triple percent = " << eraTriplePercent << std::endl;
    std::cout << "homerun percent = " << eraHomeRunPercent << std::endl;
    std::cout <<"walk percent = " << eraWalkPercent << std::endl;
    std::cout << "hit by pitch percent = " << eraHitByPitchPercent << std::endl;
    std::cout << "strike out percent = " << eraStrikeOutPercent << "\n\n\n";*/


}

Era::Era(int year){
    eraAtBats = 183628;
    eraHits = 42106;
    eraHomeRun = 4909;
    eraTriples = 939;
    eraDouble = 8242;
    eraSingle = eraHits - eraHomeRun - eraTriples - eraDouble;
    eraWalk = 14073;
    eraHitByPitch = 1602;
    eraStrikeOut = 37446;

    eraHomeRunPercent = eraHomeRun/eraAtBats * 100;
    eraTriplePercent = eraTriples/eraAtBats * 100;
    eraDoublePercent = eraDouble/eraAtBats * 100;
    eraSinglePercent = eraSingle/eraAtBats * 100;
    eraWalkPercent = eraWalk/eraAtBats * 100;
    eraHitByPitchPercent = eraHitByPitch * 100;
    eraStrikeOutPercent = eraStrikeOut/eraAtBats * 100;
}

Era::Era(std::string opposingTeamName){
    if (opposingTeamName == "yankees"){
        eraAtBats = 689;
        eraHits = 154;
        eraHomeRun = 20;
        eraTriples = 1;
        eraDouble = 31;
        eraSingle = eraHits - eraHomeRun - eraTriples - eraDouble;
        eraWalk = 52;
        eraHitByPitch = 6;
        eraStrikeOut = 144;

        eraHomeRunPercent = eraHomeRun/eraAtBats;
        eraTriplePercent = eraTriples/eraAtBats;
        eraDoublePercent = eraDouble/eraAtBats;
        eraSinglePercent = eraSingle/eraAtBats;
        eraWalkPercent = eraWalk/eraAtBats;
        eraHitByPitchPercent = eraHitByPitch;
        eraStrikeOutPercent = eraStrikeOut/eraAtBats;

        /*std::cout << "ERA Stats \n";
        std::cout << "single percent = " << eraSinglePercent << std::endl;
        std::cout << "double percent = " << eraDoublePercent << std::endl;
        std::cout << "triple percent = " << eraTriplePercent << std::endl;
        std::cout << "homerun percent = " << eraHomeRunPercent << std::endl;
        std::cout <<"walk percent = " << eraWalkPercent << std::endl;
        std::cout << "hit by pitch percent = " << eraHitByPitchPercent << std::endl;
        std::cout << "strike out percent = " << eraStrikeOutPercent << "\n\n\n";*/
    }
    else if(opposingTeamName == "red sox"){
        eraAtBats = 660;
        eraHits = 156;
        eraHomeRun = 21;
        eraTriples = 0;
        eraDouble = 35;
        eraSingle = eraHits - eraHomeRun - eraTriples - eraDouble;
        eraWalk = 52;
        eraHitByPitch = 5;
        eraStrikeOut = 116;

        eraHomeRunPercent = eraHomeRun/eraAtBats;
        eraTriplePercent = eraTriples/eraAtBats;
        eraDoublePercent = eraDouble/eraAtBats;
        eraSinglePercent = eraSingle/eraAtBats;
        eraWalkPercent = eraWalk/eraAtBats;
        eraHitByPitchPercent = eraHitByPitch;
        eraStrikeOutPercent = eraStrikeOut/eraAtBats;

        /*std::cout << "ERA Stats \n";
        std::cout << "single percent = " << eraSinglePercent << std::endl;
        std::cout << "double percent = " << eraDoublePercent << std::endl;
        std::cout << "triple percent = " << eraTriplePercent << std::endl;
        std::cout << "homerun percent = " << eraHomeRunPercent << std::endl;
        std::cout <<"walk percent = " << eraWalkPercent << std::endl;
        std::cout << "hit by pitch percent = " << eraHitByPitchPercent << std::endl;
        std::cout << "strike out percent = " << eraStrikeOutPercent << "\n\n\n";*/
    }
}

