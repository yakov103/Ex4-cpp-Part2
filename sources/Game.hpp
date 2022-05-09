

// #ifndef GAME_HPP
// #define GAME_HPP


#pragma once
#include <iostream> 
#include <vector>
#include <string>
#include <stdexcept>
#include "Player.hpp"


using namespace std;

namespace coup{

    constexpr int COUPPRICE = 7;
    constexpr int MAXPLAYERS = 6;
    constexpr int MAXMONEY = 10;

    
    class Player;
    class Game{
        private:
      

        public:
        
            unsigned int currentPlayer;
            bool gameStarted;
            bool gameEnded;

            Game();//constructor
            ~Game();//destructor
            vector<Player*> playersVec;

            vector<string> players();
            string turn(); 
            string winner(); 
            void addPlayer(Player* player);
            void nextTurn(); 


};

}


//#endif // GAME_HPP






