// CSCI 1300 Spring 2020
// Author: Colin Shober and Lucca Chiappetta
// Recitation: 204 - Thanika Reddy (Colin)
// Recitation: 203 - Soumyajyoti Bhattacharya (Lucca)
// Project 3 - Items.cpp

#include "Items.h"
#include <string>
using namespace std;

Items::Items(){
    iName = "";
    iRarity = "";
    iDescription = "";
}
void Items::setIName(string name_){
    iName = name_;
}
string Items::getIName(){
    return iName;
}
void Items::setIRarity(string rarity_){
    iRarity = rarity_;
}
string Items::getIRarity(){
    return iRarity;
}
void Items::setIDescription(string description_){
    iDescription = description_;
}
string Items::getIDescription(){
    return iDescription;
}
void Items::setIPrice(int price_){
    iPrice = price_;
}   
int Items::getIPrice(){
    return iPrice;
}