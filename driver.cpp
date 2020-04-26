// CSCI 1300 Spring 2020
// Author: Colin Shober and Lucca Chiappetta
// Recitation: 204 - Thanika Reddy (Colin)
// Recitation: 203 - Soumyajyoti Bhattacharya (Lucca)
// Project 3 - driver.cpp

#include "Game.h"
#include <string>

string toUpper_(string str) //function decleration
{
    string upper = ""; //create a new empty string to hold uppercase values
    for (int i = 0; i < str.length(); i++) //for loop that runs for every character in the string
    {
        upper += (char)toupper(str[i]); //for each loop cast the string to a character, turn it uppercase, and add it to the upper string
    }
    return upper; //return the new string
}

int main()
{
    srand(time(0));
    Game game;
    game.readMap("Map.txt");
    game.readItems("Items.txt");
    game.readDragons("Dragons.txt");

    cout << "Welcome weary traveler! What is your name?" << endl;
    string name;
    getline(cin, name);
    game.setUsername(name);
    cout << endl;
    cout << "Nice to meet you " << game.getUsername() << "! My name is Professor Pikoshi and this is our city Central Dragonium!" << endl;
    cout << "Here we have many dragons roaming the land, but be careful, not all are friendly. Stay on the path to avoid being ambished by wild dragons, they often steal loot from travelers" << endl;
    cout <<  "Collect items found throughout the world in the wild to earn coins at the SHOPS and unlock new abilities" << endl;
    cout << "and earn yourself a place among the legendary Dragon Riders. Learn about the different dragons and collect new ones by brining eggs to the INCUBATION STATIONS." << endl;
    cout << "I wish you luck on your journey, " << game.getUsername() << ", and I will give you this Weedleshnee dragon to begin your journey!" << endl;
    cout <<  endl << "WEEDLESHNEE obtained" << endl << endl;
    cout << "Almost forgot! If you run into the only legendary dragon, Ultimite, run for your life, but obtaining the loyalty of this dragon will make you the strongest man alive!" << endl << endl;
    bool check = true;
    int turnCounter = 0;
    while (check == true){
        turnCounter++;
        int menuOp;
        cout << "Turn: " << turnCounter << endl;
        cout << "User: " << game.getUsername() << endl;
        cout << " ----Map----" << endl;
        game.printMap();
        cout << "1. View your dragon" << endl << "2. View inventory" << endl << "3. Travel" << endl << "4. Finish your adventure" << endl;
        cin >> menuOp;
        switch(menuOp) {
            case 1: //view dragon
                game.printCurDragon();
                break;
            case 2: //view inventory
                game.viewInventory();
                break;
            case 3: //travel
                game.travel();
                break;
            case 4: //quit
            {    
                string quit;
                cout << "Are you sure you want to quit? Yes or No?" << endl;
                bool check = false;
                while(!check) {
                    getline(cin,quit);
                    if (toUpper_(quit) == "YES"){
                        game.endGame();
                        return 0;
                    }
                    else if (toUpper_(quit) == "NO"){
                        break;
                    }
                }
            }
            default:
                cout << "Invalid option" << endl;
                break;
        }
        game.checkTile();
        game.giveItems();
        game.randomDragon();
    }
}

//g++ -std=c++11 User.cpp Items.cpp Map.cpp Dragons.cpp Game.cpp driver.cpp -o driver.o