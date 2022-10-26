/*
 * Nicholas Schneider
 * schnei54@purdue.edu
 * baseball project version 1.0
 */

#include "player.h"
#include <math.h>
#include <string.h>

Player::Player(QString name, int position, std::string handiness, int age, int number, std::string nationality){
    playerName = name;
    position = position;
    handiness = handiness;
    age = age;
    number = number;
    nationality = nationality;
    era = new Era();
}

Player::Player() {
    era = new Era();
}

//this is where half of the pitcher batter interaction happens. All of the batting data is normalized
//in this function. This gets ride of the differences in pitchers that the batter has faced that season
//it allows the pitcher and batter interaction to based just on those two players

void Player::createBattingAverages() {
    double careerAtBatSingles = careerAtBatHits - careerAtBatHomeruns - careerAtBatTriples - careerAtBatDoubles;
    atBatHomeRunPercent = 2*(careerAtBatHomeruns / careerAtBats) - era->eraHomeRunPercent;
    atBatTriplePercent =2*(careerAtBatTriples / careerAtBats) - era->eraTriplePercent;
    atBatDoublePercent = 2*(careerAtBatDoubles / careerAtBats) - era->eraDoublePercent;
    atBatSinglePercent = 2*(careerAtBatSingles / careerAtBats) - era->eraSinglePercent;
    atBatStrikeOutPercent = 2*(careerAtBatStrikeouts / careerAtBats) - era->eraStrikeOutPercent;
    atBatWalkPercent = 2*(careerAtBatWalks / careerAtBats) - era->eraWalkPercent;
    atBatHitByPitchPercent = 2*(careerAtBatHitByPitch / careerAtBats) - era->eraHitByPitchPercent;
}

//This is the function that edits the in game stats

void Player::editGameStats(QString atBatResult, int runs) {

    if (atBatResult == "single") {
        gameAtBatSingle += 1;
    }

    else if (atBatResult == "double") {
        gameAtBatDouble += 1;
    }

    else if (atBatResult == "triple") {
        gameAtBatTriple += 1;
    }

    else if (atBatResult == "homerun") {
        gameAtBatHomeRun += 1;
    }

    else if (atBatResult == "walk") {
        gameAtBatWalk += 1;

    }
    else if (atBatResult == "hit by pitch"){
        gameAtBatHitByPitch += 1;
    }
    else if (atBatResult == "strikeout") {
        gameAtBatStrikeOut += 1;
    }
    gameAtBatRuns += runs;
    gamePlateAppereances++;
    calcGameHits();
}

// some of the player stastics we found needed to be calculated using formulas and those are here:
//OBS = on base percentage
//SLG = slugging percent
//OPS = SLG + OBS

void Player::calcGameHits() {
    gameAtBatHits = gameAtBatSingle + gameAtBatDouble + gameAtBatTriple + gameAtBatHomeRun;
    gameAtBats = gamePlateAppereances - gameAtBatWalk - gameAtBatHitByPitch;
    gameBattingAverage = gameAtBatHits/ gameAtBats;
    gameOBP = (gameAtBatHits + gameAtBatWalk + gameAtBatHitByPitch) / gamePlateAppereances;
    gameSLG = (gameAtBatSingle + 2*gameAtBatDouble + 3*gameAtBatTriple + 4*gameAtBatHomeRun) / gameAtBats;
    gameOPS = gameOBP + gameSLG;
}

//same as pitcher end game this flushed all of the game data into the season data

void Player::endGame() {
    seasonAtBatHomeruns += gameAtBatHomeRun;
    seasonAtBatTriples += gameAtBatTriple;
    seasonAtBatDoubles += gameAtBatDouble;
    seasonAtBatSingles += gameAtBatSingle;
    seasonAtBatStrikeouts += gameAtBatStrikeOut;
    seasonAtBatWalks += gameAtBatWalk;
    seasonAtBatHitByPitch += gameAtBatHitByPitch;
    seasonAtBatRuns += gameAtBatRuns;
    seasonAtBatPlateAppereances += gamePlateAppereances;
    seasonAtBatHits = seasonAtBatSingles + seasonAtBatDoubles + seasonAtBatTriples + seasonAtBatHomeruns;
    seasonAtBats = seasonAtBatPlateAppereances - seasonAtBatWalks - seasonAtBatHitByPitch;
    seasonBattingAverage = (seasonAtBatHits)/(seasonAtBats);
    seasonOBP = (seasonAtBatHits + seasonAtBatWalks + seasonAtBatHitByPitch) / seasonAtBatPlateAppereances;
    seasonSLG = (seasonAtBatSingles + 2*seasonAtBatDoubles + 3*seasonAtBatTriples + 4*seasonAtBatHomeruns) / seasonAtBats;
    seasonOPS = seasonOBP + seasonSLG;
}

void Player::startGame() {
    gameAtBatHomeRun = 0;
    gameAtBatTriple = 0;
    gameAtBatDouble = 0;
    gameAtBatSingle = 0;
    gameAtBatStrikeOut = 0;
    gameAtBatWalk = 0;
    gameAtBatHitByPitch = 0;
    gameAtBatRuns = 0;
    gamePlateAppereances = 0;
    gameAtBatHits = 0;
    gameAtBats = 0;
    gameBattingAverage = 0;
    gameOBP = 0;
    gameSLG = 0;
    gameOPS = 0;
}

void Player::startSeason(){
    seasonAtBatPlateAppereances = 0;
    seasonAtBats = 0;
    seasonAtBatStrikeouts = 0;
    seasonAtBatWalks = 0;
    seasonAtBatHits = 0;
    seasonAtBatRuns = 0;
    seasonAtBatHomeruns = 0;
    seasonAtBatSingles = 0;
    seasonAtBatDoubles = 0;
    seasonAtBatTriples = 0;
    seasonAtBatRBI = 0;
    seasonAtBatHitByPitch = 0;
    seasonStolenBases = 0;
    seasonCaughtStealing = 0;
    seasonBattingAverage = 0;
    seasonERA = 0;
    seasonOBP = 0;
    seasonSLG = 0;
    seasonOPS = 0;

}
