#include <iostream>
#include <unordered_map>
#include <functional>
#include <limits>
#include "usablestuffs.hpp"
#include "./computer/computer.hpp"
#include <unordered_set>

using namespace std;

void newGame();
void loadGame();
void highScore();
string moveToString(int move);

void rockPaperScissors(){
    autodetect_clear();
    int userInput = 0;
    unordered_map<int, function<void()>> inputChecker {
        {1, newGame}, {2, loadGame}, {3, highScore}
    };

    while (userInput != 4)
    {
        autodetect_clear();

        cout << "==================================================================\n";
        cout << "======== WELCOME TO ROCK PAPER SCISSORS - THE SIMPLE GAME ========\n";
        cout << "==================================================================\n";
        cout << "Pick your options!\n";
        cout << "1. New Game\n";
        cout << "2. Load Game\n";
        cout << "3. High Score\n";
        cout << "4. Exit\n";

        while (true)
        {
            cout << "Insert your choice: ";
            cin >> userInput;
            if (inputChecker.find(userInput) != inputChecker.end())
            {
                inputChecker[userInput]();
                break;
            }
            else if (userInput == 4)
            {
                cout << "Thank you for playing!" << endl;
                autodetect_pause();
                break;
            }
            else{
                cout << "Invalid input." << endl;
                cinClear();
            }
        }   
    }
}

void newGame(){
    autodetect_clear();

    cout << "Welcome, Player! You are now going to defeat the bot in this funi game!\n";
    cout << "You have three lives from the start, so guess wisely!" << endl;
    
    autodetect_pause();

    bool quit_func = false;
    int stageScore = 1; // If I put it inside, it'll keep rolling Stage 1 lol

    while (!quit_func)
    {
        autodetect_clear();

        unordered_set<int> inputChecker = {1, 2, 3};
        
        int userInput = 0;
        int health = 3;
        int botHealth = 3;
        
        cout << "\n=========================\n";
        cout << "======== STAGE " << stageScore << " ========\n";
        cout << "=========================\n";
        while (true)
        {
            cout << "Your health: " << health << " | Bot health: " << botHealth << '\n';
            cout << "Pick your choice!\n";
            cout << "1. Rock\n2. Paper\n3. Scissors\n4. Quit" << endl;

            int botChoice = computerDecision();

            cout << ">> ";
            cin >> userInput;

            if (inputChecker.find(userInput) != inputChecker.end())
            {
                cout << "You chose: " << moveToString(userInput) << endl;
                cout << "Bot chose: " << moveToString(botChoice) << endl;

                if (userInput == botChoice) {
                    cout << "It's a draw!" << endl;
                } 
                else if (
                    (userInput == 1 && botChoice == 3) ||
                    (userInput == 2 && botChoice == 1) ||
                    (userInput == 3 && botChoice == 2)
                ) {
                    cout << "You win this round!" << endl;
                    botHealth--;
                } 
                else {
                    cout << "Bot wins this round!" << endl;
                    health--;
                }

                if (health == 0) {
                    cout << "You lost! Game over." << endl;
                    autodetect_pause();
                    break;
                }

                if (botHealth == 0) {
                    cout << "You beat Stage " << stageScore << "! Advancing..." << endl;
                    stageScore++;
                    autodetect_pause();
                    break;
                }
            }
            else if (userInput == 4)
            {
                quit_func = true;
                break;
            }
            else {
                cout << "Invalid input." << endl;
                cinClear();
            }
        }
    }
}

void loadGame(){
    cout << "Coming soon!" << endl;
    autodetect_pause();
}

void highScore(){
    cout << "Coming soon!" << endl;
    autodetect_pause();
}

string moveToString(int move) {
    switch (move) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Unknown";
    }
}