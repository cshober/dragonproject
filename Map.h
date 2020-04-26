// CSCI 1300 Spring 2020
// Author: Colin Shober and Lucca Chiappetta
// Recitation: 204 - Thanika Reddy (Colin)
// Recitation: 203 - Soumyajyoti Bhattacharya (Lucca)
// Project 3 - Map.h

#ifndef MAP_H
#define MAP_H
#include <string>
using namespace std;

class Map {
    private:
    string map[40][50]; //Actual map
    int playMap[40][50]; //map to keep track of player

    public:
    Map(); //default constructor
    void setTile(int,int,string);
    string getTile(int, int); //returns til based off of passed ints
    void setPlayerLoc(int,int); //set players location
    int getPlayerX(); //gets x coord for player
    int getPlayerY(); //gets y coord for player
    void printMap(); //print full map
};
#endif