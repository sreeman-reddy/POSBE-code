/*
 * Nicholas Schneider
 * schnei54@purdue.edu
 * baseball project version 1.0
 */

#ifndef PITCHER
#define PITCHER
#include "player.h"
#include <iostream>
#include "era.h"

class Pitcher : public Player {

public:
        Pitcher(QString name, int position, std::string handiness, int age, int number, std::string Nationality);
        Pitcher();
        Pitcher(int i);
        void startPitcherGame();
        void startPitcherSeason();

        void createPitchingAverages();
        void editPitchingGameStats(QString atBatResult, int runs);
        void addInningPitched();
        void calcGamePitchingStats();
        void clearGameStats();
        void addInningHits();
        void addInningRuns(int runs);
        void startInning();
        void endPitcherGame();
        void printPitcherPercents();

        std::string pitcherType;

        int inningRuns;
        int inningHits;
        int inningBattersFaced;

        double gamePitchERA;
        double gamePitchInnings;
        int gamePitchSingles;
        int gamePitchDoubles;
        int gamePitchTriples;
        int gamePitchHomeRuns;
        int gamePitchStrikeouts;
        int gamePitchWalks;
        int gamePitchHitBatters;
        int gameBattersFaced;
        int gamePitchHits;
        double gamePitchRunsAllowed;
        int gamePitchPlateAppereances;
        int gamePitches;
        int gamePitchAtBats;
        bool pitchedThisGame;

        double seasonPitchERA;
        double seasonPitchInnings;
        int seasonPitchSingles;
        int seasonPitchDoubles;
        int seasonPitchTriples;
        int seasonPitchHomeRuns;
        int seasonPitchStrikeouts;
        int seasonPitchWalks;
        int seasonPitchHitBatters;
        int seasonBattersFaced;
        int seasonPitchHits;
        double seasonPitchRunsAllowed;
        int seasonPitchPlateAppereances;
        int seasonPitches;
        int seasonPitchAtBats;

        double pitcherCareerERA;
        double pitcherCareerBattersFaced;
        double pitcherCareerStrikeouts;
        double pitcherCareerWalks;
        double pitcherCareerHits;
        double pitcherCareerSingles;
        double pitcherCareerDoubles;
        double pitcherCareerTriples;
        double pitcherCareerHomeruns;
        double pitcherCareerHitByPitch;
        int careerRuns;
        int careerWHIP;
        int careerWins;
        int careerLosses;
        int careerSaves;
        int careerBlownSaves;
        double careerInningsPitched;

        double pitcherHomeRunPercent;
        double pitcherTriplePercent;
        double pitcherDoublePercent;
        double pitcherSinglePercent;
        double pitcherStrikeOutPercent;
        double pitcherWalkPercent;
        double pitcherHitByPitchPercent;

};

#endif // PITCHER

