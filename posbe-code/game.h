/*
 * Nicholas Schneider
 * schnei54@purdue.edu
 * March 17, 2016
 * baseball project version 1.0
 */
/*
 * this is the most important class of the entire project:
 * this is where the game is "played"
 */

#ifndef GAME
#define GAME
#include "player.h"
#include "pitcher.h"
#include "team.h"
#include <vector>

/* since base is not a big class I decided to embed it in the game.h and game.cpp
 * Base does exactly what you would expect it to do: hold a instance variable of
 * the player class, in other words it holds a player
 */

class Base {
    bool containsPlayer;
    Player* player;

public:

    Base(){
        player = NULL;
        containsPlayer = false;
    }
    void setPlayer(Player * player);
    void startInning();
    Player* returnPlayer();
    bool hasPlayer();
    void clearBase();
    QString returnLastResult();
    QString returnLastPitcherFaced();
};

class Game
{
public:
    Game(Team* home, Team* away, QString homePitcherName, QString awayPitcherName, bool playByPlay, QString directory);
    Game();
    void gameStart();
    void simulateInning();
    void simulateInningWPBP();
    QString batterResult(Player* player, Pitcher* pitcher);
    std::pair<int, int> moveRunner(QString numberOfBases, Player* player, Team* team);
    bool shouldChangePitcher(Team* team, int outs, int index);
    void changePitcher(Team* team, std::string typeNeeded, int index);
    double myRand(double n, double randInt);
    void printScore();
    void printStats();
    bool containsPlayerName(QString playerName, QString pitcherNames[16], int index);

    QString directory;
    int inning;
    int homeScore;
    int AwayScore;
    int homeHits;
    int awayHits;
    int homeErrors;
    int awayErrors;
    Team* homeTeam;
    Team* awayTeam;
    QString awayPitcherName;
    QString homePitcherName;
    bool playByPlay;

    std::vector<int> homeInnings;
    std::vector<int> awayInnings;

    bool firstBase;
    bool secondBase;
    bool thirdBase;
    bool home;
    bool gameOver;

    Pitcher* onMound;
    Player batter;
    int homeAtBatIndex;
    int awayAtBatIndex;

    int index;

    Base first;
    Base second;
    Base third;

    QFile* gamePlays;

};

#endif // GAME

