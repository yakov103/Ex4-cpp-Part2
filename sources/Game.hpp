

#ifndef GAME_HPP
#define GAME_HPP



#include <iostream> 
#include <vector>
#include <string>
#include <stdexcept>
#include "Player.hpp"


using namespace std;

namespace coup{
    class Player;
    class Game{
        private:
      

        public:
            vector<Player*> players;
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






