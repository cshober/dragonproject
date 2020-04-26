// CSCI 1300 Spring 2020
// Author: Colin Shober and Lucca Chiappetta
// Recitation: 204 - Thanika Reddy (Colin)
// Recitation: 203 - Soumyajyoti Bhattacharya (Lucca)
// Project 3 - Items.h

#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <string>
using namespace std;

class Items {
    private:
    string iName;
    string iRarity;
    string iDescription;
    int iPrice;

    public:
    Items(); //parametrized
    void setIName(string); //setters and getters for variables
    string getIName();
    void setIRarity(string);
    string getIRarity();
    void setIDescription(string);
    string getIDescription();
    void setIPrice(int);
    int getIPrice();
};
#endif
