// CSCI 1300 Spring 2020
// Author: Colin Shober and Lucca Chiappetta
// Recitation: 204 - Thanika Reddy (Colin)
// Recitation: 203 - Soumyajyoti Bhattacharya (Lucca)
// Project 3 - Game.h


#ifndef GAME_H
#define GAME_H
#include "Dragons.h"
#include "Map.h"
#include "Items.h"
#include "User.h"
#include <string>
using namespace std;

class Game {
    private:
    Map map;
    User user;
    Items items[20];
    Dragons dragons[20];

    public:
    //Start
    Game(); //default contructor
    void readItems(string); //read the item file
    void readMap(string); //read map file
    void readDragons(string); //read dragon file

    //Dragon
    void viewDragons(string);
    void printCurDragon();
    void printDragon(string);
    string hatchEgg();
    void randomDragon(); //random dragon fight
    bool dragonFight(string);

    //Map
    void checkTile(); //have tile react
    void printWholeMap();
    void printMap();
    void printShop(int,int);
    void printIncStation(int,int);
    void travel();

    //Items
    void giveItems();
    void printItems(string);
    int getPriceByName(string);

    //User
    void viewInventory();
    void setUsername(string);
    string getUsername();

    //Other
    void endGame();

};
#endif