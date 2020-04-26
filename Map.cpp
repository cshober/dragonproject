// CSCI 1300 Spring 2020
// Author: Colin Shober and Lucca Chiappetta
// Recitation: 204 - Thanika Reddy (Colin)
// Recitation: 203 - Soumyajyoti Bhattacharya (Lucca)
// Project 3 - Map.cpp

#include "Map.h"
#include <string>
using namespace std;


Map::Map()
{
    for (int i = 0; i < 40; i++){
        for (int j = 0; j < 50; j++){
            map[i][j] = "";
        }
    }
    for (int i = 0; i < 40; i++){
        for (int j = 0; j < 50; j++){
            if (i == 19 && j == 17) //19,17
            {
                playMap[i][j] = 1;
            }
            else
                playMap[i][j] = 0;
        }
    } 
}
void Map::setTile(int i, int j, string str) {
    map[i][j] = str;
}

string Map::getTile(int i, int j) {
        return map[i][j];
}
void Map::setPlayerLoc(int i,int j) {
    if (i >= 0 && i < 40 && j >= 0 && j < 50)
    {
        playMap[i][j] = 1;
        playMap[i + 1][j] = 0;
        playMap[i - 1][j] = 0;
        playMap[i][j + 1] = 0;
        playMap[i][j - 1] = 0;
    }
}
int Map::getPlayerX() {
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 50; j++) {
            if (playMap[i][j] == 1)
                return i;
        }
    }
    return -1;
}
int Map::getPlayerY() {
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 50; j++) {
            if (playMap[i][j] == 1)
                return j;
        }
    }
    return -1;
}