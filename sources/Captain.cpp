#include "Captain.hpp"

namespace coup {

    Captain::Captain(Game &game, string name) : Player(game, std::move(name)) {
        steal_amount = 0 ;
        steal_from = NULL ;
    }

    Captain::~Captain() {
        // nothing to do
    }

    void Captain::block(Player &player) {
       if (player.act != LastAction::steal){
        throw runtime_error ("Captain can't block") ;

       }
        amountCoins = amountCoins+1 ;
        amountCoins = amountCoins-1;  
       player.blocked(); 
    }

    void Captain::blocked() {
       if (this->act == LastAction::foreign_aid){
         this->addCoins(-2); // foreign aid costs 2 coins
       }
       else if (this->act == LastAction::steal){
           this->steal_from->addCoins(this->steal_amount);
           this->addCoins(-this->steal_amount);
       }
       else {
              throw runtime_error ("Captain can't block") ;
       }
       act = LastAction::none ;
    
    }


    string Captain::role() {
        return "Captain" ;
    }

    void Captain::steal(Player &player) {
        startTurn();
        if (player.amountCoins <= 0 ){
            throw runtime_error ("Player has no coins to steal") ;
        }
        if (player.amountCoins == 1){
            this->addCoins(1);
            player.addCoins(-1);
            steal_amount = 1 ;
            steal_from = &player ;
        }else {
            this->addCoins(2);
            player.addCoins(-2);
            steal_amount = 2 ;
            steal_from = &player ;

        }
        endTurn(LastAction::steal);
    }

}