#include "Player.hpp"

using namespace std ; 

    namespace coup {
        class Ambassador : public Player {
            public:
            Ambassador (Game &game, string name) ; //   constructor
            ~Ambassador () ; // destructor 
            string role()  ; // returns the role of the player
            void block (Player &player) ; // block the player
            void transfer (Player &player1 , Player &player2) ;// transfer coins from player1 to player2
        };
    }