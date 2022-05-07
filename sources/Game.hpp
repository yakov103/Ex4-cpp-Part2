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
        bool gameOnline(); // check if game is online
        void playerDead(Player *player); // player is dead
        unsigned int addPlayer(Player *player); // return player index
        vector<Player *> players();
        string turn();
        Player *getPlayerTurn(string name);
        void changeTurn();
        string winner(); 
        void revive(Player *player); // revive a player
        //void addPlayer(string name);
      
    };
    
}