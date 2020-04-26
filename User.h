// CSCI 1300 Spring 2020
// Author: Colin Shober and Lucca Chiappetta
// Recitation: 204 - Thanika Reddy (Colin)
// Recitation: 203 - Soumyajyoti Bhattacharya (Lucca)
// Project 3 - User.h

#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User {
    private:
    string username;
    string inventory[12]; //inventory size of 12
    string currentDragon; //current dragon and stats
    int dragCurHealth;
    int coins;
    bool egg;
    bool map;
    bool stone;
    bool cloud;
    
    public:
    User(); //default functions
    void setUsername(string); //sets username for player
    string getUsername(); //returns username
    void setCoins(int); //sets coins with inputted integer
    int getCoins(); //returns number of coins
    void addCoins(int); //adds coins to the existing number of coins
    void removeCoins(int); //removes coins with inputted integer
    void setInventory(string); //set point in inventory at indec
    void setInventoryAt(string, int);
    string getInventory(int); //returns inventory at index
    int getInventorySize();
    void setCurDragon(string); //sets your cuurent dragon and stats
    string getCurDragon(); //returns the name and stats of current dragon
    void setEgg(bool);
    bool getEgg();
    void setMap(bool);
    bool getMap();
    void setStone(bool);
    bool getStone();
    void setCloud(bool);
    bool getCloud();


    

};
#endif