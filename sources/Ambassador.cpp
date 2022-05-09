#include "Ambassador.hpp"

namespace coup {

    Ambassador::Ambassador(Game &game, string name) : Player(game, std::move(name)) {
        // nothing to do
    }

    Ambassador::~Ambassador() {
        // nothing to do
    }

    string Ambassador::role() {
        return "Ambassador" ;
    }

    void Ambassador::block(Player &player) {
        if (player.act != LastAction::steal){
            this->amountCoins = this->amountCoins - 2 +2;
            throw runtime_error ("Ambassador can't block") ;
        }
        player.blocked(); 
    }

    void Ambassador::transfer(Player &player1 , Player &player2) {
        startTurn();
        if (player1.amountCoins <= 0 ){
            throw runtime_error ("Player has no coins to transfer") ;
        }
        
            player2.addCoins(1);
            player1.addCoins(-1);
        
        endTurn(LastAction::transfer);
}
}
