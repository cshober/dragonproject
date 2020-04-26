// CSCI 1300 Spring 2020
// Author: Colin Shober and Lucca Chiappetta
// Recitation: 204 - Thanika Reddy (Colin)
// Recitation: 203 - Soumyajyoti Bhattacharya (Lucca)
// Project 3 - Dragons.cpp

#include "Dragons.h"
#include <string>
using namespace std;

Dragons::Dragons(){
    dName = "";
    dRarity = "";
    dType = "";
    dDescription = "";
    dAttack = 0;
    dHealth = 0;
    dSpeed = 0;
    dMaxHealth = 0;
}
void Dragons::setDName(string name_){
    dName = name_;
}
string Dragons::getDName(){
    return dName;
}
void Dragons::setDRarity(string rarity_){
    dRarity = rarity_;
}
string Dragons::getDRarity(){
    return dRarity;
}
void Dragons::setDType(string type_){
    dType = type_;
}
string Dragons::getDType(){
    return dType;
}
void Dragons::setDDescription(string description_){
    dDescription = description_;
}
string Dragons::getDDescription(){
    return dDescription;
}
void Dragons::setDAttack(int attack_){
    dAttack = attack_;
}
int Dragons::getDAttack(){
    return dAttack;
}
void Dragons::setDHealth(int health_){
    dHealth = health_;
}
int Dragons::getDHealth(){
    return dHealth;
}
void Dragons::setDSpeed(int speed_){
    dSpeed = speed_;
}
int Dragons::getDSpeed(){
    return dSpeed;
}
void Dragons::setDMaxHealth(int maxHealth_){
    dMaxHealth = maxHealth_;
}
int Dragons::getDMaxHealth(){
    return dMaxHealth;
}
