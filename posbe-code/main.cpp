//#include <QCoreApplication>
#include "player.h"
#include "era.h"
#include "game.h"
#include "fielder.h"
#include "pitcher.h"
#include "team.h"
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <qtextstream.h>
#include <QFile>
#include <QDir>

std::ofstream outputFile;

void demo(){

    // this is telling the program to create the Yankees and Red Sox
    // the values for both teams have been hard coded into the program see team.cpp
    // the second part of the constructor is the directory in which you want the data to go

    Team* yankees = new Team(1, "/Users/Nick Schneider/Desktop/Baseball_Engine/Simulated Data/");
    Team* redSox = new Team(2, "/Users/Nick Schneider/Desktop/Baseball_Engine/Simulated Data/");

    yankees->createDirectories();
    redSox->createDirectories();

    // this sets all the season values to 0
    // this piece of code is vital to your stats because I used pointers
    // without this your season stats will essentially be random numbers
    yankees->startSeason();
    redSox->startSeason();

    //intializing all the variables for the loops below
    int amountOfSims = 1000;

    QString yankeePitcher = "";
    QString redSoxPitcher = "";

    Team* home = yankees;
    Team* away = redSox;

    QString homePitcher;
    QString awayPitcher;

    home->openOutputFile();
    away->openOutputFile();

    for (int i = 0; i < amountOfSims; i++){
        yankees->startSeason();
        redSox->startSeason();

        for (int t = 0; t < 19; t++) {
            if (t == 0){
                yankeePitcher = "Nathan Eovaldi";
                redSoxPitcher = "Wade Miley";
                homePitcher = yankeePitcher;
                awayPitcher = redSoxPitcher;
            }
            else if (t == 1){
                yankeePitcher = "Adam Warren";
                redSoxPitcher = "Joe Kelly";
                homePitcher = yankeePitcher;
                awayPitcher = redSoxPitcher;
            }
            else if (t == 2){
                yankeePitcher = "Masahiro Tanaka";
                redSoxPitcher = "Clay Bucholz";
                homePitcher = yankeePitcher;
                awayPitcher = redSoxPitcher;
            }
            else if (t == 3){
                yankeePitcher = "CC Sabathia";
                redSoxPitcher = "Justin Masterson";
                awayPitcher = yankeePitcher;
                homePitcher = redSoxPitcher;
                home = redSox;
                away = yankees;
            }
            else if (t == 4){
                yankeePitcher = "Nathan Eovaldi";
                redSoxPitcher = "Wade Miley";
                awayPitcher = yankeePitcher;
                homePitcher = redSoxPitcher;
                home = redSox;
                away = yankees;
            }
            else if (t == 5){
                yankeePitcher = "Adam Warren";
                redSoxPitcher = "Joe Kelly";
                awayPitcher = yankeePitcher;
                homePitcher = redSoxPitcher;
                home = redSox;
                away = yankees;
            }
            else if (t == 6){
                yankeePitcher = "Micheal Pineda";
                redSoxPitcher = "Clay Bucholz";
                awayPitcher = yankeePitcher;
                homePitcher = redSoxPitcher;
                home = redSox;
                away = yankees;
            }
            else if (t == 7){
                yankeePitcher = "Ivan Nova";
                redSoxPitcher = "Eduardo Rodriguez";
                awayPitcher = yankeePitcher;
                homePitcher = redSoxPitcher;
                home = redSox;
                away = yankees;
            }
            else if (t == 8){
                yankeePitcher = "Nathan Eovaldi";
                redSoxPitcher = "Wade Miley";
                awayPitcher = yankeePitcher;
                homePitcher = redSoxPitcher;
                home = redSox;
                away = yankees;
            }
            else if (t == 9){
                yankeePitcher = "Masahiro Tanaka";
                redSoxPitcher = "Henry Owens";
                homePitcher = yankeePitcher;
                awayPitcher = redSoxPitcher;
                home = yankees;
                away = redSox;
            }
            else if (t == 10){
                yankeePitcher = "Luis Severino";
                redSoxPitcher = "Steven Wright";
                homePitcher = yankeePitcher;
                awayPitcher = redSoxPitcher;
                home = yankees;
                away = redSox;
            }
            else if (t == 11){
                yankeePitcher = "CC Sabathia";
                redSoxPitcher = "Eduardo Rodriguez";
                homePitcher = yankeePitcher;
                awayPitcher = redSoxPitcher;
                home = yankees;
                away = redSox;
            }
            else if (t == 12){
                yankeePitcher = "Ivan Nova";
                redSoxPitcher = "Eduardo Rodriguez";
                homePitcher = redSoxPitcher;
                awayPitcher = yankeePitcher;
                home = redSox;
                away = yankees;
            }
            else if (t == 13){
                yankeePitcher = "Micheal Pineda";
                redSoxPitcher = "Rick Porcello";
                homePitcher = redSoxPitcher;
                awayPitcher = yankeePitcher;
                home = redSox;
                away = yankees;
            }
            else if (t == 14){
                yankeePitcher = "Masahiro Tanaka";
                redSoxPitcher = "Henry Owens";
                homePitcher = redSoxPitcher;
                awayPitcher = yankeePitcher;
                home = redSox;
                away = yankees;
            }
            else if (t == 15){
                yankeePitcher = "Ivan Nova";
                redSoxPitcher = "Eduardo Rodriguez";
                homePitcher = yankeePitcher;
                awayPitcher = redSoxPitcher;
                home = yankees;
                away = redSox;
            }
            else if (t == 16){
                yankeePitcher = "Micheal Pineda";
                redSoxPitcher = "Rick Porcello";
                homePitcher = yankeePitcher;
                awayPitcher = redSoxPitcher;
                home = yankees;
                away = redSox;
            }
            else if (t == 17){
                yankeePitcher = "Masahiro Tanaka";
                redSoxPitcher = "Wade Miley";
                homePitcher = yankeePitcher;
                awayPitcher = redSoxPitcher;
                home = yankees;
                away = redSox;
            }
            else if (t == 18){
                yankeePitcher = "CC Sabathia";
                redSoxPitcher = "Rich Hill";
                awayPitcher = yankeePitcher;
                homePitcher = redSoxPitcher;
                home = redSox;
                away = yankees;
            }
            //this is where the game is started. Note if the last variable in the
            //game constructor is set to true the program will produce a play-by-play
            //the game also has built in functionality that when you pass it a pitcher name it will make that pitcher start

            Game game(home, away, homePitcher, awayPitcher, false, "/Users/Nick Schneider/Desktop/Baseball_Engine/Simulated Data/");
            game.gameStart();

            //since I am doing 19,000 simulations for this project I do not want to see the game
            //results so I commented out the methods that would show me the score and stats

        }
        std::cout<<"\n\t\t\t\t\tSIMULATION NUMBER "<<i<<"\n";
        yankees->printSeasonStats();
        redSox->printSeasonStats();
    }
    yankees->closeOutputFile();
    redSox->closeOutputFile();

    printf("\n\t\t\t\t\t\tDONE!!\n");

}

void thesisDemo(){

    Team* yankees = new Team(1, "/Users/Nick Schneider/Desktop/Baseball_Engine/Simulated Data/");
    Team* redSox = new Team(2, "/Users/Nick Schneider/Desktop/Baseball_Engine/Simulated Data/");

    yankees->startSeason();
    redSox->startSeason();

    Team* home = yankees;
    Team* away = redSox;

    QString yankeePitcher = "Masahiro Tanaka";
    QString redSoxPitcher = "Clay Bucholz";

    QString homePitcher = yankeePitcher;
    QString awayPitcher = redSoxPitcher;

    Game game(home, away, homePitcher, awayPitcher, true, "/Users/Nick Schneider/Desktop/Baseball_Engine/Simulated Data/");
    game.gameStart();

}

int main(int argc, char *argv[])
{
    int input = 0;
    while (input != 5) {
        std::cout << "\n\n\n";
        std::cout << "\t\tWelcome to Probabilistic Open Source Baseball Engine\n\n\n";
        std::cout << "1) Thesis Expirement\n\n2) Thesis Demo\n\n";
        //std::cout << "3) Simulate Game\n\n4) Simulate Game with Play By play\n\n5) End\n\n\n";
        std::cin >> input;
        int end = 0;

        if (input == 1) {
            demo();
            int end = 0;
            std::cout << "Enter: \n0) To return to main\n1) To end Program\n";
            std::cin >> end;
            if (end == 1){
                input = 5;
            }
            else {
                input = 0;
            }
        }
        else if (input == 2){
            thesisDemo();
            std::cout << "Enter: \n0) To return to main\n1) To end Program\n";
            std::cin >> end;
            if (end == 1){
                input = 5;
            }
            else {
                input = 0;
            }
        }
        else if (input == 3){
           std::cout << "Functionality has not been built yet\n";

           //The block of code below is in the infancy stage of changing the output directory
           //Note that when the team class is called you can pass it a directory
           //This will allow the user to change directories at will

           /*while (end != 5){
               QString homePath = QDir::currentPath();
               std::string path = homePath.toStdString();
               std::cout << "note the default path is : \n" << path << "\n\n";
               std::string directory;
               //std::cout << "Do you want to change the directory
               std::cout << "Enter the directory for your Output: ";
               std::cin >> directory;
               QString location = QString::fromStdString(directory);
               QDir dir = ("C:/Users/");
               location = "C:/Users/Nick Schneider/Desktop;
               dir.setCurrent(location);

               homePath = QDir::currentPath();
               path = homePath.toStdString();
               std::cout << "path is : \n" << path << "\n\n";

               bool madeDirectory = dir.mkpath(location);
               if (!madeDirectory){
                   std::cout << "\nnot a valid memory location\n";
               }
               else{
                   dir.cd(location);
                   QString pathCreated = dir.currentPath();
                   std::string newFolder = homePath.toStdString();
                   std::cout << "The location of your folder is: \n" << path << "\n\n";
               }
               std::cout << "Enter: \n0) To return to main\n1) To end Program\n";
               std::cin >> end;
               if (end == 1){
                  input = 5;
               }
               else {
                   input = 0;
               }
            }*/
        }
        else if (input == 4){
           std::cout << "Functionality has not been built yet\n";
           if (end == 1){
               input = 5;
           }
           else {
               input = 0;
           }
        }
        else if (input == 5){
            break;
        }
        else {
            std::cout << "enter a valid input\n";
        }
    }
}

