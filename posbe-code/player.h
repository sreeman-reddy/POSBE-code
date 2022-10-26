/*
 * Nicholas Schneider
 * schnei54@purdue.edu
 * baseball project version 1.0
 */

#ifndef PLAYER
#define PLAYER
#include <string>
#include <string.h>
#include "era.h"
#include <stdlib.h>
#include <stdio.h>
#include <qtextstream.h>
#include <QFile>

class Player {

    public:
        QString playerName;

        Player();
        Player(QString name, int position, std::string handiness, int age, int number, std::string Nationality);
        void createBattingAverages();
        void editGameStats(QString atBatResults, int runs);
        void endGame();
        void startGame();

        Era* era;
        int position;
        int firstYear;
        int lastYear;
        std::string handiness;
        int playerNumber;
        int age;
        std::string nationality;
        std::string hometown;
        int height;

        //batting statistics
        QString lastAtBatResult;
        QString lastPitcherFaced;
        int gameAtBatHomeRun;
        int gameAtBatTriple;
        int gameAtBatDouble;
        int gameAtBatSingle;
        int gameAtBatStrikeOut;
        int gameAtBatWalk;
        int gameAtBatHitByPitch;
        int gameAtBatRuns;
        int gamePlateAppereances;
        double gameAtBatHits;
        double gameAtBats;
        double gameBattingAverage;
        double gameOBP;
        double gameSLG;
        double gameOPS;
        double gameERA;

        double seasonAtBatPlateAppereances;
        double seasonAtBats;
        double seasonAtBatStrikeouts;
        double seasonAtBatWalks;
        double seasonAtBatHits;
        double seasonAtBatRuns;
        double seasonAtBatHomeruns;
        double seasonAtBatSingles;
        double seasonAtBatDoubles;
        double seasonAtBatTriples;
        double seasonAtBatRBI;
        double seasonAtBatHitByPitch;
        double seasonStolenBases;
        double seasonCaughtStealing;
        double seasonBattingAverage;
        double seasonOBP;
        double seasonSLG;
        double seasonOPS;
        double seasonERA;

        double careerAtBats;
        double careerAtBatStrikeouts;
        double careerAtBatWalks;
        double careerAtBatHits;
        double careerAtBatRuns;
        double careerAtBatHomeruns;
        double careerAtBatSigles;
        double careerAtBatDoubles;
        double careerAtBatTriples;
        double careerAtBatRBI;
        double careerAtBatHitByPitch;
        double careerStolenBases;
        double careerCaughtStealing;

        double atBatHomeRunPercent;
        double atBatTriplePercent;
        double atBatDoublePercent;
        double atBatSinglePercent;
        double atBatStrikeOutPercent;
        double atBatWalkPercent;
        double atBatHitByPitchPercent;

        void addGameAtBat();
        void addGameSingle();
        void addGameDouble();
        void addGameTriple();
        void addGameHomeRun();
        void addGameRBI(int i);
        void addGameBaseOnBalls();
        void addGameHitByPitch();
        void addGameStrikeout();
        void calcGameHits();
        void startSeason();


};

#endif // PLAYER

