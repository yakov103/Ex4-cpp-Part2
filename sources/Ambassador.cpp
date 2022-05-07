#include "Ambassador.hpp"
namespace coup{
    Ambassador::Ambassador(Game &game, string name) : Player(game,name)
    {
    }
        void Ambassador::transfer(Player &player1, Player &player2){
        cout << "EXCHANGE " << endl;
    }
    Ambassador::~Ambassador()
    {
    }

}