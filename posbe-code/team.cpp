/*
 * Nicholas Schneider
 * schnei54@purdue.edu
 * baseball project version 1.0
 */

#include "team.h"
#include "player.h"
#include "pitcher.h"
#include <math.h>
#include <fstream>
#include <iostream>
#include <qtextstream.h>
#include <QFile>
#include <QDir>

/*Team::Team(char* name, char* country, char* state, std::vector<Player> players)
{
    TeamName = name;
    TeamCountry = country;
    TeamState = state;
    TeamPlayers = players;

}*/


//the teams are "created here"
//1 = yankees
//2= redsox
//location is going to be where all of the player data goes; the location of the file it will be placed in

Team::Team(int i, std::string location) {

    if (i == 1) {
        era = new Era("red sox");
        era = new Era();

        Player* ellsbury = new Player();
        ellsbury->playerName = "Jacoby Ellsbury";
        ellsbury->era = era;
        ellsbury->careerAtBats = 80;
        ellsbury->careerAtBatHits = 20;
        ellsbury->careerAtBatDoubles = 3;
        ellsbury->careerAtBatTriples = 0;
        ellsbury->careerAtBatHomeruns = 2;
        ellsbury->careerAtBatWalks = 5;
        ellsbury->careerAtBatHitByPitch = 1;
        ellsbury->careerAtBatStrikeouts = 15;
        centerField = ellsbury;
        ellsbury->createBattingAverages();
        battingOrder[0] = ellsbury;

        Player* gardner = new Player();
        gardner->playerName = "Brett Gardner";
        gardner->era = era;
        gardner->careerAtBats = 81;
        gardner->careerAtBatHits = 23;
        gardner->careerAtBatDoubles = 4;
        gardner->careerAtBatTriples = 0;
        gardner->careerAtBatHomeruns = 2;
        gardner->careerAtBatWalks = 5;
        gardner->careerAtBatHitByPitch = 0;
        gardner->careerAtBatStrikeouts = 15;
        leftField = gardner;
        gardner->createBattingAverages();
        battingOrder[1] = gardner;

        Player* beltran = new Player();
        beltran->playerName = "Carlos Beltran";
        beltran->era = era;
        beltran->careerAtBats = 62;
        beltran->careerAtBatHits = 16;
        beltran->careerAtBatDoubles = 7;
        beltran->careerAtBatTriples = 0;
        beltran->careerAtBatHomeruns = 3;
        beltran->careerAtBatWalks = 3;
        beltran->careerAtBatHitByPitch = 0;
        beltran->careerAtBatStrikeouts = 9;
        rightField = beltran;
        beltran->createBattingAverages();
        battingOrder[2] = beltran;

        Player* teixeira = new Player();
        teixeira->playerName = "Mark Teixeira";
        teixeira->era = era;
        teixeira->careerAtBats = 52;
        teixeira->careerAtBatHits = 8;
        teixeira->careerAtBatDoubles = 0;
        teixeira->careerAtBatTriples = 0;
        teixeira->careerAtBatHomeruns = 2;
        teixeira->careerAtBatWalks = 8;
        teixeira->careerAtBatHitByPitch = 1;
        teixeira->careerAtBatStrikeouts = 8;
        firstBase = teixeira;
        teixeira->createBattingAverages();
        battingOrder[4] = teixeira;

        Player* mcCann = new Player();
        mcCann->playerName = "Brian McCann";
        mcCann->era = era;
        mcCann->careerAtBats = 61;
        mcCann->careerAtBatHits = 11;
        mcCann->careerAtBatDoubles = 4;
        mcCann->careerAtBatTriples = 0;
        mcCann->careerAtBatHomeruns = 3;
        mcCann->careerAtBatWalks = 4;
        mcCann->careerAtBatHitByPitch = 2;
        mcCann->careerAtBatStrikeouts = 10;
        catcher = mcCann;
        mcCann->createBattingAverages();
        battingOrder[5] = mcCann;

        Player* headley = new Player();
        headley->playerName = "Chase Headley";
        headley->era = era;
        headley->careerAtBats = 80;
        headley->careerAtBatHits = 18;
        headley->careerAtBatDoubles = 4;
        headley->careerAtBatTriples = 0;
        headley->careerAtBatHomeruns = 2;
        headley->careerAtBatWalks = 8;
        headley->careerAtBatHitByPitch = 2;
        headley->careerAtBatStrikeouts = 17;
        leftField = headley;
        headley->createBattingAverages();
        battingOrder[6] = headley;

        Player* rodriguez = new Player();
        rodriguez->playerName = "Alex Rodriguez";
        rodriguez->era = era;
        rodriguez->careerAtBats = 81;
        rodriguez->careerAtBatHits = 22;
        rodriguez->careerAtBatDoubles = 5;
        rodriguez->careerAtBatTriples = 0;
        rodriguez->careerAtBatHomeruns = 4;
        rodriguez->careerAtBatWalks = 10;
        rodriguez->careerAtBatHitByPitch = 0;
        rodriguez->careerAtBatStrikeouts = 20;
        dh = rodriguez;
        rodriguez->createBattingAverages();
        battingOrder[3] = rodriguez;

        Player* drew = new Player();
        drew->playerName = "Stephen Drew";
        drew->era = era;
        drew->careerAtBats = 37;
        drew->careerAtBatHits = 8;
        drew->careerAtBatDoubles = 2;
        drew->careerAtBatTriples = 0;
        drew->careerAtBatHomeruns = 2;
        drew->careerAtBatWalks = 1;
        drew->careerAtBatHitByPitch = 0;
        drew->careerAtBatStrikeouts = 4;
        rightField = drew;
        drew->createBattingAverages();
        battingOrder[7] = drew;

        Player* gregorius = new Player();
        gregorius->playerName = "Didi Gregorius";
        gregorius->era = era;
        gregorius->careerAtBats = 75;
        gregorius->careerAtBatHits = 16;
        gregorius->careerAtBatDoubles = 1;
        gregorius->careerAtBatTriples = 0;
        gregorius->careerAtBatHomeruns = 1;
        gregorius->careerAtBatWalks = 7;
        gregorius->careerAtBatHitByPitch = 2;
        gregorius->careerAtBatStrikeouts = 8;
        rightField = gregorius;
        gregorius->createBattingAverages();
        battingOrder[8] = gregorius;

        Pitcher* tanaka = new Pitcher();
        tanaka->playerName = "Masahiro Tanaka";
        tanaka->pitcherType = "starter";
        tanaka->careerAtBats = 8;
        tanaka->careerAtBatHits = 0;
        tanaka->careerAtBatDoubles = 0;
        tanaka->careerAtBatTriples = 0;
        tanaka->careerAtBatHomeruns = 0;
        tanaka->careerAtBatWalks = 1;
        tanaka->careerAtBatHitByPitch = 0;
        tanaka->careerAtBatStrikeouts = 2;
        tanaka->createBattingAverages();
        //away.battingOrder[8] = lester;
        tanaka->pitcherCareerBattersFaced = 92;
        tanaka->pitcherCareerHomeruns = 4;
        tanaka->pitcherCareerTriples = 0;
        tanaka->pitcherCareerDoubles = 8;
        tanaka->pitcherCareerHits = 20;
        tanaka->pitcherCareerStrikeouts = 15;
        tanaka->pitcherCareerWalks = 6;
        tanaka->pitcherCareerHitByPitch = 0;
        tanaka->createPitchingAverages();
        startingRotation[0] = tanaka;
        pitchers[0] = tanaka;

        Pitcher* sabathia = new Pitcher();
        sabathia->playerName = "CC Sabathia";
        sabathia->pitcherType = "starter";
        sabathia->pitcherCareerBattersFaced = 73;
        sabathia->pitcherCareerHomeruns = 1;
        sabathia->pitcherCareerTriples = 0;
        sabathia->pitcherCareerDoubles = 3;
        sabathia->pitcherCareerHits = 16;
        sabathia->pitcherCareerStrikeouts = 14;
        sabathia->pitcherCareerWalks = 9;
        sabathia->pitcherCareerHitByPitch = 0;
        sabathia->createPitchingAverages();
        startingRotation[1] = sabathia;
        pitchers[1] = sabathia;

        Pitcher* pineda = new Pitcher();
        pineda->playerName = "Micheal Pineda";
        pineda->pitcherType = "starter";
        pineda->pitcherCareerBattersFaced = 66;
        pineda->pitcherCareerHomeruns = 3;
        pineda->pitcherCareerTriples = 0;
        pineda->pitcherCareerDoubles = 5;
        pineda->pitcherCareerHits = 18;
        pineda->pitcherCareerStrikeouts = 17;
        pineda->pitcherCareerWalks = 0;
        pineda->pitcherCareerHitByPitch = 1;
        pineda->createPitchingAverages();
        startingRotation[2] = pineda;
        pitchers[2] = pineda;

        Pitcher* eovaldi = new Pitcher();
        eovaldi->pitcherType = "starter";
        eovaldi->playerName = "Nathan Eovaldi";
        eovaldi->pitcherCareerBattersFaced = 74;
        eovaldi->pitcherCareerHomeruns = 1;
        eovaldi->pitcherCareerTriples = 0;
        eovaldi->pitcherCareerDoubles = 1;
        eovaldi->pitcherCareerHits = 22;
        eovaldi->pitcherCareerStrikeouts = 7;
        eovaldi->pitcherCareerWalks = 2;
        eovaldi->pitcherCareerHitByPitch = 1;
        eovaldi->createPitchingAverages();
        startingRotation[3] = eovaldi;
        pitchers[3] = eovaldi;

        Pitcher* nova = new Pitcher();
        nova->playerName = "Ivan Nova";
        nova->pitcherType = "starter";
        nova->pitcherCareerBattersFaced = 80;
        nova->pitcherCareerHomeruns = 5;
        nova->pitcherCareerTriples = 0;
        nova->pitcherCareerDoubles = 5;
        nova->pitcherCareerHits = 22;
        nova->pitcherCareerStrikeouts = 13;
        nova->pitcherCareerWalks = 3;
        nova->pitcherCareerHitByPitch = 0;
        nova->createPitchingAverages();
        startingRotation[4] = nova;
        pitchers[4] = nova;

        Pitcher* severino = new Pitcher();
        severino->playerName = "Luis Severino";
        severino->pitcherType = "starter";
        severino->pitcherCareerBattersFaced = 18;
        severino->pitcherCareerHomeruns = 1;
        severino->pitcherCareerTriples = 0;
        severino->pitcherCareerDoubles = 1;
        severino->pitcherCareerHits = 2;
        severino->pitcherCareerStrikeouts = 7;
        severino->pitcherCareerWalks = 0;
        severino->pitcherCareerHitByPitch = 0;
        severino->createPitchingAverages();
        startingRotation[6] = severino;
        pitchers[5] = severino;

        Pitcher* miller = new Pitcher();
        miller->playerName = "Andrew Miller";
        miller->pitcherType = "closer";
        miller->pitcherCareerBattersFaced = 45;
        miller->pitcherCareerHomeruns = 5;
        miller->pitcherCareerTriples = 0;
        miller->pitcherCareerDoubles = 0;
        miller->pitcherCareerHits = 2;
        miller->pitcherCareerStrikeouts = 16;
        miller->pitcherCareerWalks = 8;
        miller->pitcherCareerHitByPitch = 1;
        miller->createPitchingAverages();
        bullpen[0] = miller;
        startingRotation[7] = miller;
        pitchers[6] = miller;

        Pitcher* warren = new Pitcher();
        warren->playerName = "Adam Warren";
        warren->pitcherType = "setup";
        warren->pitcherCareerBattersFaced = 76;
        warren->pitcherCareerHomeruns = 0;
        warren->pitcherCareerTriples = 1;
        warren->pitcherCareerDoubles = 6;
        warren->pitcherCareerHits = 17;
        warren->pitcherCareerStrikeouts = 9;
        warren->pitcherCareerWalks = 6;
        warren->pitcherCareerHitByPitch = 2;
        warren->createPitchingAverages();
        startingRotation[5] = warren;
        bullpen[1] = warren;
        pitchers[7] = warren;

        Pitcher* betances = new Pitcher();
        betances->playerName = "Dellin Betances";
        betances->pitcherType = "relief";
        betances->pitcherCareerBattersFaced = 46;
        betances->pitcherCareerHomeruns = 1;
        betances->pitcherCareerTriples = 0;
        betances->pitcherCareerDoubles = 0;
        betances->pitcherCareerHits = 7;
        betances->pitcherCareerStrikeouts = 20;
        betances->pitcherCareerWalks = 5;
        betances->pitcherCareerHitByPitch = 0;
        betances->createPitchingAverages();
        bullpen[2] = betances;
        pitchers[8] = betances;

        Pitcher* wilson = new Pitcher();
        wilson->playerName = "Justin Wilson";
        wilson->pitcherType = "relief";
        wilson->pitcherCareerBattersFaced = 38;
        wilson->pitcherCareerHomeruns = 0;
        wilson->pitcherCareerTriples = 0;
        wilson->pitcherCareerDoubles = 1;
        wilson->pitcherCareerHits = 7;
        wilson->pitcherCareerStrikeouts = 11;
        wilson->pitcherCareerWalks = 2;
        wilson->pitcherCareerHitByPitch = 0;
        wilson->createPitchingAverages();
        bullpen[3] = wilson;
        pitchers[9] = wilson;

        Pitcher* shreve = new Pitcher();
        shreve->playerName = "Chasen Shreve";
        shreve->pitcherType = "relief";
        shreve->pitcherCareerBattersFaced = 32;
        shreve->pitcherCareerHomeruns = 1;
        shreve->pitcherCareerTriples = 0;
        shreve->pitcherCareerDoubles = 1;
        shreve->pitcherCareerHits = 7;
        shreve->pitcherCareerStrikeouts = 7;
        shreve->pitcherCareerWalks = 5;
        shreve->pitcherCareerHitByPitch = 0;
        shreve->createPitchingAverages();
        bullpen[4] = shreve;
        startingRotation[8] = shreve;
        pitchers[10] = shreve;

        Pitcher* rogers = new Pitcher();
        rogers->playerName = "Esmil Rogers";
        rogers->pitcherType = "relief";
        rogers->pitcherCareerBattersFaced = 30;
        rogers->pitcherCareerHomeruns = 2;
        rogers->pitcherCareerTriples = 0;
        rogers->pitcherCareerDoubles = 0;
        rogers->pitcherCareerHits = 8;
        rogers->pitcherCareerStrikeouts = 5;
        rogers->pitcherCareerWalks = 3;
        rogers->pitcherCareerHitByPitch = 1;
        rogers->createPitchingAverages();
        bullpen[5] = rogers;
        pitchers[11] = rogers;

        Pitcher* mitchell = new Pitcher();
        mitchell->playerName = "Bryan Mitchell";
        mitchell->pitcherType = "relief";
        mitchell->pitcherCareerBattersFaced = 19;
        mitchell->pitcherCareerHomeruns = 1;
        mitchell->pitcherCareerTriples = 0;
        mitchell->pitcherCareerDoubles = 0;
        mitchell->pitcherCareerHits = 6;
        mitchell->pitcherCareerStrikeouts = 3;
        mitchell->pitcherCareerWalks = 3;
        mitchell->pitcherCareerHitByPitch = 0;
        mitchell->createPitchingAverages();
        bullpen[6] = mitchell;
        pitchers[12] = mitchell;

        pitchers[13] = NULL;
        pitchers[14] = NULL;
        pitchers[15] = NULL;

        TeamName = "New York Yankees";
        StadiumName = "Yankee Stadium";
        abbreviation = "NYY";
    }

    else if (i == 2) {
        era = new Era("yankees");
        era = new Era();

        Player* betts = new Player();
        betts->playerName = "Mookie Betts";
        betts->era = era;
        betts->careerAtBats = 77;
        betts->careerAtBatHits = 20;
        betts->careerAtBatDoubles = 8;
        betts->careerAtBatTriples = 1;
        betts->careerAtBatHomeruns = 5;
        betts->careerAtBatWalks = 3;
        betts->careerAtBatHitByPitch = 0;
        betts->careerAtBatStrikeouts = 16;
        centerField = betts;
        betts->createBattingAverages();
        battingOrder[0] = betts;

        Player* pedroia = new Player();
        pedroia->playerName = "Dustin Pedroia";
        pedroia->era = era;
        pedroia->careerAtBats = 49;
        pedroia->careerAtBatHits = 10;
        pedroia->careerAtBatDoubles = 2;
        pedroia->careerAtBatTriples = 0;
        pedroia->careerAtBatHomeruns = 1;
        pedroia->careerAtBatWalks = 3;
        pedroia->careerAtBatHitByPitch = 0;
        pedroia->careerAtBatStrikeouts = 16;
        secondBase = pedroia;
        pedroia->createBattingAverages();
        battingOrder[1] = pedroia;

        Player* ortiz = new Player();
        ortiz->playerName = "David Ortiz";
        ortiz->era = era;
        ortiz->careerAtBats = 68;
        ortiz->careerAtBatHits = 15;
        ortiz->careerAtBatDoubles = 6;
        ortiz->careerAtBatTriples = 0;
        ortiz->careerAtBatHomeruns = 3;
        ortiz->careerAtBatWalks = 7;
        ortiz->careerAtBatHitByPitch = 0;
        ortiz->careerAtBatStrikeouts = 11;
        dh = ortiz;
        ortiz->createBattingAverages();
        battingOrder[2] = ortiz;

        Player* ramirez = new Player();
        ramirez->playerName = "Hanley Ramirez";
        ramirez->era = era;
        ramirez->careerAtBats = 50;
        ramirez->careerAtBatHits = 11;
        ramirez->careerAtBatDoubles = 1;
        ramirez->careerAtBatTriples = 0;
        ramirez->careerAtBatHomeruns = 2;
        ramirez->careerAtBatWalks = 1;
        ramirez->careerAtBatHitByPitch = 1;
        ramirez->careerAtBatStrikeouts = 7;
        leftField = ramirez;
        ramirez->createBattingAverages();
        battingOrder[3] = ramirez;

        Player* sandoval = new Player();
        sandoval->playerName = "Pablo Sandoval";
        sandoval->era = era;
        sandoval->careerAtBats = 68;
        sandoval->careerAtBatHits = 19;
        sandoval->careerAtBatDoubles = 2;
        sandoval->careerAtBatTriples = 0;
        sandoval->careerAtBatHomeruns = 1;
        sandoval->careerAtBatWalks = 1;
        sandoval->careerAtBatHitByPitch = 0;
        sandoval->careerAtBatStrikeouts = 12;
        thirdBase = sandoval;
        sandoval->createBattingAverages();
        battingOrder[4] = sandoval;

        Player* napoli = new Player();
        napoli->playerName = "Mike Napoli";
        napoli->era = era;
        napoli->careerAtBats = 52;
        napoli->careerAtBatHits = 7;
        napoli->careerAtBatDoubles = 1;
        napoli->careerAtBatTriples = 0;
        napoli->careerAtBatHomeruns = 1;
        napoli->careerAtBatWalks = 7;
        napoli->careerAtBatHitByPitch = 2;
        napoli->careerAtBatStrikeouts = 11;
        firstBase = napoli;
        napoli->createBattingAverages();
        battingOrder[5] = napoli;

        Player* bogaerts = new Player();
        bogaerts->playerName = "Xander Bogaerts";
        bogaerts->era = era;
        bogaerts->careerAtBats = 86;
        bogaerts->careerAtBatHits = 23;
        bogaerts->careerAtBatDoubles = 3;
        bogaerts->careerAtBatTriples = 0;
        bogaerts->careerAtBatHomeruns = 1;
        bogaerts->careerAtBatWalks = 7;
        bogaerts->careerAtBatHitByPitch = 0;
        bogaerts->careerAtBatStrikeouts = 13;
        shortStop = bogaerts;
        bogaerts->createBattingAverages();
        battingOrder[6] = bogaerts;

        Player* swihart = new Player();
        swihart->playerName = "Blake Swihart";
        swihart->era = era;
        swihart->careerAtBats = 38;
        swihart->careerAtBatHits = 10;
        swihart->careerAtBatDoubles = 1;
        swihart->careerAtBatTriples = 0;
        swihart->careerAtBatHomeruns = 2;
        swihart->careerAtBatWalks = 3;
        swihart->careerAtBatHitByPitch = 0;
        swihart->careerAtBatStrikeouts = 11;
        catcher = swihart;
        swihart->createBattingAverages();
        battingOrder[7] = swihart;

        Player* bradleyJR = new Player();
        bradleyJR->playerName = "Jackie Bradley Jr";
        bradleyJR->era = era;
        bradleyJR->careerAtBats = 38;
        bradleyJR->careerAtBatHits = 10;
        bradleyJR->careerAtBatDoubles = 4;
        bradleyJR->careerAtBatTriples = 0;
        bradleyJR->careerAtBatHomeruns = 1;
        bradleyJR->careerAtBatWalks = 7;
        bradleyJR->careerAtBatHitByPitch = 0;
        bradleyJR->careerAtBatStrikeouts = 7;
        rightField = bradleyJR;
        bradleyJR->createBattingAverages();
        battingOrder[8] = bradleyJR;

        Pitcher* bucholz = new Pitcher();
        bucholz->playerName = "Clay Bucholz";
        bucholz->pitcherType = "starter";
        bucholz->careerAtBats = 6;
        bucholz->careerAtBatHits = 0;
        bucholz->careerAtBatDoubles = 0;
        bucholz->careerAtBatTriples = 0;
        bucholz->careerAtBatHomeruns = 0;
        bucholz->careerAtBatWalks = 0;
        bucholz->careerAtBatHitByPitch = 0;
        bucholz->careerAtBatStrikeouts = 2;
        startingRotation[0] = bucholz;
        bucholz->createBattingAverages();
        //away.battingOrder[8] = lester;
        bucholz->pitcherCareerBattersFaced = 38;
        bucholz->pitcherCareerHomeruns = 3;
        bucholz->pitcherCareerTriples = 0;
        bucholz->pitcherCareerDoubles = 2;
        bucholz->pitcherCareerHits = 10;
        bucholz->pitcherCareerStrikeouts = 6;
        bucholz->pitcherCareerWalks = 2;
        bucholz->pitcherCareerHitByPitch = 0;
        bucholz->createPitchingAverages();
        pitchers[0] = bucholz;

        Pitcher* miley = new Pitcher();
        miley->playerName = "Wade Miley";
        miley->pitcherType = "starter";
        miley->pitcherCareerBattersFaced = 99;
        miley->pitcherCareerHomeruns = 1;
        miley->pitcherCareerTriples = 0;
        miley->pitcherCareerDoubles = 10;
        miley->pitcherCareerHits = 27;
        miley->pitcherCareerStrikeouts = 14;
        miley->pitcherCareerWalks = 6;
        miley->pitcherCareerHitByPitch = 0;
        miley->createPitchingAverages();
        startingRotation[1] = miley;
        pitchers[1] = miley;

        Pitcher* porcello = new Pitcher();
        porcello->playerName = "Rick Porcello";
        porcello->pitcherType = "starter";
        porcello->pitcherCareerBattersFaced = 62;
        porcello->pitcherCareerHomeruns = 2;
        porcello->pitcherCareerTriples = 0;
        porcello->pitcherCareerDoubles = 3;
        porcello->pitcherCareerHits = 11;
        porcello->pitcherCareerStrikeouts = 21;
        porcello->pitcherCareerWalks = 2;
        porcello->pitcherCareerHitByPitch = 1;
        porcello->createPitchingAverages();
        startingRotation[2] = porcello;
        pitchers[2] = porcello;

        Pitcher* kelly = new Pitcher();
        kelly->pitcherType = "starter";
        kelly->playerName = "Joe Kelly";
        kelly->pitcherCareerBattersFaced = 48;
        kelly->pitcherCareerHomeruns = 1;
        kelly->pitcherCareerTriples = 0;
        kelly->pitcherCareerDoubles = 2;
        kelly->pitcherCareerHits = 10;
        kelly->pitcherCareerStrikeouts = 11;
        kelly->pitcherCareerWalks = 2;
        kelly->pitcherCareerHitByPitch = 0;
        kelly->createPitchingAverages();
        startingRotation[3] = kelly;
        pitchers[3] = kelly;

        Pitcher* rodriguez = new Pitcher();
        rodriguez->playerName = "Eduardo Rodriguez";
        rodriguez->pitcherType = "starter";
        rodriguez->pitcherCareerBattersFaced = 105;
        rodriguez->pitcherCareerHomeruns = 3;
        rodriguez->pitcherCareerTriples = 0;
        rodriguez->pitcherCareerDoubles = 3;
        rodriguez->pitcherCareerHits = 22;
        rodriguez->pitcherCareerStrikeouts = 11;
        rodriguez->pitcherCareerWalks = 7;
        rodriguez->pitcherCareerHitByPitch = 1;
        rodriguez->createPitchingAverages();
        startingRotation[4] = rodriguez;
        pitchers[4] = rodriguez;

        Pitcher* masterson = new Pitcher();
        masterson->playerName = "Justin Masterson";
        masterson->pitcherType = "starter";
        masterson->pitcherCareerBattersFaced = 30;
        masterson->pitcherCareerHomeruns = 0;
        masterson->pitcherCareerTriples = 0;
        masterson->pitcherCareerDoubles = 2;
        masterson->pitcherCareerHits = 6;
        masterson->pitcherCareerStrikeouts = 2;
        masterson->pitcherCareerWalks = 3;
        masterson->pitcherCareerHitByPitch = 1;
        masterson->createPitchingAverages();
        startingRotation[6] = masterson;
        pitchers[5] = masterson;

        Pitcher* hill = new Pitcher();
        hill->playerName = "Rich Hill";
        hill->pitcherType = "starter";
        hill->pitcherCareerBattersFaced = 23;
        hill->pitcherCareerHomeruns = 1;
        hill->pitcherCareerTriples = 0;
        hill->pitcherCareerDoubles = 1;
        hill->pitcherCareerHits = 4;
        hill->pitcherCareerStrikeouts = 6;
        hill->pitcherCareerWalks = 3;
        hill->pitcherCareerHitByPitch = 0;
        hill->createPitchingAverages();
        startingRotation[8] = hill;
        pitchers[6] = hill;

        Pitcher* uehara = new Pitcher();
        uehara->playerName = "Koji Uehara";
        uehara->pitcherType = "closer";
        uehara->pitcherCareerBattersFaced = 9;
        uehara->pitcherCareerHomeruns = 0;
        uehara->pitcherCareerTriples = 0;
        uehara->pitcherCareerDoubles = 2;
        uehara->pitcherCareerHits = 2;
        uehara->pitcherCareerStrikeouts = 2;
        uehara->pitcherCareerWalks = 1;
        uehara->pitcherCareerHitByPitch = 0;
        uehara->createPitchingAverages();
        bullpen[0] = uehara;
        pitchers[7] = uehara;

        Pitcher* ogando = new Pitcher();
        ogando->playerName = "Alexi Ogando";
        ogando->pitcherType = "setup";
        ogando->pitcherCareerBattersFaced = 40;
        ogando->pitcherCareerHomeruns = 4;
        ogando->pitcherCareerTriples = 0;
        ogando->pitcherCareerDoubles = 0;
        ogando->pitcherCareerHits = 8;
        ogando->pitcherCareerStrikeouts = 8;
        ogando->pitcherCareerWalks = 3;
        ogando->pitcherCareerHitByPitch = 0;
        ogando->createPitchingAverages();
        bullpen[1] = ogando;
        pitchers[8] = ogando;

        Pitcher* owens = new Pitcher();
        owens->playerName = "Henry Owens";
        owens->pitcherType = "relief";
        owens->pitcherCareerBattersFaced = 33;
        owens->pitcherCareerHomeruns = 2;
        owens->pitcherCareerTriples = 0;
        owens->pitcherCareerDoubles = 2;
        owens->pitcherCareerHits = 11;
        owens->pitcherCareerStrikeouts = 7;
        owens->pitcherCareerWalks = 3;
        owens->pitcherCareerHitByPitch = 0;
        owens->createPitchingAverages();
        startingRotation[5] = owens;
        bullpen[2] = owens;
        pitchers[9] = owens;

        Pitcher* ross = new Pitcher;
        ross->playerName = "Robbie Ross ";
        ross->pitcherType = "relief";
        ross->pitcherCareerBattersFaced = 49;
        ross->pitcherCareerHomeruns = 0;
        ross->pitcherCareerTriples = 0;
        ross->pitcherCareerDoubles = 3;
        ross->pitcherCareerHits = 8;
        ross->pitcherCareerStrikeouts = 9;
        ross->pitcherCareerWalks = 6;
        ross->pitcherCareerHitByPitch = 0;
        ross->createPitchingAverages();
        bullpen[3] = ross;
        pitchers[10] = ross;

        Pitcher* wright =  new Pitcher();
        wright->playerName = "Steven Wright";
        wright->pitcherType = "relief";
        wright->pitcherCareerBattersFaced = 51;
        wright->pitcherCareerHomeruns = 2;
        wright->pitcherCareerTriples = 0;
        wright->pitcherCareerDoubles = 2;
        wright->pitcherCareerHits = 10;
        wright->pitcherCareerStrikeouts = 10;
        wright->pitcherCareerWalks = 5;
        wright->pitcherCareerHitByPitch = 0;
        wright->createPitchingAverages();
        bullpen[4] = wright;
        startingRotation[7] = wright;
        pitchers[11] = wright;

        Pitcher* rogers = new Pitcher();
        rogers->playerName = "Tommy Layne";
        rogers->pitcherType = "relief";
        rogers->pitcherCareerBattersFaced = 32;
        rogers->pitcherCareerHomeruns = 0;
        rogers->pitcherCareerTriples = 0;
        rogers->pitcherCareerDoubles = 1;
        rogers->pitcherCareerHits = 9;
        rogers->pitcherCareerStrikeouts = 5;
        rogers->pitcherCareerWalks = 4;
        rogers->pitcherCareerHitByPitch = 1;
        rogers->createPitchingAverages();
        bullpen[5] = rogers;
        pitchers[12] = rogers;

        Pitcher* breslow = new Pitcher;
        breslow->playerName = "Craig Breslow";
        breslow->pitcherType = "relief";
        breslow->pitcherCareerBattersFaced = 41;
        breslow->pitcherCareerHomeruns = 2;
        breslow->pitcherCareerTriples = 0;
        breslow->pitcherCareerDoubles = 3;
        breslow->pitcherCareerHits = 13;
        breslow->pitcherCareerStrikeouts = 4;
        breslow->pitcherCareerWalks = 5;
        breslow->pitcherCareerHitByPitch = 1;
        breslow->createPitchingAverages();
        bullpen[6] = breslow;
        pitchers[13] = breslow;

        pitchers[14] = NULL;
        pitchers[15] = NULL;

        TeamName = "Boston Red Sox";
        StadiumName = "Fenway Park";
        abbreviation = "BOS";
    }
    destination = location;
}

Team::Team(){

}

//This opens all of the output files. This must happen to have the data be output
void Team::openOutputFile(){

    QString fileName = QString::fromStdString(destination) + this->TeamName + "/" + "Batter/" + this->TeamName + "Batters.csv";
    batterFile = new QFile(fileName);
    batterFile->open(QFile::WriteOnly|QFile::Truncate);

    QString fileName2 = QString::fromStdString(destination) + this->TeamName + "/" + "Pitcher/" + this->TeamName + "Pitchers.csv";
    pitcherFile = new QFile(fileName2);
    pitcherFile->open(QFile::WriteOnly|QFile::Truncate);


    QString fileName3 = QString::fromStdString(destination) + this->TeamName + "/" + "Batter/" + this->TeamName + "BattersSingles.csv";
    batterSingleFile = new QFile(fileName3);
    batterSingleFile->open(QFile::WriteOnly|QFile::Truncate);

    QString fileName4 = QString::fromStdString(destination) + this->TeamName + "/" + "Batter/" + this->TeamName + "BattersDoubles.csv";
    batterDoubleFile = new QFile(fileName4);
    batterDoubleFile->open(QFile::WriteOnly|QFile::Truncate);


    QString fileName5 = QString::fromStdString(destination) + this->TeamName + "/" + "Batter/" + this->TeamName + "BattersTriples.csv";
    batterTripleFile = new QFile(fileName5);
    batterTripleFile->open(QFile::WriteOnly|QFile::Truncate);

    QString fileName6 = QString::fromStdString(destination) + this->TeamName + "/" + "Batter/" + this->TeamName + "BattersHomeRuns.csv";
    batterHomeRunFile = new QFile(fileName6);
    batterHomeRunFile->open(QFile::WriteOnly|QFile::Truncate);


    QString fileName7 = QString::fromStdString(destination) + this->TeamName + "/" + "Batter/" + this->TeamName + "BattersWalks.csv";
    batterWalksFile = new QFile(fileName7);
    batterWalksFile->open(QFile::WriteOnly|QFile::Truncate);

    QString fileName8 = QString::fromStdString(destination) + this->TeamName + "/" + "Batter/" + this->TeamName + "BattersStrikeOuts.csv";
    batterStrikeOutFile = new QFile(fileName8);
    batterStrikeOutFile->open(QFile::WriteOnly|QFile::Truncate);

    QString fileName9 = QString::fromStdString(destination) + this->TeamName + "/" + "Batter/" + this->TeamName + "BattersHitByPitch.csv";
    batterHitByPitchFile = new QFile(fileName9);
    batterHitByPitchFile->open(QFile::WriteOnly|QFile::Truncate);

    QString fileName10 = QString::fromStdString(destination) + this->TeamName + "/" + "Batter/" + this->TeamName + "PitcherSingles.csv";
    pitcherSingleFile = new QFile(fileName10);
    pitcherSingleFile->open(QFile::WriteOnly|QFile::Truncate);

    QString fileName11 = QString::fromStdString(destination) + this->TeamName + "/" + "Pitcher/" + this->TeamName + "PitcherDoubles.csv";
    pitcherDoubleFile = new QFile(fileName11);
    pitcherDoubleFile->open(QFile::WriteOnly|QFile::Truncate);


    QString fileName12 = QString::fromStdString(destination) + this->TeamName + "/" + "Pitcher/" + this->TeamName + "PitcherTriples.csv";
    pitcherTripleFile = new QFile(fileName12);
    pitcherTripleFile->open(QFile::WriteOnly|QFile::Truncate);

    QString fileName13 = QString::fromStdString(destination) + this->TeamName + "/" + "Pitcher/" + this->TeamName + "PitcherHomeRuns.csv";
    pitcherHomeRunFile = new QFile(fileName13);
    pitcherHomeRunFile->open(QFile::WriteOnly|QFile::Truncate);


    QString fileName14 = QString::fromStdString(destination) + this->TeamName + "/" + "Pitcher/" + this->TeamName + "PitcherWalks.csv";
    pitcherWalksFile = new QFile(fileName14);
    pitcherWalksFile->open(QFile::WriteOnly|QFile::Truncate);

    QString fileName15 = QString::fromStdString(destination) + this->TeamName + "/" + "Pitcher/" + this->TeamName + "PitcherStrikeOuts.csv";
    pitcherStrikeOutFile = new QFile(fileName15);
    pitcherStrikeOutFile->open(QFile::WriteOnly|QFile::Truncate);

    QString fileName16 = QString::fromStdString(destination) + this->TeamName + "/" + "Pitcher/" + this->TeamName + "PitcherHitByPitch.csv";
    pitcherHitByPitchFile = new QFile(fileName16);
    pitcherHitByPitchFile->open(QFile::WriteOnly|QFile::Truncate);


    QTextStream batterSingleStream(batterSingleFile);
    QTextStream batterDoubleStream(batterDoubleFile);
    QTextStream batterTripleStream(batterTripleFile);
    QTextStream batterHomeRunStream(batterHomeRunFile);
    QTextStream batterWalkStream(batterWalksFile);
    QTextStream batterStrikeOutStream(batterStrikeOutFile);
    QTextStream batterHitByPitchStream(batterHitByPitchFile);

    QTextStream pitcherSingleStream(pitcherSingleFile);
    QTextStream pitcherDoubleStream(pitcherDoubleFile);
    QTextStream pitcherTripleStream(pitcherTripleFile);
    QTextStream pitcherHomeRunStream(pitcherHomeRunFile);
    QTextStream pitcherWalkStream(pitcherWalksFile);
    QTextStream pitcherStrikeOutStream(pitcherStrikeOutFile);
    QTextStream pitcherHitByPitchStream(pitcherHitByPitchFile);

    for (int p = 0; p < 9; p++) {
        Player* temp = battingOrder[p];
        if (temp != NULL){
            batterSingleStream << temp->playerName << ",";
            batterDoubleStream << temp->playerName << ",";
            batterTripleStream << temp->playerName << ",";
            batterHomeRunStream << temp->playerName << ",";
            batterWalkStream << temp->playerName << ",";
            batterStrikeOutStream << temp->playerName << ",";
            batterHitByPitchStream << temp->playerName << ",";
        }
    }

    batterSingleStream << "\n";
    batterDoubleStream << "\n";
    batterTripleStream << "\n";
    batterHomeRunStream << "\n";
    batterWalkStream <<  "\n";
    batterStrikeOutStream << "\n";
    batterHitByPitchStream << "\n";


    for (int p = 0; p < 16; p++) {
        Player* temp = pitchers[p];
        if (temp != NULL){
            pitcherSingleStream << temp->playerName << ",";
            pitcherDoubleStream << temp->playerName << ",";
            pitcherTripleStream << temp->playerName << ",";
            pitcherHomeRunStream << temp->playerName << ",";
            pitcherWalkStream << temp->playerName << ",";
            pitcherStrikeOutStream << temp->playerName << ",";
            pitcherHitByPitchStream << temp->playerName << ",";
        }
    }

    pitcherSingleStream << "\n";
    pitcherDoubleStream << "\n";
    pitcherTripleStream << "\n";
    pitcherHomeRunStream << "\n";
    pitcherWalkStream <<  "\n";
    pitcherStrikeOutStream << "\n";
    pitcherHitByPitchStream << "\n";

}

//This just closes all of the files
//good coding practice plus allows the data and files to be stored safely

void Team::closeOutputFile(){
    batterFile->close();
    pitcherFile->close();

    batterSingleFile->close();
    batterDoubleFile->close();
    batterTripleFile->close();
    batterHomeRunFile->close();
    batterWalksFile->close();
    batterStrikeOutFile->close();
    batterHitByPitchFile->close();

    pitcherSingleFile->close();
    pitcherDoubleFile->close();
    pitcherTripleFile->close();
    pitcherHomeRunFile->close();
    pitcherWalksFile->close();
    pitcherStrikeOutFile->close();
    pitcherHitByPitchFile->close();
}

//Prints all the season stats for each player to the desired output file

void Team::printSeasonStats() {

    int width = 7;

    QTextStream batterStream(batterFile);

    QTextStream batterSingleStream(batterSingleFile);
    QTextStream batterDoubleStream(batterDoubleFile);
    QTextStream batterTripleStream(batterTripleFile);
    QTextStream batterHomeRunStream(batterHomeRunFile);
    QTextStream batterWalkStream(batterWalksFile);
    QTextStream batterStrikeOutStream(batterStrikeOutFile);
    QTextStream batterHitByPitchStream(batterHitByPitchFile);

    batterStream << " Batting Stats\n" << "Name,PA,AB,H,1B,2B,3B,HR,RBI,BB,HBP,SO,BA,OBP,SLG,OPS\n";


    for (int p = 0; p < 9; p++) {
        Player* temp = battingOrder[p];
        if (temp != NULL){
            batterStream << temp->playerName << "," <<temp->seasonAtBatPlateAppereances << "," << temp->seasonAtBats << "," << temp->seasonAtBatHits << ",";
            batterStream << temp->seasonAtBatSingles << "," << temp->seasonAtBatDoubles << "," << temp->seasonAtBatTriples << "," << temp->seasonAtBatHomeruns << ",";
            batterStream << temp->seasonAtBatRuns << "," << temp->seasonAtBatWalks << "," << temp->seasonAtBatHitByPitch << "," << temp->seasonAtBatStrikeouts << ",";
            batterStream.setRealNumberPrecision(3);
            batterStream << temp->seasonBattingAverage << "," << temp->seasonOBP << "," << temp->seasonSLG << "," << temp->seasonOPS;
            batterStream << "\n";

            batterSingleStream << temp->seasonAtBatSingles / temp->seasonAtBatPlateAppereances << ",";
            batterDoubleStream << temp->seasonAtBatDoubles / temp->seasonAtBatPlateAppereances << ",";
            batterTripleStream << temp->seasonAtBatTriples / temp->seasonAtBatPlateAppereances<< ",";
            batterHomeRunStream << temp->seasonAtBatHomeruns / temp->seasonAtBatPlateAppereances << ",";
            batterWalkStream << temp->seasonAtBatWalks / temp->seasonAtBatPlateAppereances<< ",";
            batterStrikeOutStream << temp->seasonAtBatStrikeouts / temp->seasonAtBatPlateAppereances << ",";
            batterHitByPitchStream << temp->seasonAtBatHitByPitch / temp->seasonAtBatPlateAppereances<< ",";


        }
    }

    batterSingleStream << "\n";
    batterDoubleStream << "\n";
    batterTripleStream << "\n";
    batterHomeRunStream << "\n";
    batterWalkStream <<  "\n";
    batterStrikeOutStream << "\n";
    batterHitByPitchStream << "\n";

    batterStream << "\n\n";

    width = 8;

    QTextStream pitcherStream(pitcherFile);
    pitcherStream << TeamName << " Pitching Stats\n";
    pitcherStream << "Name, IP, H, R, ER, BB, SO, HR, HBP, ERA, BF, AB, 1B, 2B, 3B\n";
    QString pitcherNames [16];
    int pitcherNamesIndex = 0;
    for (int t = 0; t < 16; t++) {
        Pitcher* temp = availablePitchers[t];
        if (temp != NULL){
            if (!(containsPlayerName(temp->playerName, pitcherNames, pitcherNamesIndex))){
                pitcherStream.setRealNumberPrecision(4);
                pitcherStream << temp->playerName << "," << temp->seasonPitchInnings << "," << temp->seasonPitchHits << "," << temp->seasonPitchRunsAllowed << ",";
                pitcherStream << temp->seasonPitchRunsAllowed << "," << temp->seasonPitchWalks << "," << temp->seasonPitchStrikeouts << ",";
                pitcherStream.setRealNumberPrecision(3);
                pitcherStream << temp->seasonPitchHomeRuns << "," << temp->seasonPitchHitBatters << "," << temp->seasonPitchERA << ",";
                pitcherStream << temp->seasonPitchPlateAppereances << "," << temp->seasonPitchAtBats << "," << temp->seasonPitchSingles << ",";
                pitcherStream << temp->seasonPitchDoubles << "," << temp->seasonPitchTriples << "\n";
                pitcherNames[pitcherNamesIndex] = temp->playerName;
                pitcherNamesIndex++;


            }
        }
    }
    pitcherStream << "\n\n";

    QTextStream pitcherSingleStream(pitcherSingleFile);
    QTextStream pitcherDoubleStream(pitcherDoubleFile);
    QTextStream pitcherTripleStream(pitcherTripleFile);
    QTextStream pitcherHomeRunStream(pitcherHomeRunFile);
    QTextStream pitcherWalkStream(pitcherWalksFile);
    QTextStream pitcherStrikeOutStream(pitcherStrikeOutFile);
    QTextStream pitcherHitByPitchStream(pitcherHitByPitchFile);

    for (int p = 0; p < 16; p++) {
        Pitcher* temp = pitchers[p];
        if (temp != NULL){
           if (temp->seasonPitchPlateAppereances != 0) {
                double singlePercent = temp->seasonPitchSingles;
                pitcherSingleStream << (double)temp->seasonPitchSingles / (double)temp->seasonPitchPlateAppereances << ",";
                pitcherDoubleStream << (double)temp->seasonPitchDoubles / (double)temp->seasonPitchPlateAppereances << ",";
                pitcherTripleStream << (double)temp->seasonPitchTriples / (double)temp->seasonPitchPlateAppereances << ",";
                pitcherHomeRunStream << (double)temp->seasonPitchHomeRuns / (double)temp->seasonPitchPlateAppereances << ",";
                pitcherWalkStream << (double)temp->seasonPitchWalks / (double)temp->seasonPitchPlateAppereances << ",";
                pitcherStrikeOutStream << (double)temp->seasonPitchStrikeouts  / (double)temp->seasonPitchPlateAppereances << ",";
                pitcherHitByPitchStream << (double)temp->seasonPitchHitBatters / (double)temp->seasonPitchPlateAppereances << ",";
           }
           else {
               pitcherSingleStream << 0 << ",";
               pitcherDoubleStream << 0 << ",";
               pitcherTripleStream << 0 << ",";
               pitcherHomeRunStream << 0 << ",";
               pitcherWalkStream << 0 << ",";
               pitcherStrikeOutStream << 0 << ",";
               pitcherHitByPitchStream << 0 << ",";

           }
        }
    }

    pitcherSingleStream << "\n";
    pitcherDoubleStream << "\n";
    pitcherTripleStream << "\n";
    pitcherHomeRunStream << "\n";
    pitcherWalkStream <<  "\n";
    pitcherStrikeOutStream << "\n";
    pitcherHitByPitchStream << "\n";
}

//This is extremely important because it sets all of the player season stats to 0
// if this is not done the output that comes later when you try to the read the
// data is way off. (Random numbers off the stack will be given to each variable

void Team::startSeason(){
    for(int i = 0; i < 9; i++){
        battingOrder[i]->startSeason();
    }
    for(int p = 0; p < 9; p++){
        startingRotation[p]->startPitcherSeason();
        //std::cout << "started pitcher\n";
    }
    //std::cout << "started pitchers";
    for(int l = 0; l < 7; l++){
        bullpen[l]->startPitcherSeason();
    }
}

void Team::startGame(QString pitcherName){
    pitcherIndex = 0;
    for(int i = 0; i < 9; i++){
        battingOrder[i]->startGame();
    }

    for(int j = 1; j < 9; j++){
        if(startingRotation[j]->playerName == pitcherName){
            Pitcher* temp = startingRotation[0];
            startingRotation[0] = startingRotation[j];
            startingRotation[j] = temp;
            break;
        }
    }

    startingRotation[0]->startPitcherGame();
    availablePitchers[0] = startingRotation[0];


    for (int w = 0; w < 7; w++){
        availablePitchers[w+1] = bullpen[w];
    }
    for (int m = 0; m < 8; m++){
        availablePitchers[m+8] = startingRotation[m+1];
    }

    for(int y = 0; y < 16; y++){
        availablePitchers[y]->pitchedThisGame = false;
    }
}

void Team::printGameStats(){
    std::cout.width(50);
    //std::cout << TeamName << " Game Batting Stats\n\n";
    std::cout.width(18);
    std::cout << "Name";
    std::cout.width(5);
    std::cout << "PA";
    std::cout.width(5);
    std::cout << "AB";
    std::cout.width(5);
    std::cout << "H";
    std::cout.width(5);
    std::cout << "1B";
    std::cout.width(5);
    std::cout << "2B";
    std::cout.width(5);
    std::cout << "3B";
    std::cout.width(5);
    std::cout << "HR";
    std::cout.width(5);
    std::cout << "RBI";
    std::cout.width(5);
    std::cout << "BB";
    std::cout.width(5);
    std::cout << "HBP";
    std::cout.width(5);
    std::cout << "SO";
    std::cout.width(8);
    std::cout << "BA";
    std::cout.width(8);
    std::cout << "OBP";
    std::cout.width(8);
    std::cout << "SLG";
    std::cout.width(8);
    std::cout << "OPS";
    std::cout << "\n";


    for (int p = 0; p < 9; p++) {
        Player* temp = battingOrder[p];
        if (temp != NULL){
            std::cout.width(18);
            //std::cout << temp->playerName;
            std::cout.width(5);
            std::cout << temp->gamePlateAppereances;
            std::cout.width(5);
            std::cout << temp->gameAtBats;
            std::cout.width(5);
            std::cout << temp->gameAtBatHits;
            std::cout.width(5);
            std::cout << temp->gameAtBatSingle;
            std::cout.width(5);
            std::cout << temp->gameAtBatDouble;
            std::cout.width(5);
            std::cout << temp->gameAtBatTriple;
            std::cout.width(5);
            std::cout << temp->gameAtBatHomeRun;
            std::cout.width(5);
            std::cout << temp->gameAtBatRuns;
            std::cout.width(5);
            std::cout << temp->gameAtBatWalk;
            std::cout.width(5);
            std::cout << temp->gameAtBatHitByPitch;
            std::cout.width(5);
            std::cout << temp->gameAtBatStrikeOut;
            printf("   %0.3f", temp->gameBattingAverage);
            printf("   %0.3f", temp->gameOBP);
            printf("   %0.3f", temp->gameSLG);
            printf("   %0.3f", temp->gameOPS);
            std::cout << "\n\n";
        }

    }

    std::cout.width(50);
    //std::cout << TeamName << " Game Pitching Stats\n\n";
    std::cout.width(18);
    std::cout << "Name";
    std::cout.width(5);
    std::cout << "IP";
    std::cout.width(5);
    std::cout << "H";
    std::cout.width(5);
    std::cout << "R";
    std::cout.width(5);
    std::cout << "ER";
    std::cout.width(5);
    std::cout << "BB";
    std::cout.width(5);
    std::cout << "SO";
    std::cout.width(5);
    std::cout << "HR";
    std::cout.width(5);
    std::cout << "HBP";
    std::cout.width(8);
    std::cout << "ERA";
    std::cout.width(5);
    std::cout << "BF";
    std::cout.width(5);
    std::cout << "AB";
    std::cout.width(5);
    std::cout << "1B";
    std::cout.width(5);
    std::cout << "2B";
    std::cout.width(5);
    std::cout << "3B";
    std::cout << "\n";
    QString pitcherNames[16];
    int pitcherNamesIndex = 0;
    for (int t = 0; t < 16; t++) {
        Pitcher* tempPitcher = availablePitchers[t];
        if(tempPitcher != NULL){
            if (tempPitcher->pitchedThisGame) {
                if (!(containsPlayerName(tempPitcher->playerName, pitcherNames, pitcherNamesIndex))){
                    std::cout.width(18);
                    //std::cout << tempPitcher->playerName;
                    printf(" %*.1f",5,tempPitcher->gamePitchInnings);
                    std::cout.width(5);
                    std::cout << tempPitcher->gamePitchHits;
                    std::cout.width(5);
                    std::cout << tempPitcher->gamePitchRunsAllowed;
                    std::cout.width(5);
                    std::cout << tempPitcher->gamePitchRunsAllowed;
                    std::cout.width(5);
                    std::cout << tempPitcher->gamePitchWalks;
                    std::cout.width(5);
                    std::cout << tempPitcher->gamePitchStrikeouts;
                    std::cout.width(5);
                    std::cout << tempPitcher->gamePitchHomeRuns;
                    std::cout.width(5);
                    std::cout << tempPitcher->gamePitchHitBatters;
                    printf("   %.3f",tempPitcher->gamePitchERA);
                    std::cout.width(5);
                    std::cout << tempPitcher->gamePitchPlateAppereances;
                    std::cout.width(5);
                    std::cout << tempPitcher->gamePitchAtBats;
                    std::cout.width(5);
                    std::cout << tempPitcher->gamePitchSingles;
                    std::cout.width(5);
                    std::cout << tempPitcher->gamePitchDoubles;
                    std::cout.width(5);
                    std::cout << pitcher->gamePitchTriples;
                    std::cout << "\n\n";
                    pitcherNames[pitcherNamesIndex] = tempPitcher->playerName;
                    pitcherNamesIndex++;
                }
            }
        }
    }
}

bool Team::containsPlayerName(QString playerName, QString pitcherNames[16], int index){
     for (int i = 0; i < index; i++){
         if (playerName == pitcherNames[i]){
             return true;
         }
     }
     return false;
}

Pitcher* Team::returnPitcher(QString pitcherName){
    for (int i = 0; i < 16; i++){
        if (availablePitchers != NULL){
            if (availablePitchers[i]->playerName == pitcherName){
                return availablePitchers[i];
            }
        }
    }
    std::cout << "could not find player" << std::endl;
    return NULL;
}

//this is where the directories that the data will be outputed into are created;

bool Team::createDirectories(){
    QString homePath = QString::fromStdString(destination);
    QString location = homePath + "/" + TeamName;
    QDir dir = (location);
    bool madeDirectory = dir.mkpath(location);
    if (!madeDirectory){
        return false;
    }
    QString pitcherLocation= homePath + "/" + TeamName + "/Pitcher";
    QDir pitcher = (pitcherLocation);
    madeDirectory = pitcher.mkpath(pitcherLocation);
    if (!madeDirectory){
        return false;
    }
    QString batterLocation = homePath + "/" + TeamName + "/Batter";
    QDir batter = (batterLocation);
    madeDirectory = batter.mkpath(batterLocation);
    if (!madeDirectory){
        return false;
    }
}
