/*
 * Nicholas Schneider
 * schnei54@purdue.edu
 * baseball project version 1.0
 */

#ifndef TEAM
#define TEAM
#include "era.h"
#include "player.h"
#include "pitcher.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <qtextstream.h>
#include <QFile>

#include <fstream>
#include <iostream>
#include <qtextstream.h>
#include <QFile>


class Team {
public:
    std::string destination;

    QString TeamName;
    std::string abbreviation;
    std::string TeamCountry;
    char* TeamState;
    char* TeamTown;
    int TeamMaxSalary;
    int TeamCurrentSalary;
    int TeamGamesPlayed;
    int TeamWins;
    int TeamLosses;
    Player* battingOrder[9];
    Pitcher* startingRotation[9];
    Pitcher* bullpen[7];
    Pitcher* availablePitchers[16];
    Pitcher* pitchers[16];
    int pitcherIndex;
    Era* era;


    std::string StadiumName;
    char* StadiumLocation;
    int capacity;

    Player* catcher;
    Player* firstBase;
    Player* secondBase;
    Player* shortStop;
    Player* thirdBase;
    Player* leftField;
    Player* rightField;
    Player* centerField;
    Pitcher* pitcher;
    Player* dh;

    QFile* batterFile;
    QFile* pitcherFile;

    QFile* batterSingleFile;
    QFile* batterDoubleFile;
    QFile* batterTripleFile;
    QFile* batterHomeRunFile;
    QFile* batterWalksFile;
    QFile* batterStrikeOutFile;
    QFile* batterHitByPitchFile;

    QFile* pitcherSingleFile;
    QFile* pitcherDoubleFile;
    QFile* pitcherTripleFile;
    QFile* pitcherHomeRunFile;
    QFile* pitcherWalksFile;
    QFile* pitcherStrikeOutFile;
    QFile* pitcherHitByPitchFile;

    //Team(char* name, char* country, char* state, std::vector<Player> players);
    Team(int i, std::string location);
    Team();
    void openOutputFile();
    void closeOutputFile();
    void printGameStats();
    void printSeasonStats();
    void startSeason();
    void startGame(QString pitcherName);
    bool containsPlayerName(QString playerName, QString pitcherNames[16], int index);
    Pitcher* returnPitcher(QString pitcherName);
    std::ofstream* outputFile;

    bool createDirectories();

};

#endif // TEAM

