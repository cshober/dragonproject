// CSCI 1300 Spring 2020
// Author: Colin Shober and Lucca Chiappetta
// Recitation: 204 - Thanika Reddy (Colin)
// Recitation: 203 - Soumyajyoti Bhattacharya (Lucca)
// Project 3 - User.cpp

#include "User.h"
#include <iostream>
#include <string>
using namespace std;

User::User() {
    username = "";
    currentDragon = "Weedleshnee";
    egg = false;
    map = false;
    stone = false;
    cloud = false;
    coins = 5; //each player starts with 5 coins in the beginning of the game
    for (int i = 0; i < 12; i++){
        inventory[i] = "EMPTY";
    }
}

void User::setUsername(string username_) {
    username = username_;
}

string User::getUsername() {
    return username;
}

void User::setCoins(int coins_) {
    coins = coins_;
}

int User::getCoins() {
    return coins;
}

void User::addCoins(int coins_) {
    coins += coins_;
}

void User::removeCoins(int coins_) {
    coins -= coins_;
}
void User::setInventory(string str)
{
    for (int i = 0; i < 12; i++){
        if (inventory[i] == "EMPTY"){
            inventory[i] = str;
            return;
        }
    }
}
void User::setInventoryAt(string str, int i)
{
    inventory[i] = str;
}
string User::getInventory(int i){
    if (i >= 0 && i < 12){
        return inventory[i];
    }  
    else {
        return "invalid index";
    }
}
int User::getInventorySize(){
    int count;
    for (int i = 0; i < 12; i++){
        if (inventory[i] != "EMPTY"){
            count++;
        }
    }
    return count;
}
void User::setCurDragon(string dragon_){
    currentDragon = dragon_;
}
string User::getCurDragon(){
    return currentDragon;
}
void User::setEgg(bool egg_){
    egg = egg_;
}
bool User::getEgg(){
    return egg;
}
void User::setMap(bool map_){
    map = map_;
}
bool User::getMap(){
    return map;
}
void User::setStone(bool stone_){
    stone = stone_;
}
bool User::getStone(){
    return stone;
}
void User::setCloud(bool cloud_){
    cloud = cloud_;
}
bool User::getCloud(){
    return cloud;
}