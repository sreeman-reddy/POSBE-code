/*
 * Nicholas Schneider
 * schnei54@purdue.edu
 * baseball project version 1.0
 */

#include "player.h"
#include "game.h"
#include "team.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <random>
#include <chrono>

//the base class is pretty simple not much is going on
Player* Base::returnPlayer(){
    return player;
}
bool Base::hasPlayer(){
    return containsPlayer;
}
void Base::setPlayer(Player* player){
    this->player = player;
    containsPlayer = true;
}
void Base::clearBase(){
    this->player = NULL;
    containsPlayer = false;
}
//this method lets the program know if the player should have a charged run against
QString Base::returnLastResult(){
    if(!(containsPlayer)){
        // this case senerio should never happen. See the moveRunner method below to see
        // why this will never happen.
        std::cout << "the program has crashed due to an empty base\n";
        return NULL;
    }
    return player->lastAtBatResult;
}

QString Base::returnLastPitcherFaced(){
    if(!(containsPlayer)){
        // this case senerio should never happen. See the moveRunner method below to see
        // why this will never happen.
        std::cout << "the program has crashed due to an empty base\n";
        return NULL;
    }
    return player->lastPitcherFaced;
}




Game::Game(Team* home, Team* away, QString homePitcherName, QString awayPitcherName, bool playByPlay, QString directory) {
    homeTeam = home;
    awayTeam = away;
    this->awayPitcherName = awayPitcherName;
    this->homePitcherName = homePitcherName;
    this->playByPlay = playByPlay;
    this->directory = directory;
}

Game::Game(){

}

//this is the core of the engine. This is where the batter and pitcher interaction is played out
//this is where the totallity of the formula comes together and than the random number is
//used to generate what the output is.

QString Game::batterResult(Player* player, Pitcher* pitcher) {

    /*std::cout << "Player Stats \n";
    std::cout << "single percent = " << player->atBatSinglePercent << std::endl;
    std::cout << "double percent = " << player->atBatDoublePercent << std::endl;
    std::cout << "triple percent = " << player->atBatTriplePercent << std::endl;
    std::cout << "homerun percent = " << player->atBatHomeRunPercent << std::endl;
    std::cout <<"walk percent = " << player->atBatWalkPercent << std::endl;
    std::cout << "hit by pitch percent = " << player->atBatHitByPitchPercent << std::endl;
    std::cout << "strike out percent = " << player->atBatStrikeOutPercent << "\n\n\n";*/

    double singlePercent = 100*(player->atBatSinglePercent + pitcher->pitcherSinglePercent)/2;
    double doublePercent = 100*(player->atBatDoublePercent + pitcher->pitcherDoublePercent)/2;
    double triplePercent = 100*(player->atBatTriplePercent + pitcher->pitcherTriplePercent)/2;
    double homerunPercent = 100*(player->atBatHomeRunPercent + pitcher->pitcherHomeRunPercent)/2;
    double walksPercent = 100*(player->atBatWalkPercent + pitcher->pitcherWalkPercent)/2;
    double hitByPitchPercent = 100*(player->atBatHitByPitchPercent + pitcher->pitcherHitByPitchPercent)/2;
    double strikeoutsPercent = 100*(player->atBatStrikeOutPercent + pitcher->pitcherStrikeOutPercent)/2;

    /*std::cout << "Total Stats \n";
    std::cout << "single percent = " << singlePercent << std::endl;
    std::cout << "double percent = " << doublePercent << std::endl;
    std::cout << "triple percent = " << triplePercent << std::endl;
    std::cout << "homerun percent = " << homerunPercent << std::endl;
    std::cout <<"walk percent = " << walksPercent << std::endl;
    std::cout << "hit by pitch percent = " << hitByPitchPercent << std::endl;
    std::cout << "strike out percent = " << strikeoutsPercent << std::endl;*/

    double random = 0;
    random = myRand(0.0, 100.0);

    if (random <= singlePercent) {
        return "single";
    }
    else if (random <= (singlePercent + doublePercent)) {
        return "double";
    }
    else if (random <= (singlePercent + doublePercent + triplePercent)) {
        return "triple";
    }
    else if (random <= (singlePercent + doublePercent + triplePercent + homerunPercent)) {
        return "homerun";
    }
    else if (random <= (singlePercent + doublePercent + triplePercent + homerunPercent + walksPercent)) {
        return "walk";
    }
    else if (random <= (singlePercent + doublePercent + triplePercent + homerunPercent + walksPercent + hitByPitchPercent)) {
        return "hit by pitch";
    }
    else if(random <= (singlePercent + doublePercent + triplePercent + homerunPercent + walksPercent + hitByPitchPercent + strikeoutsPercent)) {
             return "strikeout";
    }
    else if(random >= 98){
        return "error";
    }
    else {
        return "out";
    }    
}

double Game::myRand(double a, double b) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine generator (seed);
    //std::uniform_int_distribution<int> distribution (a,b);
    std::uniform_real_distribution<double> distribution (a,b);
    return distribution(generator);
}

//here the players are advanced to the correct base.
//Example if the player hits a double they are moved to second.
//Also it is important to note this is where the earned runs are charged.
//So if Adam Warren gives up a base hit and than he is pulled from the game
//and than the player who hit the ball scores that run is charged against
//Adam Warren

std::pair<int, int> Game::moveRunner(QString numberOfBases, Player* player, Team* team){
    int runs = 0;
    int earnedRuns = 0;
    if (numberOfBases == "single") {
        if (third.hasPlayer()) {
            if(third.returnLastResult() != "error"){
                QString tempPlayerName = third.returnPlayer()->lastPitcherFaced;
                Pitcher * tempPitcher = team->returnPitcher(tempPlayerName);
                tempPitcher->editPitchingGameStats("", 1);
            }
            runs++;
            third.clearBase();
        }
        if (second.hasPlayer()) {
            if(second.returnLastResult() != "error"){
                QString tempPlayerName = second.returnPlayer()->lastPitcherFaced;
                Pitcher * tempPitcher = team->returnPitcher(tempPlayerName);
                tempPitcher->editPitchingGameStats("", 1);
            }
            runs++;
            second.clearBase();
        }
        if (first.hasPlayer()) {
            second.setPlayer(first.returnPlayer());
            first.clearBase();
        }
        first.setPlayer(player);
    }

    else if (numberOfBases == "double") {
        if (third.hasPlayer()) {
            if(third.returnLastResult() != "error"){
                QString tempPlayerName = third.returnPlayer()->lastPitcherFaced;
                Pitcher * tempPitcher = team->returnPitcher(tempPlayerName);
                tempPitcher->editPitchingGameStats("", 1);
            }
            runs++;
            third.clearBase();
        }
        if (second.hasPlayer()) {
            if(second.returnLastResult() != "error"){
                QString tempPlayerName = second.returnPlayer()->lastPitcherFaced;
                Pitcher * tempPitcher = team->returnPitcher(tempPlayerName);
                tempPitcher->editPitchingGameStats("", 1);
            }
            runs++;
            second.clearBase();
        }
        if (first.hasPlayer()) {
            third.setPlayer(first.returnPlayer());
            first.clearBase();
        }
        second.setPlayer(player);
    }

    else if (numberOfBases == "triple") {
        if (third.hasPlayer()) {
            if(third.returnLastResult() != "error") {
                QString tempPlayerName = third.returnPlayer()->lastPitcherFaced;
                Pitcher * tempPitcher = team->returnPitcher(tempPlayerName);
                tempPitcher->editPitchingGameStats("", 1);
            }
            runs++;
            third.clearBase();
        }
        if (second.hasPlayer()) {
            if (second.returnLastResult() != "error"){
                QString tempPlayerName = second.returnPlayer()->lastPitcherFaced;
                Pitcher * tempPitcher = team->returnPitcher(tempPlayerName);
                tempPitcher->editPitchingGameStats("", 1);
            }
            runs++;
            second.clearBase();
        }
        if (first.hasPlayer()) {
            if(first.returnLastResult() != "error"){
                QString tempPlayerName = first.returnPlayer()->lastPitcherFaced;
                Pitcher * tempPitcher = team->returnPitcher(tempPlayerName);
                tempPitcher->editPitchingGameStats("", 1);
            }
            runs++;
            first.clearBase();
        }
        third.setPlayer(player);
    }

    else if (numberOfBases == "homerun") {
        if (third.hasPlayer()) {
            if(third.returnLastResult() != "error"){
                QString tempPlayerName = third.returnPlayer()->lastPitcherFaced;
                Pitcher * tempPitcher = team->returnPitcher(tempPlayerName);
                tempPitcher->editPitchingGameStats("", 1);
            }
            runs++;
            third.clearBase();
        }
        if (second.hasPlayer()) {
            if(second.returnLastResult() != "error") {
                QString tempPlayerName = second.returnPlayer()->lastPitcherFaced;
                Pitcher * tempPitcher = team->returnPitcher(tempPlayerName);
                tempPitcher->editPitchingGameStats("", 1);
            }
            runs++;
            second.clearBase();
        }
        if (first.hasPlayer()) {
            if(first.returnLastResult() != "error"){
                QString tempPlayerName = first.returnPlayer()->lastPitcherFaced;
                Pitcher * tempPitcher = team->returnPitcher(tempPlayerName);
                tempPitcher->editPitchingGameStats("", 1);
            }
            runs++;
            first.clearBase();
        }
        runs++;
        earnedRuns++;
    }

    else if (numberOfBases == "walk" || numberOfBases == "error" || numberOfBases == "hit by pitch") {
        if (third.hasPlayer() && second.hasPlayer() && first.hasPlayer()) {
            if(third.returnLastResult() != "error"){
                QString tempPlayerName = third.returnPlayer()->lastPitcherFaced;
                Pitcher * tempPitcher = team->returnPitcher(tempPlayerName);
                tempPitcher->editPitchingGameStats(" ", 1);
            }
            runs++;
            third.setPlayer(second.returnPlayer());
            second.setPlayer(first.returnPlayer());
            first.clearBase();
        }
        else if (second.hasPlayer() && first.hasPlayer()) {
            third.setPlayer(second.returnPlayer());
            second.setPlayer(first.returnPlayer());
            first.clearBase();
        }
        else if (first.hasPlayer()) {
            second.setPlayer(first.returnPlayer());
            first.clearBase();
        }
        first.setPlayer(player);
    }

    else if(numberOfBases == "out"){

    }

    std::pair<int, int> returnValue(runs, earnedRuns);
    return returnValue;

}

//here is where the game is actually played

void Game::gameStart() {

    homeScore = 0;
    AwayScore = 0;
    homeHits = 0;
    awayHits = 0;
    homeErrors = 0;
    awayErrors = 0;
    inning = 1;
    homeAtBatIndex = 0;
    awayAtBatIndex = 0;
    gameOver = false;

    first = Base();
    second = Base();
    third = Base();

    homeTeam->startGame(homePitcherName);
    awayTeam->startGame(awayPitcherName);

    homeTeam->pitcher = (homeTeam->startingRotation[0]);
    awayTeam->pitcher = (awayTeam->startingRotation[0]);

    homeTeam->pitcher->startPitcherGame();
    awayTeam->pitcher->startPitcherGame();

    homeTeam->pitcher->pitchedThisGame = true;
    awayTeam->pitcher->pitchedThisGame = true;

    if (playByPlay == true){

        QString playByPlayLocation = directory + "Play_by_Play.rtf";
        gamePlays = new QFile(playByPlayLocation);
        gamePlays->open(QFile::WriteOnly|QFile::Truncate);

        while(!(gameOver)) {
            simulateInningWPBP();
            inning++;
        }
        for (int p = 0; p < 9; p++) {
            homeTeam->battingOrder[p]->endGame();
            awayTeam->battingOrder[p]->endGame();
        }

        QString homePitcherNames[16];
        int homePitcherIndex = 0;
        QString awayPitcherNames[16];
        int awayPitcherIndex = 0;

        for (int y = 0; y < 16; y++){
            Pitcher* tempHome = homeTeam->availablePitchers[y];
            if (tempHome != NULL) {
                if (tempHome->pitchedThisGame && !(containsPlayerName(tempHome->playerName, homePitcherNames, homePitcherIndex))) {
                    tempHome->endPitcherGame();
                    homePitcherNames[homePitcherIndex] = tempHome->playerName;
                    homePitcherIndex++;
                }
            }

            Pitcher* tempAway = awayTeam->availablePitchers[y];
            if (tempAway != NULL) {
                if (tempAway->pitchedThisGame && !(containsPlayerName(tempAway->playerName, awayPitcherNames, awayPitcherIndex))) {
                    tempAway->endPitcherGame();
                    awayPitcherNames[awayPitcherIndex] = tempAway->playerName;
                    awayPitcherIndex++;
                }
            }
        }
        printScore();

        gamePlays->close();
    }
    else{
        while(!(gameOver)) {
            simulateInning();
            inning++;
        }
        for (int p = 0; p < 9; p++) {
            homeTeam->battingOrder[p]->endGame();
            awayTeam->battingOrder[p]->endGame();
        }

        QString homePitcherNames[16];
        int homePitcherIndex = 0;
        QString awayPitcherNames[16];
        int awayPitcherIndex = 0;

        for (int y = 0; y < 16; y++){
            Pitcher* tempHome = homeTeam->availablePitchers[y];
            if (tempHome != NULL) {
                if (tempHome->pitchedThisGame && !(containsPlayerName(tempHome->playerName, homePitcherNames, homePitcherIndex))) {
                    tempHome->endPitcherGame();
                    homePitcherNames[homePitcherIndex] = tempHome->playerName;
                    homePitcherIndex++;
                }
            }

            Pitcher* tempAway = awayTeam->availablePitchers[y];
            if (tempAway != NULL) {
                if (tempAway->pitchedThisGame && !(containsPlayerName(tempAway->playerName, awayPitcherNames, awayPitcherIndex))) {
                    tempAway->endPitcherGame();
                    awayPitcherNames[awayPitcherIndex] = tempAway->playerName;
                    awayPitcherIndex++;
                }
            }
        }
    }
}

//this function will simulate the game with play by play. So there will be data output from
//this function saying what happened in a play by play analysis that will be located
//at the location that is passed at the top

void Game::simulateInningWPBP(){
    int outs = 0;
    first.clearBase();
    second.clearBase();
    third.clearBase();
    int runs = 0;
    int earnedRuns;

    QTextStream plays(gamePlays);

    plays << "\nInning Number = " << inning << "\n";

    homeTeam->pitcher->startInning();
    awayTeam->pitcher->startInning();

    plays << "At Bat: " << awayTeam->TeamName << "\n";
    plays << "\tPitching now is: " << homeTeam->pitcher->playerName << "\n";
    while (outs < 3) {
        Player* atBat = awayTeam->battingOrder[awayAtBatIndex % 9];
        Pitcher* pitch = homeTeam->pitcher;
        QString atBatResult = batterResult(atBat, pitch);
        awayTeam->battingOrder[awayAtBatIndex % 9]->lastAtBatResult = atBatResult;

        if (atBatResult == ("out")) {
            outs++;
            homeTeam->pitcher->addInningPitched();
            plays << "\t\t" << atBat->playerName << " is out\n";
        }
        else if (atBatResult == ("strikeout")) {
            outs++;
            homeTeam->pitcher->addInningPitched();
            plays << "\t\t" << atBat->playerName << " struckout\n";
        }
        else if(atBatResult == ("single") || atBatResult == ("double") || atBatResult == ("triple") || atBatResult == ("homerun")) {
            awayHits++;
            homeTeam->pitcher->addInningHits();
            plays << "\t\t" << atBat->playerName << " hit a " << atBatResult << "\n";
        }
        else if(atBatResult == ("error")){
            homeErrors++;
            plays << "\t\t" << atBat->playerName << " reached on base via an error\n";
        }
        else if(atBatResult == ("walk")){
            plays << "\t\t" << atBat->playerName << " walked\n";
        }

        atBat->lastAtBatResult = atBatResult;
        atBat->lastPitcherFaced = pitch->playerName;
        std::pair<int, int> scoreStats = moveRunner(atBatResult, atBat, homeTeam);
        int scored = scoreStats.first;
        earnedRuns = scoreStats.second;
        atBat->editGameStats(atBatResult, scored);
        homeTeam->pitcher->editPitchingGameStats(atBatResult, earnedRuns);
        awayAtBatIndex++;
        runs += scored;
        homeTeam->pitcher->addInningRuns(runs);
        bool pitcherChange = shouldChangePitcher(homeTeam, outs, homeTeam->pitcherIndex);
        if (pitch->playerName != homeTeam->pitcher->playerName){
            plays << "\tPitching now is: " << homeTeam->pitcher->playerName << "\n";
        }
    }
    awayInnings.push_back(runs);
    AwayScore += runs;

    plays << awayTeam->TeamName << " = " << AwayScore << "    ";
    plays << homeTeam->TeamName << " = " << homeScore << "\n\n";

    if (inning == 9 && homeScore > AwayScore) {
        gameOver = true;
        homeInnings.push_back(0);
        return;
    }
    outs = 0;
    runs = 0;

    first.clearBase();
    second.clearBase();
    third.clearBase();

    plays << "At Bat: " << homeTeam->TeamName << "\n";
    plays << "\tPitching now is: " << awayTeam->pitcher->playerName << "\n";

    while (outs < 3) {
        Player* atBat = homeTeam->battingOrder[homeAtBatIndex % 9];
        Pitcher* pitch = awayTeam->pitcher;
        QString atBatResult = batterResult(atBat, pitch);
        atBat->lastAtBatResult = atBatResult;

        if (atBatResult == ("out")) {
            outs++;
            homeTeam->pitcher->addInningPitched();
            plays << "\t\t" << atBat->playerName << " is out\n";
        }
        else if (atBatResult == ("strikeout")) {
            outs++;
            homeTeam->pitcher->addInningPitched();
            plays << "\t\t" << atBat->playerName << " struckout\n";
        }
        else if(atBatResult == ("single") || atBatResult == ("double") || atBatResult == ("triple") || atBatResult == ("homerun")) {
            homeHits++;
            homeTeam->pitcher->addInningHits();
            plays << "\t\t" << atBat->playerName << " hit a " << atBatResult << "\n";
        }
        else if(atBatResult == ("error")){
            awayErrors++;
            plays << "\t\t" << atBat->playerName << " reached base via an error\n";
        }
        else if(atBatResult == ("walk")){
            plays << "\t\t" << atBat->playerName << " walked\n";
        }

        atBat->lastAtBatResult = atBatResult;
        atBat->lastPitcherFaced = pitch->playerName;
        std::pair<int, int> scoreStats = moveRunner(atBatResult, atBat, awayTeam);
        int scored = scoreStats.first;
        int earnedRuns = scoreStats.second;


        atBat->editGameStats(atBatResult, scored);

        awayTeam->pitcher->editPitchingGameStats(atBatResult, earnedRuns);
        homeAtBatIndex++;

        //std::cout << "edit stats";
        runs += scored;
        homeScore += scored;
        awayTeam->pitcher->addInningRuns(runs);

        if(inning > 8 && homeScore > AwayScore) {
            gameOver = true;
            break;
        }
        bool pitcherChange = shouldChangePitcher(awayTeam, outs, awayTeam->pitcherIndex);
        if (pitch->playerName != awayTeam->pitcher->playerName){
            plays << "\tPitching now is: " << awayTeam->pitcher->playerName << "\n";
        }
    }
    homeInnings.push_back(runs);
    //homeScore += runs;
    plays << awayTeam->TeamName << " = " << AwayScore << "    ";
    plays << homeTeam->TeamName << " = " << homeScore << "\n\n";

    if(inning > 8 && homeScore != AwayScore) {
        gameOver = true;
    }
}

//same as function before just without the play by play

void Game::simulateInning(){
    int outs = 0;
    first.clearBase();
    second.clearBase();
    third.clearBase();
    int runs = 0;
    int earnedRuns;

    homeTeam->pitcher->startInning();
    awayTeam->pitcher->startInning();

    while (outs < 3) {

        Player* atBat = awayTeam->battingOrder[awayAtBatIndex % 9];
        Pitcher* pitch = homeTeam->pitcher;

        QString atBatResult = batterResult(atBat, pitch);
        awayTeam->battingOrder[awayAtBatIndex % 9]->lastAtBatResult = atBatResult;
        awayTeam->battingOrder[awayAtBatIndex % 9]->lastPitcherFaced = pitch->playerName;


        if (atBatResult == ("out") || atBatResult == ("strikeout")) {
            outs++;
            homeTeam->pitcher->addInningPitched();
        }
        else if(atBatResult == ("single") || atBatResult == ("double") || atBatResult == ("triple") || atBatResult == ("homerun")) {
            awayHits++;
            homeTeam->pitcher->addInningHits();
        }
        else if(atBatResult == ("error")){
            homeErrors++;
        }
        atBat->lastAtBatResult = atBatResult;
        atBat->lastPitcherFaced = pitch->playerName;
        std::pair<int, int> scoreStats = moveRunner(atBatResult, atBat, homeTeam);
        int scored = scoreStats.first;
        earnedRuns = scoreStats.second;
        atBat->editGameStats(atBatResult, scored);
        homeTeam->pitcher->editPitchingGameStats(atBatResult, earnedRuns);
        awayAtBatIndex++;
        runs += scored;
        homeTeam->pitcher->addInningRuns(runs);
        shouldChangePitcher(homeTeam, outs, homeTeam->pitcherIndex);
    }
    awayInnings.push_back(runs);
    AwayScore += runs;

    outs = 0;
    runs = 0;

    if (inning == 9 && homeScore > AwayScore) {
        gameOver = true;
        homeInnings.push_back(0);
        return;
    }

    first.clearBase();
    second.clearBase();
    third.clearBase();

    while (outs < 3 ) {
        Player* atBat = homeTeam->battingOrder[homeAtBatIndex % 9];
        Pitcher* pitch = awayTeam->pitcher;
        QString atBatResult = batterResult(atBat, pitch);
        atBat->lastAtBatResult = atBatResult;

        if (atBatResult == "out" || atBatResult == "strikeout") {
            outs++;
            awayTeam->pitcher->addInningPitched();
        }
        else if(atBatResult == "single" || atBatResult == "double" || atBatResult == "triple" || atBatResult == "homerun") {
            homeHits++;
            awayTeam->pitcher->addInningHits();
        }
        else if(atBatResult == "error"){
            awayErrors++;
        }
        atBat->lastAtBatResult = atBatResult;
        atBat->lastPitcherFaced = pitch->playerName;
        std::pair<int, int> scoreStats = moveRunner(atBatResult, atBat, awayTeam);
        int scored = scoreStats.first;
        earnedRuns = scoreStats.second;

        atBat->editGameStats(atBatResult, scored);

        awayTeam->pitcher->editPitchingGameStats(atBatResult, earnedRuns);
        homeAtBatIndex++;

        runs += scored;
        homeScore += scored;
        awayTeam->pitcher->addInningRuns(runs);

        if(inning > 8 && homeScore > AwayScore) {
            gameOver = true;
            break;
        }
        shouldChangePitcher(awayTeam, outs, awayTeam->pitcherIndex);
    }
    homeInnings.push_back(runs);

    if(inning > 8 && homeScore != AwayScore) {
        gameOver = true;
    }
}

//this is a function determines whethe the pitcher neeeds to be changed from the game and
//a new pitcher needs to come in. It also calls the change pitcher function when it thinks the
//pitcher should be changed

bool Game::shouldChangePitcher(Team* team, int outs, int index){
    if(team->pitcher->pitcherType == "starter") {
        if(team->pitcher->gamePitchInnings >= 6 && team->pitcher->gamePitchRunsAllowed >= 6) {
            changePitcher(team, "relief", index);
            return true;
        }
        else if ((team->pitcher->inningRuns > 4 && team->pitcher->inningHits > 8) && inning > 3) {
            changePitcher(team, "relief", index);
            return true;
        }
        else if ((team->pitcher->inningRuns > 2 || team->pitcher->inningHits > 4) && inning >= 6) {
            changePitcher(team, "relief", index);
            return true;
        }
        else if (team->pitcher->gamePitchInnings >= 10){
            changePitcher(team, "relief", index);
            return true;
        }
        else if (abs(homeScore - AwayScore) < 3 && inning >= 7 && team->pitcher->gamePitchHits > 7 && third.hasPlayer() && outs < 2){
            if(inning == 8){
                changePitcher(team, "setup", index);
                return true;
            }
            else if(inning == 9){
                changePitcher(team, "closer", index);
                return true;
            }
            else {
                changePitcher(team, "relief", index);
                return true;
            }
        }
        else if (inning > 7 && team->pitcher->gamePitchHits > 5 && outs == 3){
            if(inning == 8){
                changePitcher(team, "setup", index);
                return true;
            }
            else if(inning == 9){
                changePitcher(team, "closer", index);
                return true;
            }
            else {
                changePitcher(team, "relief", index);
                return true;
            }
        }
        return false;
    }
    if(team->pitcher->pitcherType == "relief" || team->pitcher->pitcherType == "setup" || team->pitcher->pitcherType == "closer"){
        if(team->pitcher->inningRuns >= 5) {
            if(inning == 8){
                changePitcher(team, "setup", index);
            }
            else if(inning == 9){
                changePitcher(team, "closer", index);
            }
            else {
                changePitcher(team, "relief", index);
            }
        }
        else if(team->pitcher->gamePitchInnings > 2 && outs == 3){
            if(inning == 8){
                changePitcher(team, "setup", index);
            }
            else if(inning == 9){
                changePitcher(team, "closer", index);
            }
            else {
                changePitcher(team, "relief", index);
            }
        }
        if (abs(homeScore - AwayScore) <= 4){
            if (inning == 7 && team->pitcher->inningHits >= 3){
                changePitcher(team, "relief", index);
            }
            else if (inning == 8 && team->pitcher->inningHits >= 2){
                changePitcher(team, "setup", index);
            }
            else if (inning >= 9 && (team->pitcher->inningHits >= 2 || team->pitcher->inningRuns >= 2)){
                changePitcher(team, "relief", index);
            }
        }
        else {
            if (inning == 7 && team->pitcher->inningHits >= 5){
                changePitcher(team, "relief", index);
            }
            else if (inning == 8 && team->pitcher->inningHits >= 5){
                changePitcher(team, "relief", index);
            }
            else if (inning >= 9 && (team->pitcher->inningHits >= 5 || team->pitcher->inningRuns >= 2)){
                changePitcher(team, "relief", index);
            }
        }

    }
}

//this changes the pitcher based on rules that we defined.
//Its hard to explain those rules but basically what happens
//is if a closer is called the closer is the pitcher put in the game
//if the setup guy is called he is put into the game
//if a relief pitcher called one of them is put into the game
//if all the pitchers are used than than the starters are used and once
//all of them are used the order restarts

void Game::changePitcher(Team *team, std::string pitcherNeeded, int index){

    if(pitcherNeeded == "closer"){
        if(!(team->availablePitchers[1]->pitchedThisGame)){
            team->pitcher = team->availablePitchers[1];
            team->pitcherIndex++;
            team->pitcher->pitchedThisGame = true;
            team->pitcher->startPitcherGame();
        }
        changePitcher(team, "relief", 3);
    }

    else if(pitcherNeeded == "setup"){
        if(!(team->availablePitchers[2]->pitchedThisGame)){
            team->pitcher = team->availablePitchers[2];
            team->pitcherIndex++;
            team->pitcher->pitchedThisGame = true;
            team->pitcher->startPitcherGame();
        }
        changePitcher(team, "relief", 3);
    }

    else if(pitcherNeeded == "relief"){
        if (index < 8){
            if(!(team->availablePitchers[index]->pitchedThisGame)){
                team->pitcher = team->availablePitchers[index];
                team->pitcherIndex++;
                team->pitcher->pitchedThisGame = true;
                team->pitcher->startPitcherGame();
            }
            else {
                changePitcher(team, "relief", index+1);
            }
        }
        else {
            changePitcher(team, "starter", index);
       }
    }

    else if(pitcherNeeded == "starter"){
        if (index < 13){
            if(!(team->availablePitchers[index]->pitchedThisGame)){
                team->pitcher = team->availablePitchers[index];
                team->pitcherIndex++;
                team->pitcher->pitchedThisGame = true;
                team->pitcher->startPitcherGame();
            }
            else {
                changePitcher(team, "starter", index+1);
            }
        }
        else {
            changePitcher(team, "any", 0);
       }
    }
    else {
        team->pitcher = team->availablePitchers[index];
        team->pitcherIndex++;
        team->pitcher->pitchedThisGame = true;
        team->pitcher->endGame();
        team->pitcher->startPitcherGame();
    }
}

void Game::printScore() {
    if (playByPlay == true) {
        std::cout.width(40);
        //std::cout << awayTeam->TeamName << " @ ";
        //std::cout << homeTeam->TeamName << "\n";
        std::cout.width(50);
        std::cout << homeTeam->StadiumName << "\n";

        printf("    ");
        for (int i = 0; i < awayInnings.size(); i++) {
            std::cout.width(5);
            std::cout << i+1;
        }
        std::cout.width(8);
        std::cout << "Runs";
        std::cout.width(7);
        std::cout << "Hits";
        std::cout.width(10);
        std::cout << "Errors\n";
        std::cout.width(4);
        std::cout << awayTeam->abbreviation;
        std::cout.width(5);
        for (int l = 0; l < awayInnings.size(); l++) {
            std::cout.width(5);
            std::cout << awayInnings.at(l);
        }
        std::cout.width(8);
        std::cout << AwayScore;
        std::cout.width(7);
        std::cout << awayHits;
        std::cout.width(10);
        std::cout << awayErrors << "\n";
        std::cout.width(4);
        std::cout << homeTeam->abbreviation;
        for (int l = 0; l < homeInnings.size(); l++) {
            std::cout.width(5);
            std::cout << homeInnings.at(l);
        }
        std::cout.width(8);
        std::cout << homeScore;
        std::cout.width(7);
        std::cout << homeHits;
        std::cout.width(10);
        std::cout << homeErrors << "\n";
        std::cout << "\n";
        return;
    }
    else {
        std::cout.width(40);
        //std::cout << awayTeam->TeamName << " @ ";
        //std::cout << homeTeam->TeamName << "\n";
        std::cout.width(50);
        std::cout << homeTeam->StadiumName << "\n";

        printf("    ");
        for (int i = 0; i < awayInnings.size(); i++) {
            std::cout.width(5);
            std::cout << i+1;
        }
        std::cout.width(8);
        std::cout << "Runs";
        std::cout.width(7);
        std::cout << "Hits";
        std::cout.width(10);
        std::cout << "Errors\n";
        std::cout.width(4);
        std::cout << awayTeam->abbreviation;
        std::cout.width(5);
        for (int l = 0; l < awayInnings.size(); l++) {
            std::cout.width(5);
            std::cout << awayInnings.at(l);
        }
        std::cout.width(8);
        std::cout << AwayScore;
        std::cout.width(7);
        std::cout << awayHits;
        std::cout.width(10);
        std::cout << awayErrors << "\n";
        std::cout.width(4);
        std::cout << homeTeam->abbreviation;
        for (int l = 0; l < homeInnings.size(); l++) {
            std::cout.width(5);
            std::cout << homeInnings.at(l);
        }
        std::cout.width(8);
        std::cout << homeScore;
        std::cout.width(7);
        std::cout << homeHits;
        std::cout.width(10);
        std::cout << homeErrors << "\n";
        std::cout << "\n";
        return;
    }

}

void Game::printStats() {
    homeTeam->printGameStats();
    awayTeam->printGameStats();
}

bool Game::containsPlayerName(QString playerName, QString pitcherNames[16], int index){
     for (int i = 0; i < index; i++){
         if (playerName == pitcherNames[i]){
             return true;
         }
     }
     return false;
}
