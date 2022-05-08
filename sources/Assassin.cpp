#include "Assassin.hpp"

namespace  coup { 

    Assassin::Assassin(Game &game, string name) : Player(game, name) {
        this->target = NULL; 
    }
    string Assassin::role() {
        return "Assassin";
    }
    void Assassin::coup(Player &player) {
        startTurn();
        if (!player.isAlive){
            throw invalid_argument("Player is already dead");
        }
        if (amountCoins <= 2 ){
            throw invalid_argument("Player does not have enough money to coup");
        }
        if (amountCoins < 7 ){
            player.isAlive = false;
            target = &player;
            this->addCoins(-3);
            endTurn(LastAction::assassinate);
        }
        else {
            player.isAlive = false;
            target = &player;
            this->addCoins(-7);
            endTurn(LastAction::coup);
        }
    }

    void Assassin::blocked() {
        if (act == LastAction::foreign_aid){ 
            this->amountCoins -= 2 ; 
            act = LastAction::none;
        }   
        else if (act == LastAction::assassinate){
            target->isAlive = true; 
            target = NULL;
        }
        else {
            throw invalid_argument("Player is not blocking");
        }
        act = LastAction::none;
    }
    }



