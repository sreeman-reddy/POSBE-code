/*
 * Nicholas Schneider
 * schnei54@purdue.edu
 * baseball project version 1.0
 */

#include "pitcher.h"
#include <math.h>

Pitcher::Pitcher(QString name, int position, std::string handiness, int age, int number, std::string nationality)
    : Player (name, position, handiness, age, number, nationality)

{
    playerName = name;
    position = position;
    handiness = handiness;
    age = age;
    number = number;
}

Pitcher::Pitcher() {
    Era* era = new Era();
    pitcherHomeRunPercent = era->eraHomeRunPercent;
    pitcherTriplePercent = era->eraTriplePercent;
    pitcherDoublePercent = era->eraDoublePercent;
    pitcherSinglePercent = era->eraSinglePercent;
    pitcherStrikeOutPercent = era->eraStrikeOutPercent;
    pitcherWalkPercent = era->eraWalkPercent;
    pitcherHitByPitchPercent = era->eraHitByPitchPercent;
    playerName = "Nick";
    pitcherType = "relief";

}

// here is where all the pitcher data is created to be used to average with the batter

void Pitcher::createPitchingAverages() {
    pitcherHomeRunPercent = pitcherCareerHomeruns/pitcherCareerBattersFaced;
    pitcherTriplePercent = pitcherCareerTriples/pitcherCareerBattersFaced;
    pitcherDoublePercent = pitcherCareerDoubles/pitcherCareerBattersFaced;
    pitcherSinglePercent = (pitcherCareerHits - pitcherCareerHomeruns - pitcherCareerTriples - pitcherCareerDoubles)/pitcherCareerBattersFaced;
    pitcherStrikeOutPercent = pitcherCareerStrikeouts/pitcherCareerBattersFaced ;
    pitcherWalkPercent = pitcherCareerWalks/pitcherCareerBattersFaced;
    pitcherHitByPitchPercent = pitcherCareerHitByPitch/pitcherCareerBattersFaced;
}

//edits the pitcher stats

void Pitcher::editPitchingGameStats(QString atBatResult, int runs) {

    if (atBatResult == "single") {
        gamePitchSingles += 1;
    }

    else if (atBatResult == "double") {
        gamePitchDoubles += 1;
    }

    else if (atBatResult == "triple") {
        gamePitchTriples += 1;
    }

    else if (atBatResult == "homerun") {
        gamePitchHomeRuns += 1;
    }

    else if (atBatResult == "walk") {
        gamePitchWalks += 1;

    }
    else if (atBatResult == "hit by pitch"){
        gamePitchHitBatters += 1;
    }
    else if (atBatResult == "strikeout") {
        gamePitchStrikeouts += 1;
    }

    gamePitchRunsAllowed += runs;
    gamePitchPlateAppereances++;
    calcGamePitchingStats();
}

void Pitcher::addInningPitched() {
   gamePitchInnings += 1.0/3.0;
}

void Pitcher::calcGamePitchingStats() {
    gamePitchHits = gamePitchSingles + gamePitchDoubles + gamePitchTriples + gamePitchHomeRuns;
    gamePitchERA = 9.0 * gamePitchRunsAllowed / gamePitchInnings;
    gamePitchAtBats = gamePitchPlateAppereances - gamePitchWalks - gamePitchHitBatters;

}
 void Pitcher::clearGameStats(){
     gamePitchERA = 0;
     gamePitchInnings = 0;
     gamePitchSingles = 0;
     gamePitchDoubles = 0;
     gamePitchTriples = 0;
     gamePitchHomeRuns = 0;
     gamePitchStrikeouts = 0;
     gamePitchWalks = 0;
     gamePitchHitBatters = 0;
     gameBattersFaced = 0;
     gamePitchHits = 0;
     gamePitchRunsAllowed = 0;
     gamePitchPlateAppereances = 0;
     gamePitches = 0;
     gamePitchAtBats = 0;

 }

 void Pitcher::addInningHits() {
     inningHits++;
 }

 void Pitcher::addInningRuns(int runs){
     inningRuns += runs;
 }

 void Pitcher::startInning(){
     inningHits = 0;
     inningRuns = 0;
 }

void Pitcher::startPitcherGame(){
    inningRuns = 0;
    inningHits = 0;
    inningBattersFaced = 0;

    gamePitchERA = 0;
    gamePitchInnings = 0;
    gamePitchSingles = 0;
    gamePitchDoubles = 0;
    gamePitchTriples = 0;
    gamePitchHomeRuns = 0;
    gamePitchStrikeouts = 0;
    gamePitchWalks = 0;
    gamePitchHitBatters = 0;
    gameBattersFaced = 0;
    gamePitchHits = 0;
    gamePitchRunsAllowed = 0;
    gamePitchPlateAppereances = 0;
    gamePitches = 0;
    gamePitchAtBats = 0;

}

void Pitcher::startPitcherSeason(){
    seasonPitchERA = 0;
    seasonPitchInnings = 0;
    seasonPitchSingles = 0;
    seasonPitchDoubles = 0;
    seasonPitchTriples = 0;
    seasonPitchHomeRuns = 0;
    seasonPitchStrikeouts = 0;
    seasonPitchWalks = 0;
    seasonPitchHitBatters = 0;
    seasonBattersFaced = 0;
    seasonPitchHits = 0;
    seasonPitchRunsAllowed = 0;
    seasonPitchPlateAppereances = 0;
    seasonPitches = 0;
    seasonPitchAtBats = 0;
}

// this is just flushing the data out of the game into the season variables

void Pitcher::endPitcherGame(){
    seasonPitchInnings += gamePitchInnings;
    seasonPitchSingles += gamePitchSingles;
    seasonPitchDoubles += gamePitchDoubles;
    seasonPitchTriples += gamePitchTriples;
    seasonPitchHomeRuns += gamePitchHomeRuns;
    seasonPitchStrikeouts += gamePitchStrikeouts;
    seasonPitchWalks += gamePitchWalks;
    seasonPitchHitBatters += gamePitchHitBatters;
    seasonBattersFaced += gameBattersFaced;
    seasonPitchHits += gamePitchHits;
    seasonPitchRunsAllowed += gamePitchRunsAllowed;
    seasonPitchPlateAppereances += gamePitchPlateAppereances;
    seasonPitches = 0;
    seasonPitchAtBats += gamePitchAtBats;
    seasonPitchERA = ((seasonPitchRunsAllowed)/(seasonPitchInnings)) * 9.0;

    inningRuns = 0;
    inningHits = 0;
    inningBattersFaced = 0;

    /*gamePitchERA = 0;
    gamePitchInnings = 0;
    gamePitchSingles = 0;
    gamePitchDoubles = 0;
    gamePitchTriples = 0;
    gamePitchHomeRuns = 0;
    gamePitchStrikeouts = 0;
    gamePitchWalks = 0;
    gamePitchHitBatters = 0;
    gameBattersFaced = 0;
    gamePitchHits = 0;
    gamePitchRunsAllowed = 0;
    gamePitchPlateAppereances = 0;
    gamePitches = 0;
    gamePitchAtBats = 0;*/
}

//this prints the calculated data points for the pitcher (mainly to be used if game data looks weird)

void Pitcher::printPitcherPercents(){
    //std::cout << "pitcher = " << playerName << "\n";
    std::cout << "single Percent" << pitcherSinglePercent << "\n";
    std::cout << "double Percent" << pitcherDoublePercent << "\n";
    std::cout << "triple Percent" << pitcherTriplePercent << "\n";
    std::cout << "homeRun Percent" << pitcherHomeRunPercent << "\n";
    std::cout << "strikeOut Percent" << pitcherStrikeOutPercent << "\n";
}
