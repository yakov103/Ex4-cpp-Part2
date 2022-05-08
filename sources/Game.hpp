

#ifndef GAME_HPP
#define GAME_HPP



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
            vector<Player*> playersVec;
            unsigned int currentPlayer;
            bool gameStarted;
            bool gameEnded;
            Game();//constructor
            ~Game();//destructor
            vector<string> players();
            string turn(); 
            string winner(); 
            void addPlayer(Player* player);
            void nextTurn(); 


};

}


#endif // GAME_HPP






