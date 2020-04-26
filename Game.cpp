// CSCI 1300 Spring 2020
// Author: Colin Shober and Lucca Chiappetta
// Recitation: 204 - Thanika Reddy (Colin)
// Recitation: 203 - Soumyajyoti Bhattacharya (Lucca)
// Project 3 - Game.cpp

#include "Game.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//Helper Functions
int randomNumbers(int min, int max) {
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}
int split(string str, char lim, string arr[], int size){
    if (str == "") //if the string is empty return 0
        return 0;

    string word = ""; //create variable to hold each word
    str += lim; //add delimiter to end of the string so the prgram knows when the last word ends
    int count = 0; //create counter to hold number of elements
    for (int i = 0; i < str.length(); i++) //for loop that runs through each charcter of string
    {
        if (str[i] == lim && word != "") //if the string at index is the delimiter or the word is empty (2 delimters in a row)
        {
            arr[count] = word; //set the array at current count to the string stored in word variable
            count++; //add 1 to the number of elements
            word = ""; //reset the word variable to empty to store the next word
            if (count > size) //check to see the size is still in bounds to prevent seg fault
            {
                return -1;
            }
        }
        else if (str[i] != lim) //if the delimter is not reached
        {
            word += str[i]; //add character at indx to the word variable
        }
    }
    return count; //return number of elements
}
string toUpper(string str){
    string upper = ""; //create a new empty string to hold uppercase values
    for (int i = 0; i < str.length(); i++) //for loop that runs for every character in the string
    {
        upper += (char)toupper(str[i]); //for each loop cast the string to a character, turn it uppercase, and add it to the upper string
    }
    return upper; //return the new string
}

//Read Functions
Game::Game(){}
void Game::readItems(string file){
    ifstream myFile;
    myFile.open(file);
    string line;
    string arr[4];
    int count = 0 ;
    if (myFile.is_open()){
        while(getline(myFile, line)){
            split(line, ',', arr, 4);
            items[count].setIName(arr[0]);
            items[count].setIRarity(arr[1]);
            items[count].setIDescription(arr[2]);
            items[count].setIPrice(stoi(arr[3]));
            count++;
        }
    }
    else{
        return;
    }
}
void Game::readDragons(string file){
    ifstream myFile;
    myFile.open(file);
    string line = "";
    string arr[7];
    int count = 0 ;
    if (myFile.is_open()){
        while(getline(myFile, line)){
            split(line, ',', arr, 6);
            dragons[count].setDName(arr[0]);
            dragons[count].setDRarity(arr[1]);
            dragons[count].setDType(arr[2]);
            dragons[count].setDAttack(stoi(arr[3]));
            dragons[count].setDHealth(stoi(arr[4]));
            dragons[count].setDMaxHealth(stoi(arr[4]));
            dragons[count].setDSpeed(stoi(arr[5]));
            dragons[count].setDDescription(arr[6]);
            count++;
        }
    }
}
void Game::readMap(string file){
    ifstream myFile;
    myFile.open(file);
    string line = "";
    string arr [50];
    int count = 0;
    if (myFile.is_open()){
        while(getline(myFile,line)){
            split(line, ',', arr, 50);
            for (int i = 0; i < 50; i++)
            {
                map.setTile(count, i, arr[i]);
            }
            count++;
        }
    }
}

//Dragon Functions
void Game::viewDragons(string str){
    if (toUpper(str) == "COMMON"){
        cout << "Common Dragons:" << endl;
        for (int i = 12; i < 20; i++)
        {
            cout << "----" << dragons[i].getDName() << " (" << dragons[i].getDType() << ")" << "----" << endl;
            cout << "Attack: " << dragons[i].getDAttack() << endl;
            cout << "Health: " << dragons[i].getDHealth() << endl;
            cout << "Speed: " << dragons[i].getDSpeed() << endl;
            cout << dragons[i].getDDescription() << endl;
        }
    }
    if (toUpper(str) == "RARE"){
        cout << "Rare Dragons:" << endl;
        for (int i = 4; i < 12; i++){
            cout << "----" << dragons[i].getDName() << " (" << dragons[i].getDType() << ")" << "----" << endl;
            cout << "Attack: " << dragons[i].getDAttack() << endl;
            cout << "Health: " << dragons[i].getDHealth() << endl;
            cout << "Speed: " << dragons[i].getDSpeed() << endl;
            cout << dragons[i].getDDescription() << endl;
        }
    }
    if (toUpper(str) == "EPIC"){
        cout << "Epic Dragons:" << endl;
        for (int i = 1; i < 4; i++){
            cout << "----" << dragons[i].getDName() << " (" << dragons[i].getDType() << ")" << "----" << endl;
            cout << "Attack: " << dragons[i].getDAttack() << endl;
            cout << "Health: " << dragons[i].getDHealth() << endl;
            cout << "Speed: " << dragons[i].getDSpeed() << endl;
            cout << dragons[i].getDDescription() << endl;      
        }
    }
    if (toUpper(str) == "LEGENDARY")
    {
        cout << "----" << dragons[0].getDName() << " (" << dragons[0].getDType() << ")" << "----" << endl;
        cout << "Attack: " << dragons[0].getDAttack() << endl;
        cout << "Health: " << dragons[0].getDHealth() << endl;
        cout << "Speed: " << dragons[0].getDSpeed() << endl;
        cout << dragons[0].getDDescription() << endl;         
    }
}
void Game::printCurDragon(){ //printing stats of dragon
    if (user.getCurDragon() == ""){
        cout << "You don't currently have a dragon! Be careful!" << endl;
        return;
    }
    for (int i = 0; i < 20; i++)
    {
        if (user.getCurDragon() == dragons[i].getDName())
        {
            cout << "----" << dragons[i].getDName() << " (" << dragons[i].getDType() << ")" << "----" << endl;
            cout << "Attack: " << dragons[i].getDAttack() << endl;
            cout << "Health: " << dragons[i].getDHealth() << endl;
            cout << "Speed: " << dragons[i].getDSpeed() << endl;
            cout << "Rarity: " << dragons[i].getDRarity() << endl;
            cout << dragons[i].getDDescription() << endl;
        }
    }
    cout << "1. Main Menu" << endl << "2. Set free" << endl;
    bool check = false;
    int menu;
    while (!check){
        cin >> menu;
        if (menu == 1){
            check = true;
            return;
        }
        if (menu == 2){
            if (user.getCurDragon() == ""){
                cout << "You don't currently have a dragon!" << endl;
                return;
            }
            cout << "Are you sure you want to let your dragon go? You will be defenseless. Yes or No?" << endl;
            bool dCheck = false;
            while(!check){
                string freedom;
                getline(cin,freedom);
                if (toUpper(freedom) == "YES"){
                    cout << user.getCurDragon() << " has been set free!" << endl;
                    user.setCurDragon("");
                    check = true;
                }
                if (toUpper(freedom) == "NO"){
                    check = true;
                }
            }
        }
        else{
            cout << "Invalid option." << endl;
        }
    }

}
void Game::printDragon(string dragon_){
    int dIndex;
    if (user.getCurDragon() == ""){
        cout << "You do not currently have a dragon!" << endl << endl;
    }
    for (int i = 0; i < 20; i++){
        if (dragon_ == dragons[i].getDName()){
            dIndex = i;
        }
    }
    cout << "----" << dragons[dIndex].getDName() << " (" << dragons[dIndex].getDType() << ")" << "----" << endl;
    cout << "Attack: " << dragons[dIndex].getDAttack() << endl;
    cout << "Health: " << dragons[dIndex].getDHealth() << endl;
    cout << "Speed: " << dragons[dIndex].getDSpeed() << endl;
    cout << dragons[dIndex].getDDescription() << endl;         
}
string Game::hatchEgg(){
    int randNum = randomNumbers(0, 100);
    if(randNum == 100) {
        //GET ULTIMITE (0)
        return "Ultimite";
    }
    else if(randNum < 100 && randNum >= 90) {
        //GET EPIC (1-3)
        int subRand = randomNumbers(1,3);
        return dragons[subRand].getDName();
    }
    else if(randNum < 90 && randNum >= 55) {
        //GET RARE (4-11)
        int subRand = randomNumbers(4,11);
        return dragons[subRand].getDName();
    }
    else if(randNum < 55 && randNum >= 1) {
        //GET COMMON (12-19)
        int subRand = randomNumbers(12,19);
        return dragons[subRand].getDName();
    }
    else if(randNum == 0){
        return "It's just a yolk! Looks like you got a rotten egg!";
    }

    return "You have no egg to hatch!";
}
void Game::randomDragon(){
    if (map.getTile(map.getPlayerX(), map.getPlayerY()) == "▓"){
        int randNum = randomNumbers(1,13);
        int randRarity = randomNumbers(1,100);
        int subRand;
        if (randNum == 1){
            if(randRarity == 100) {
                //GET ULTIMITE (0)
                subRand = 0;
            }
            if(randRarity < 100 && randRarity >= 90){
                //GET EPIC (1-3)
                subRand = randomNumbers(1,3);
            }
            if(randRarity < 90 && randRarity >= 55) {
                //GET RARE (4-11)
                subRand = randomNumbers(4,11);
            }
            if(randRarity < 55 && randRarity >= 1) {
                //GET RARE (12-19)
                subRand = randomNumbers(12,19);
            }

            if(user.getCurDragon() == dragons[subRand].getDName())
                return;
                
            cout << "You have run into a wild Dragon! What would you like to do?" << endl;
            cout << endl;
            printDragon(dragons[subRand].getDName());
            cout << endl;
            if (user.getCurDragon() != "")
                printDragon(user.getCurDragon());
            cout << endl;
            int battleOp;
            bool fightCheck = false;
            while(!fightCheck) {
                cout << "1. Fight" << endl << "2. Run" << endl << "3. Capture" << endl;
                if(user.getCurDragon() == "")
                    cout << "CAREFUL! You don't have a dragon. Run while you still can!" << endl;
                cin >> battleOp;
                switch (battleOp){
                    case 1:
                        cout << endl;
                        cout << dragons[subRand].getDName() << " VS. " << user.getCurDragon() << endl;
                        cout << endl;
                        fightCheck = dragonFight(dragons[subRand].getDName());
                        if (fightCheck == true){
                            return;
                        }
                        break;
                    case 2:
                        cout << "You got away safely!" << endl;
                        return;

                    case 3:
                        if (user.getStone() == true){ //if you have the stone
                            user.setStone(false); //this changes from having the stone
                            if (dragons[subRand].getDName() == "Ultimite"){ //if the dragon you are facing is ultimite
                                int randCap = randomNumbers(1,3); //1 in 3 chance of catching ultimite
                                if (randCap == 1) { //if the random number is 1, you catch ultimite 
                                    cout << "You have captured Ultimite! You are the most legendary draogn rider in the world!" << endl;
                                    user.setCurDragon("Ultimite"); //sets your current dragon to Ultimite
                                    return;
                                }
                                else{ //if it is not 1
                                    cout << "Ultimite is too strong to capture! He got away!" << endl;
                                    return;
                                }
                            }
                            else { //if you capture the dragon
                                cout << dragons[subRand].getDName() << " has been captured! Would you like to keep " << dragons[subRand].getDName() << " or release it back into the wild?" << endl;
                                cout << "1. Keep" << endl << "2. Release" << endl;
                                int keep = 0;
                                bool keepCheck = false;
                                while(!keepCheck) {
                                    cin >> keep;

                                    if(keep == 1) {
                                        user.setCurDragon(dragons[subRand].getDName());
                                        cout << dragons[subRand].getDName() << " is now your companion!" << endl;
                                        keepCheck = true;
                                        return;
                                    }

                                    else if(keep == 2) {
                                        cout << dragons[subRand].getDName() << " has been released. Maybe you will see him in the wild someday!" << endl;
                                        keepCheck = true;
                                        return;
                                    }

                                    else
                                        cout << "Invalid option." << endl;
                                }
                            }
                        }
                        else { //if you dont have iros stone
                            cout << "You do not have Iro's Stone to capture a dragon!" << endl;
                            break;
                        }
                    
                    default: //if not 1,2,3 for fight
                        cout << "Invalid input." << endl;
                        break;
                }
            }
        }
    }
}
bool Game::dragonFight(string dragon_){
    int userI, cpuI, userAttackRand, CPUAttackRand, CPUChanceAttackRand, blockChance;
    for (int i = 0; i < 20; i++){
        if (dragons[i].getDName() == dragon_)
            cpuI = i;
        if (dragons[i].getDName() == user.getCurDragon())
            userI = i;
    }

    if (user.getCurDragon() == ""){
        cout << "You don't have a dragon to fight! " << dragons[cpuI].getDName() << " has spared your life, but he plundered your inventory!" << endl << endl;
        for (int i = 0; i < 12; i++){
            user.setInventoryAt("EMPTY", i);
        }
        user.setCloud(false);
        user.setMap(false);
        user.setEgg(false);
        user.setStone(false);
        return true;
    }
    
    if (dragons[userI].getDSpeed() > dragons[cpuI].getDSpeed()){ //user atatcks first
        cout << dragons[userI].getDName() << " attacks first!" << endl << endl;
        userAttackRand = randomNumbers(1,dragons[userI].getDAttack());
        blockChance = randomNumbers(1,4);
        if (blockChance == 1) {
            cout << dragons[userI].getDName() << "'s attack missed!" << endl << endl;
        }
        else{
            cout << dragons[userI].getDName() << " has dealt " << userAttackRand << " damage!" << endl << endl;
            dragons[cpuI].setDHealth(dragons[cpuI].getDHealth() - userAttackRand);
        }

        CPUChanceAttackRand = randomNumbers(1,4);
        CPUAttackRand = randomNumbers(1,dragons[cpuI].getDAttack());
        if(CPUChanceAttackRand == 1 || CPUChanceAttackRand == 2 || CPUChanceAttackRand == 3) {
            cout << dragons[cpuI].getDName() << " attacked! It dealt " << CPUAttackRand << " damage!" << endl << endl;
            dragons[userI].setDHealth(dragons[userI].getDHealth() - CPUAttackRand);
        }

        else {
            cout << dragons[cpuI].getDName() << "'s attack missed!" << endl << endl;
        }
        
        if (dragons[userI].getDHealth() <= 0){
            dragons[userI].setDHealth(0);
            cout <<  endl << "Your dragon has perished and " << dragons[cpuI].getDName() << " has spared your life, but it plundered your inventory!" << endl << endl;
            for (int i = 0; i < 12; i++){
                user.setInventoryAt("EMPTY", i);
            }
            user.setCloud(false);
            user.setMap(false);
            user.setEgg(false);
            user.setStone(false);
            dragons[userI].setDHealth(dragons[userI].getDMaxHealth());
            user.setCurDragon("");
            return true;
        }
        
        if(dragons[cpuI].getDHealth() <= 0) {
            dragons[cpuI].setDHealth(0);
            cout << "You have slain " << dragons[cpuI].getDName() << "! Gather the dragon remains and bring them to SHOP to get your reward!" << endl << endl;
            dragons[cpuI].setDHealth(dragons[cpuI].getDMaxHealth());
            user.setInventory("Saphire Gem");
            user.setInventory("Dragon Horn");
            user.setInventory("Dragon Claws");
            int randEgg = randomNumbers(1,4);
            if (randEgg == 1){
                cout << "It was preganant! Claim your egg and bring it to the Incubation Station!" << endl << endl;
                user.setEgg(true);
            }
            return true;
        }
    }
    else if (dragons[userI].getDSpeed() < dragons[cpuI].getDSpeed()){
        cout << dragons[cpuI].getDName() << " attacks first!" << endl << endl;
        CPUChanceAttackRand = randomNumbers(1,4);
        CPUAttackRand = randomNumbers(1,dragons[cpuI].getDAttack());
        if(CPUChanceAttackRand == 1 || CPUChanceAttackRand == 2 || CPUChanceAttackRand == 3) {
            cout << dragons[cpuI].getDName() << " attacked! It dealt " << CPUAttackRand << " damage!" << endl << endl;
            dragons[userI].setDHealth(dragons[userI].getDHealth() - CPUAttackRand);
        }

        else {
            cout << dragons[cpuI].getDName() << "'s attack missed!" << endl << endl;
        }

        userAttackRand = randomNumbers(1,dragons[userI].getDAttack());
        blockChance = randomNumbers(1,4);
        if (blockChance == 1) {
            cout << dragons[userI].getDName() << "'s attack missed!" << endl << endl;
        }
        else{
            cout << dragons[userI].getDName() << " has dealt " << userAttackRand << " damage!" << endl << endl;
            dragons[cpuI].setDHealth(dragons[cpuI].getDHealth() - userAttackRand);
        }

        if (dragons[userI].getDHealth() <= 0){
            dragons[userI].setDHealth(0);
            cout << "Your dragon has perished and " << dragons[cpuI].getDName() << " has spared your life, but it plundered your inventory!" << endl << endl;
            for (int i = 0; i < 12; i++){
                user.setInventoryAt("EMPTY", i);
            }
            user.setCloud(false);
            user.setMap(false);
            user.setEgg(false);
            user.setStone(false);
            dragons[userI].setDHealth(dragons[userI].getDMaxHealth());
            user.setCurDragon("");
            return true;
        }
        
        if(dragons[cpuI].getDHealth() <= 0) {
            dragons[cpuI].setDHealth(0);
            cout << "You have slain " << dragons[cpuI].getDName() << "! Gather the dragon remains and bring them to SHOP to get your reward!" << endl << endl;
            dragons[cpuI].setDHealth(dragons[cpuI].getDMaxHealth());
            user.setInventory("Saphire Gem");
            user.setInventory("Dragon Horn");
            user.setInventory("Dragon Claws");
            int randEgg = randomNumbers(1,7);
            if (randEgg == 1){
                cout << "It was preganant! Claim your egg and bring it to the Incubation Station!" << endl << endl;
                user.setEgg(true);
            }
            return true;
        }
    }

    else if(dragons[userI].getDSpeed() == dragons[cpuI].getDSpeed()) {
        int randomAttack = randomNumbers(1,2);

        if(randomAttack == 1) {
            cout << dragons[userI].getDName() << " attacks first!" << endl << endl;
            userAttackRand = randomNumbers(1,dragons[userI].getDAttack());
            blockChance = randomNumbers(1,4);
            if (blockChance == 1) {
                cout << dragons[userI].getDName() << "'s attack missed!" << endl << endl;
            }
            else{
                cout << dragons[userI].getDName() << " has dealt " << userAttackRand << " damage!" << endl << endl;
                dragons[cpuI].setDHealth(dragons[cpuI].getDHealth() - userAttackRand);
            }

            CPUChanceAttackRand = randomNumbers(1,4);
            CPUAttackRand = randomNumbers(1,dragons[cpuI].getDAttack());
            if(CPUChanceAttackRand == 1 || CPUChanceAttackRand == 2 || CPUChanceAttackRand == 3) {
                cout << dragons[cpuI].getDName() << " attacked! It dealt " << CPUAttackRand << " damage!" << endl << endl;
                dragons[userI].setDHealth(dragons[userI].getDHealth() - CPUAttackRand);
            }

            else {
                cout << dragons[cpuI].getDName() << "'s attack missed!" << endl << endl;
            }
            
            if (dragons[userI].getDHealth() <= 0){
                dragons[userI].setDHealth(0);
                cout <<  endl << "Your dragon has perished and " << dragons[cpuI].getDName() << " has spared your life, but it plundered your inventory!" << endl << endl;
                for (int i = 0; i < 12; i++){
                    user.setInventoryAt("EMPTY", i);
                }
                user.setCloud(false);
                user.setMap(false);
                user.setEgg(false);
                user.setStone(false);
                dragons[userI].setDHealth(dragons[userI].getDMaxHealth());
                user.setCurDragon("");
                return true;
            }
            
            if(dragons[cpuI].getDHealth() <= 0) {
                dragons[cpuI].setDHealth(0);
                cout << "You have slain " << dragons[cpuI].getDName() << "! Gather the dragon remains and bring them to SHOP to get your reward!" << endl << endl;
                dragons[cpuI].setDHealth(dragons[cpuI].getDMaxHealth());
                user.setInventory("Saphire Gem");
                user.setInventory("Dragon Horn");
                user.setInventory("Dragon Claws");
                int randEgg = randomNumbers(1,4);
                if (randEgg == 1){
                    cout << "It was preganant! Claim your egg and bring it to the Incubation Station!" << endl << endl;
                    user.setEgg(true);
                }
                return true;
            }
        }

        else {
            cout << dragons[cpuI].getDName() << " attacks first!" << endl << endl;
            CPUChanceAttackRand = randomNumbers(1,4);
            CPUAttackRand = randomNumbers(1,dragons[cpuI].getDAttack());
            if(CPUChanceAttackRand == 1 || CPUChanceAttackRand == 2 || CPUChanceAttackRand == 3) {
                cout << dragons[cpuI].getDName() << " attacked! It dealt " << CPUAttackRand << " damage!" << endl << endl;
                dragons[userI].setDHealth(dragons[userI].getDHealth() - CPUAttackRand);
            }

            else {
                cout << dragons[cpuI].getDName() << "'s attack missed!" << endl << endl;
            }

            userAttackRand = randomNumbers(1,dragons[userI].getDAttack());
            blockChance = randomNumbers(1,4);
            if (blockChance == 1) {
                cout << dragons[userI].getDName() << "'s attack missed!" << endl << endl;
            }
            else{
                cout << dragons[userI].getDName() << " has dealt " << userAttackRand << " damage!" << endl << endl;
                dragons[cpuI].setDHealth(dragons[cpuI].getDHealth() - userAttackRand);
            }

            if (dragons[userI].getDHealth() <= 0){
                dragons[userI].setDHealth(0);
                cout << "Your dragon has perished and " << dragons[cpuI].getDName() << " has spared your life, but it plundered your inventory!" << endl << endl;
                for (int i = 0; i < 12; i++){
                    user.setInventoryAt("EMPTY", i);
                }
                user.setCloud(false);
                user.setMap(false);
                user.setEgg(false);
                user.setStone(false);
                dragons[userI].setDHealth(dragons[userI].getDMaxHealth());
                user.setCurDragon("");
                return true;
            }
            
            if(dragons[cpuI].getDHealth() <= 0) {
                dragons[cpuI].setDHealth(0);
                cout << "You have slain " << dragons[cpuI].getDName() << "! Gather the dragon remains and bring them to SHOP to get your reward!" << endl << endl;
                dragons[cpuI].setDHealth(dragons[cpuI].getDMaxHealth());
                user.setInventory("Saphire Gem");
                user.setInventory("Dragon Horn");
                user.setInventory("Dragon Claws");
                int randEgg = randomNumbers(1,7);
                if (randEgg == 1){
                    cout << "It was preganant! Claim your egg and bring it to the Incubation Station!" << endl << endl;
                    user.setEgg(true);
                }
                return true;
            }
        }
        
    }

    printDragon(user.getCurDragon());
    cout << endl << endl;
    printDragon(dragon_);
    cout << endl;
    return false;
}

//Map Functions
void Game::printWholeMap(){
    for (int i = 0; i < 40; i++){
            for (int j = 0; j < 50; j++){
                if (map.getPlayerX() == i && map.getPlayerY() == j)
                    cout << "☆";
                else
                    cout << map.getTile(i,j);
            }
            cout << endl;
        }
}
void Game::printMap(){ //need to add edge cases
    cout << map.getPlayerX() << ", " << map.getPlayerY() << endl;
    if (user.getMap() == true) //if you have map item
    {
        int x = map.getPlayerX() - 7;
        int y = map.getPlayerY() - 7;
        for (int i = x; i < x + 15; i++){
            for (int j = y; j < y + 15; j++){
                if (i > 39 || j > 49) //edge case
                    cout << "- ";
                if (i < 0 || j < 0) //edge case
                    cout << "- ";
                else if (map.getPlayerX() == i && map.getPlayerY() == j)
                    cout << "☆" << " ";
                else
                    cout << map.getTile(i,j) << " ";
            }
            cout << endl;
        }
    }
    else if (user.getMap() == false) //if you dont have map
    {
        int x = map.getPlayerX() - 3;
        int y = map.getPlayerY() - 3;
        for (int i = x; i < x + 7; i++){
            for (int j = y; j < y + 7; j++){
                if (i > 39 || j > 49 ) //edge case
                    cout << "- ";
                if (i < 0 || j < 0) //edge case
                    cout << "- ";
                else if (map.getPlayerX() == i && map.getPlayerY() == j)
                    cout << "☆" << " ";
                else
                    cout << map.getTile(i,j) << " ";
            }
            cout << endl;
        }
    }
}
void Game::travel() {
    int travel;
    bool check = false;
    cout << "Where would you like to go?" << endl;
    cout << "1. North" << endl << "2. South" << endl << "3. East" << endl << "4. West" << endl;
    cin >> travel;
    if(travel == 1253) { //cheats
        user.setStone(true);
        user.setEgg(true);
        user.setCloud(true);
        user.setMap(true);
        user.addCoins(99999);
    }
    if(travel == 6274) { //remove cheats
        user.setStone(false);
        user.setEgg(false);
        user.setCloud(false);
        user.setMap(false);
    }
    switch (travel){
        case 1:
            if (map.getTile(map.getPlayerX() - 1, map.getPlayerY()) == "w"){
                map.setPlayerLoc(map.getPlayerX(), map.getPlayerY());
                cout << endl << "There is water in your way! Choose another direction." << endl << endl;
                break;
            }
            else {
                map.setPlayerLoc(map.getPlayerX() - 1, map.getPlayerY());
                break;
            }
        case 2:
            if (map.getTile(map.getPlayerX() + 1, map.getPlayerY()) == "w"){
                map.setPlayerLoc(map.getPlayerX(), map.getPlayerY());
                cout << endl << "There is water in your way! Choose another direction." << endl << endl;
                break;
            }
            else {
                map.setPlayerLoc(map.getPlayerX() + 1, map.getPlayerY());
                break;
            }
        case 3:
            if (map.getTile(map.getPlayerX(), map.getPlayerY() + 1) == "w"){
                map.setPlayerLoc(map.getPlayerX(), map.getPlayerY());
                cout << endl << "There is water in your way! Choose another direction." << endl << endl;
                break;
            }
            else {
                map.setPlayerLoc(map.getPlayerX(), map.getPlayerY() + 1);
                break;
            }
        case 4:
            if (map.getTile(map.getPlayerX(), map.getPlayerY() - 1) == "w"){
                map.setPlayerLoc(map.getPlayerX(), map.getPlayerY());
                cout << endl << "There is water in your way! Choose another direction." << endl << endl;
                break;
            }

            else {
                map.setPlayerLoc(map.getPlayerX(), map.getPlayerY() - 1);
                break;
            }
        default:
            cout << "Invalid option." << endl;
            break;
    }
}
void Game::checkTile(){
    //incubation station
    if(map.getTile(map.getPlayerX(),map.getPlayerY()) == "I") {
        int incubateChoice;
        bool check = false;

        cout << endl << "Welcome to the Incubation Station!" << endl << "We are here to help with all your dragons needs! Would would you like to do?" << endl;

        while(!check) {
            cout << "1. Hatch dragon egg" << endl << "2. View all dragons" <<  endl << "3. Heal dragons" << endl << "4. Leave Incubation Station" << endl;
            if (user.getCloud() == true && user.getCurDragon() == "Weedleshnee")
                cout << "5. Discover a secret" << endl;
            cin >> incubateChoice;

            if(incubateChoice == 1) { //hatch egg
                if(user.getEgg() == true) { //if the user does have an egg in their inventory
                    string hatchedDragon = hatchEgg();
                    if (hatchedDragon == "It's just a yolk! Looks like you got a rotten egg!" || hatchedDragon == user.getCurDragon()) {
                        cout << "It's just a yolk! Looks like you got a rotten egg!" << endl;
                        return;
                    }
                    string keepDrag = "";
                    cout << endl << "Congratulations! You hatched " << hatchedDragon << "!" << endl << endl;

                    printDragon(hatchedDragon);
                    cout << endl;
                    if(user.getCurDragon() != "") {
                        printDragon(user.getCurDragon());
                        
                    }

                    bool edgeChoice = false;
                    while(!edgeChoice) {
                        if(user.getCurDragon() == "") {
                            cout << hatchedDragon << " is now your companion." << endl << endl;
                            user.setCurDragon(hatchedDragon);
                            user.setEgg(false);
                            edgeChoice = true;
                        }

                        else {
                            cout << endl << "Would you like to replace " << user.getCurDragon() << " with " << hatchedDragon << "? Yes or No?" << endl;
                            cin >> keepDrag;
                            keepDrag = toUpper(keepDrag);

                            if(keepDrag == "YES") {
                                user.setCurDragon(hatchedDragon);
                                user.setEgg(false);
                                cout << hatchedDragon << " is now your companion." << endl;
                                edgeChoice = true;
                            }

                            else if(keepDrag == "NO") {
                                user.setEgg(false);
                                cout << "That's too bad. Maybe you will see " << hatchedDragon << " out in the wild someday!" << endl;
                                edgeChoice = true;
                            }
                        }
                    }
                }

                else if(user.getEgg() == false) { //if the user does not have an egg in their inventory
                    cout << "You don't have an egg to hatch! Please come back once you have obtained one." << endl;
                }
            }

            else if(incubateChoice == 2) {
                cout << "Which dragons would you like to see?" << endl << "1. Common" << endl << "2. Rare" << endl << "3. Epic" << endl << "4. Legendary" << endl;
                int viewDragChoice;
                cin >> viewDragChoice;

                bool edgeViewDragCheck = false;
                while(!edgeViewDragCheck) {
                    if(viewDragChoice == 1) { 
                        viewDragons("COMMON");
                        edgeViewDragCheck = true;
                    }
                    else if(viewDragChoice == 2) {
                        viewDragons("RARE");
                        edgeViewDragCheck = true;
                    }
                    else if(viewDragChoice == 3) {
                        viewDragons("EPIC");
                        edgeViewDragCheck = true;
                    }
                    else if(viewDragChoice == 4) {
                        viewDragons("LEGENDARY");
                        edgeViewDragCheck = true;
                    }
                    else
                        cout << "Please choose from one of the options. (1-4)" << endl;
                }
            }

            else if(incubateChoice == 3) { //heal
                int dragFullHealth;
                int dragonIndex;
                if (user.getCurDragon() == ""){
                    cout << "You have no dragon to heal!" << endl;
                    return;
                }
                for(int i = 0; i < 20; i++) {
                    if(dragons[i].getDName() == user.getCurDragon()){
                        dragFullHealth = dragons[i].getDMaxHealth();
                        dragonIndex = i;
                    }
                }
                
                int dragHealthMissing = dragFullHealth - dragons[dragonIndex].getDHealth();
                bool healFinish = false;
                while(!healFinish) {
                    cout << "It looks like " << user.getCurDragon() << " is " << dragHealthMissing << " HP from full health. Would you like to spend 30 coins to heal it to full? (Yes/No)" << endl;
                    cout << "Coins: " << user.getCoins() << endl;
                    bool healChoice = false;
                    string option = "";

                    while(!healChoice) {
                        getline(cin, option);
                        toUpper(option);

                        if(toUpper(option) == "YES") {
                            if (dragHealthMissing == 0){
                                cout << "Your dragon is already fully healed!" << endl << endl;
                                healChoice = true;
                                healFinish = true;
                            }
                            else {
                                if(user.getCoins() < 30) {
                                    cout << "You don't have enough coins to heal your dragon! Stop by the SHOP to sell some items." << endl;
                                    healChoice = true;
                                    healFinish = true;
                                }
                                else {
                                    dragons[dragonIndex].setDHealth(dragFullHealth);
                                    cout << "Your dragon has been healed to full health." << endl;
                                    user.removeCoins(30);
                                    healChoice = true;
                                    healFinish = true;
                                }
                            }
                        }

                        else if(toUpper(option) == "NO") {
                            cout << "Okay! Come back when you want to heal your dragon." << endl;
                            healChoice = true;
                            healFinish = true;
                        }
                    }
                }
            }

            else if(incubateChoice == 4) {
                cout << "Come back soon!" << endl;
                check = true;
            }

            else if (incubateChoice == 5){
                if (user.getCloud() == true && user.getCurDragon() == "Weedleshnee"){
                    cout << "Would you like to infuse your Dark Cloud with your Weedleshnee dragon to begin evolution? Yes or No?" << endl;
                    bool evolCheck = false;
                    string evolChoice;
                    while(!evolCheck) {
                        getline(cin, evolChoice);
                        if(toUpper(evolChoice) == "YES"){
                            cout << endl << endl << "THE EVOLUTION HAS BEGUN!" << endl << endl;
                            long timer;
                            while(timer != 1){
                                timer = randomNumbers(1,1000000000); //just a timer to add a super overly dramatic delay
                            }
                            cout << "Congratulations! Your Weedleshnee has evolved into ULTIMITE, the most powerful dragon in the Central Dragonium!" << endl << endl;
                            user.setCurDragon("Ultimite");
                            user.setCloud(false);
                            evolCheck = true;
                            
                        }
                        else if(toUpper(evolChoice) == "NO") {
                            evolCheck = true;
                        }
                    }
                }
                else{
                    cout << "Invalid option." << endl;
                }
            }
            else
                cout << "Invalid option." << endl;
        }
    }

    if(map.getTile(map.getPlayerX(),map.getPlayerY()) == "S") {
        cout << endl << "Welcome to the Shop!" << endl;
        cout << "We have many traders here ready to buy your treasure from your adventures or sell you all your dragon needs!" << endl;
        int merchant;
        bool shopCheck = false;
        while(!shopCheck){
            cout << "Coins: " << user.getCoins() << endl;
            cout << "1. Sell" << endl << "2. Buy" << endl << "3. Return to journey" << endl;
            cin >> merchant;
            if (merchant == 1){ //sell
                bool sellCheck = false;
                while(!sellCheck){ //fake poop loop
                    cout << "What would you would like to sell? (Enter 13 to leave merchant)" << endl;
                    cout << "Coins: " << user.getCoins() << endl;
                    int count = 0;
                    for (int i = 0; i < 12; i++){
                        cout << i + 1 << ". " << user.getInventory(i) << ": " << getPriceByName(user.getInventory(i)) << endl;
                        if (user.getInventory(i) != "EMPTY"){
                            count++;
                        }
                    }

                    int sell = 0;
                    if (count == 0){
                        cout << endl << "You have nothing to sell!" << endl;
                        sellCheck = true;
                    }

                    else {
                        cin >> sell;
                        if (sell == 13){
                            sellCheck = true;
                            break;
                        }
                        else if (sell >= 1 && sell <= 12){
                            if (user.getInventory(sell - 1) == "EMPTY"){
                                cout << "There is no item in this slot to sell." << endl;
                            }
                            user.addCoins(getPriceByName(user.getInventory(sell - 1)));
                            user.setInventoryAt("EMPTY", sell - 1);
                        }
                        else
                        {
                            cout << "Invalid option." << endl;
                        }
                    }
                }
            }
            else if (merchant == 2){//buy
                cout << "What would you like to buy? (Enter 13 to return to main menu)" << endl;
                int buyChoice;
                bool poopCheck = false;
                while(!poopCheck) { //the real poop loop
                    cout << "Coins: " << user.getCoins() << endl;
                    cout << "1. Dragon Egg: 300" << endl << "2. Map: 200" << endl << "3. Iro's Stone: 800" << endl;
                    cin >> buyChoice;

                    if(buyChoice == 1) {
                        if (user.getEgg() == true){
                            cout << "You already have a Dragon Egg!" << endl;
                            poopCheck = true;
                        }
                        else{
                            if (user.getCoins() >= 300){
                                cout << "You have aqcuired a Dragon Egg!" << endl;
                                user.setEgg(true);
                                user.removeCoins(300);
                                poopCheck = true;
                            }
                            else{
                                cout << "You do not have enough coins to purchase a Dragon Egg!" << endl;
                                poopCheck = true;
                            }
                        }
                    }

                    else if(buyChoice == 2) {
                        if (user.getMap() == true){
                            cout << "You already have a Dragon Egg!" << endl;
                            poopCheck = true;
                        }

                        else {
                            if(user.getCoins() >= 200){
                                cout << "You have aqcuired a Map!" << endl;
                                user.setMap(true);
                                user.removeCoins(200);
                                poopCheck = true;
                            }
                            
                            else {
                                cout << "You do not have enough coins to purchase a Map!" << endl;
                                poopCheck = true;
                            }
                        }
                    }

                    else if(buyChoice == 3) {
                        if (user.getStone() == true){
                            cout << "You already have a Iro's Stone!" << endl;
                            poopCheck = true;
                        }
                        else{
                            if (user.getCoins() >= 800){
                                cout << "You have aqcuired a Iro's Stone!" << endl;
                                user.setStone(true);
                                user.removeCoins(800);
                                poopCheck = true;
                            }
                            else{
                                cout << "You do not have enough coins to purchase a Iro's Stone!" << endl;
                                poopCheck = true;
                            }
                        }
                    }

                    else if(buyChoice == 13) {
                        poopCheck = true;
                    }
                }
            }
            else if (merchant == 3){//quit
                shopCheck = true;
            }
            else{
                cout << "Invalid option." << endl;
            }
        }
    }
}

//Item Functions
void Game::giveItems(){
    if (map.getTile(map.getPlayerX(),map.getPlayerY()) == "▓")
    {
        int randNum = randomNumbers(1,12); //odds of picking up an item
        if (randNum == 1){
            int randRarity = randomNumbers(0,100); //random number to decide which rarity item you will find if the previous random number == 1
            {
                if (randRarity == 100) //dark cloud
                {
                    cout << "You have found " << items[0].getIName() << " (" << items[0].getIRarity() << ")" << endl;
                    cout << items[0].getIDescription() << endl;
                    if (user.getInventorySize() == 12){
                        cout << endl << "Your inventory is full! You cannot carry this item." << endl;
                        return;
                    }
                    cout << "Would you like to add " << items[0].getIName() << "? Yes or No?" << endl;
                    string itemOp = "";
                    bool check = true;
                    while(check == true){
                        getline(cin, itemOp);
                        if(toUpper(itemOp) == "YES"){
                            cout << items[0].getIName() << " has been added to your inventory!" << endl;
                            user.setEgg(true);
                            check = false;
                            return;
                        }
                        else if(toUpper(itemOp) == "NO"){
                            cout << items[0].getIName() << " has been left on the ground" << endl;
                            check = false;
                            return;
                        }
                    }
                }
                if (randRarity >= 85 && randRarity < 100) //epic
                {
                    //Epic
                    int randItem = randomNumbers(1,3);
                    cout << "You have found " << items[randItem].getIName() << " (" << items[randItem].getIRarity() << ")" << endl;
                    cout << items[randItem].getIDescription() << endl;
                    if (user.getInventorySize() == 12){
                        cout << endl << "Your inventory is full! You cannot carry this item." << endl;
                        return;
                    }
                    cout << "Would you like to add " << items[randItem].getIName() << "? Yes or No?" << endl;
                    string itemOp = "";
                    bool check = true;
                    while(check == true){
                        getline(cin, itemOp);
                        if(toUpper(itemOp) == "YES"){
                            cout << items[randItem].getIName() << " has been added to your inventory!" << endl;
                            if (items[randItem].getIName() == "Iro's Stone")
                                user.setStone(true);
                            else if (items[randItem].getIName() == "Dragon Egg")
                                user.setEgg(true);
                            else
                                user.setInventory(items[randItem].getIName());
                            check = false;
                            return;
                        }
                        else if(toUpper(itemOp) == "NO"){
                            cout << items[randItem].getIName() << " has been left on the ground" << endl;
                            check = false;
                            return;
                        }
                    }
                }
                if (randRarity >= 50 && randRarity < 85) //rare
                {
                    //Rare
                    int randItem = randomNumbers(4,12);
                    cout << "You have found " << items[randItem].getIName() << " (" << items[randItem].getIRarity() << ")" << endl;
                    cout << items[randItem].getIDescription() << endl;
                    if (user.getInventorySize() == 12) {
                        cout << endl << "Your inventory is full! You cannot carry this item." << endl;
                        return;
                    }
                    cout << "Would you like to add " << items[randItem].getIName() << "? Yes or No?" << endl;
                    string itemOp = "";
                    bool check = true;
                    while(check == true){
                        getline(cin, itemOp);
                        if(toUpper(itemOp) == "YES"){
                            cout << items[randItem].getIName() << " has been added to your inventory!" << endl;
                            if (items[randItem].getIName() == "Map")
                                user.setMap(true);
                            else
                                user.setInventory(items[randItem].getIName());
                            check = false;
                            return;
                        }
                        else if(toUpper(itemOp) == "NO"){
                            cout << items[randItem].getIName() << " has been left on the ground" << endl;
                            check = false;
                            return;
                        }
                    }
                }
                if (randRarity >= 0 && randRarity < 50) //comon
                {
                    //Common
                    int randItem = randomNumbers(12,19);
                    cout << "You have found " << items[randItem].getIName() << " (" << items[randItem].getIRarity() << ")" << endl;
                    cout << items[randItem].getIDescription() << endl;
                    if (user.getInventorySize() == 12){
                        cout << endl << "Your inventory is full! You cannot carry this item." << endl;
                        return;
                    }
                    cout << "Would you like to add " << items[randItem].getIName() << "? Yes or No?" << endl;
                    bool check = false;
                    while(!check){
                        string itemOp = "";
                        getline(cin, itemOp);
                        if(toUpper(itemOp) == "YES"){
                            cout << items[randItem].getIName() << " has been added to your inventory!" << endl;
                            user.setInventory(items[randItem].getIName());
                            check = true;
                            return;
                        }
                        else if(toUpper(itemOp) == "NO"){
                            cout << items[randItem].getIName() << " has been left on the ground" << endl;
                            check = true;
                            return;
                        }
                    }
                }
            }
        }
    }
}
void Game::printItems(string item_){
    if (item_ == "")
    {
        return;
    }
    for (int i = 0; i < 20; i++)
    {
        if (item_ == items[i].getIName())
        {
            cout << "----" << items[i].getIName() << "----" << endl;
            cout << "Rarity: " << items[i].getIRarity() << endl;
            cout << items[i].getIDescription() << endl;
        }
    }
}
int Game::getPriceByName(string str){
    if (str == "EMPTY"){
        return 0;
    }
    for (int i = 0; i < 20; i++){
        if (items[i].getIName() == str)
            return items[i].getIPrice();
    }
    return -1;
}

//User Functions
void Game::viewInventory(){
    bool check = false;
    while(!check){
        cout << "----Inventory----" << endl;
        cout << "Coins: " << user.getCoins() << endl;
        for (int i = 0; i < 12; i++){
            cout << i + 1 << ". " << user.getInventory(i) << endl;
        }

        if (user.getMap() == true)
            cout << "Map acquired" << endl;
        if (user.getCloud() == true)
            cout << "Dark Cloud acquired" << endl;
        if (user.getEgg() == true)
            cout << "Dragon Egg acquired" << endl;
        if (user.getStone() == true)
            cout << "Iro's Stone acquired" << endl;
        int drop;
        cout << "Would you like to drop any item? (Enter 13 to leave inventory)" << endl;
        cin >> drop;
        if (drop == 13){
            check = true;
            return;
        }
        else if (drop >= 1 && drop <= 12){
            if (user.getInventory(drop - 1) == "EMPTY"){
                cout << "There is no Item in this inventory slot!" << endl;
            }
            else{
                cout << user.getInventory(drop) << " has been dropped." << endl;
                user.setInventoryAt("EMPTY", drop - 1);
            }
        }
        else{
            cout << "Invalid input." << endl;
        }
    }  
}
void Game::setUsername(string username_){
    user.setUsername(username_);
}
string Game::getUsername(){
    return user.getUsername();
}

//Other Functions
void Game::endGame(){
    cout << endl <<  "----Stats----" << endl;
    cout << endl << user.getUsername() << endl;
    cout << endl << "Your Dragon: " << endl;
    int dIndex;
    for (int i = 0; i < 20; i++){
        if (user.getCurDragon() == dragons[i].getDName()){
            cout << dragons[i].getDName() << " (" << dragons[i].getDType() << ")" << endl;
            cout << "Attack: " << dragons[i].getDAttack() << endl;
            cout << "Health: " << dragons[i].getDHealth() << endl;
            cout << "Speed: " << dragons[i].getDSpeed() << endl;
            cout << "Rarity: " << dragons[i].getDRarity() << endl;
            cout << dragons[i].getDDescription() << endl;
            dIndex = i;
        }
    }
    cout << endl << "Total coins: " << user.getCoins() << endl << endl;
    cout << "-------------" << endl;
    cout << endl;

    //add to leaderboards
    ofstream myFile;
    string line;
    myFile.open("Leaderboards.txt", fstream::app);
    myFile << user.getUsername() << ",Coins: " << user.getCoins() << ",Dragon: " << user.getCurDragon() << "(" << dragons[dIndex].getDRarity() << ")";
    if (dragons[dIndex].getDRarity() == "Epic")
        myFile << " Legendary Rider";
    if (dragons[dIndex].getDRarity() == "Legendary")
        myFile << " Ultimite's Rider";
    myFile << endl;
    myFile.close();

    //print leadboards
    cout << endl <<  "----Leaderboard----" << endl <<  endl;
    line = "";
    string arr[3];
    ifstream myFile_;
    myFile_.open("Leaderboards.txt");
    if (myFile_.is_open()){
        while(getline(myFile_, line)){
            split(line, ',', arr, 3);
            cout << arr[0] << endl << arr[1] << endl << arr[2] << endl;
            cout << endl;
        }
    }
    cout << "-------------------" << endl;
    cout << endl;
    cout << "Thank you for playing!" << endl;
}