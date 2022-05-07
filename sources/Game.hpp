#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Player.hpp"
#pragma once
using namespace std;

// coup game class
namespace coup
{
    class Game
    {
    private:
        vector<Player *> playerList; // list of players
        Player *currentPlayer; // current player
        unsigned int currentPlayerIndex; // current player index
        unsigned int turnNumber;    // turn number
        bool gameOver; 
        bool gameStarted;
    
    public: 
    // Constructor
        Game(/* args */);
    // Destructor
      ~Game();

    // Methods
        bool gameOnline();
        unsigned int addPlayer(Player *player);
        vector<Player *> players();
        string turn();
        string winner();
        void revive(Player *player);
        //void addPlayer(string name);
      
    };
    
}