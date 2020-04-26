// CSCI 1300 Spring 2020
// Author: Colin Shober and Lucca Chiappetta
// Recitation: 204 - Thanika Reddy (Colin)
// Recitation: 203 - Soumyajyoti Bhattacharya (Lucca)
// Project 3 - Dragons.h

#ifndef DRAGONS_H
#define DRAGONS_H
#include <iostream>
#include <string>
using namespace std;

class Dragons
{
    private:
    string dName;
    string dRarity;
    string dType;
    string dDescription;
    int dAttack;
    int dHealth;
    int dSpeed;
    int dMaxHealth;

    public:
    Dragons();
    void setDName(string);
    string getDName();
    void setDRarity(string);
    string getDRarity();
    void setDType(string);
    string getDType();
    void setDDescription(string);
    string getDDescription();
    void setDAttack(int);
    int getDAttack();
    void setDHealth(int);
    int getDHealth();
    void setDMaxHealth(int);
    int getDMaxHealth();
    void setDSpeed(int);
    int getDSpeed();
};
#endif