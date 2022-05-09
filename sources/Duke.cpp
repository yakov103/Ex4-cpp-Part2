#include "Duke.hpp"

namespace coup {
Duke::Duke(Game &game, string name) : Player(game, std::move(name)) {
}


string Duke::role() {
    return "Duke";
}



void Duke::block(Player &player){
    amountCoins = amountCoins+1 ;
    amountCoins = amountCoins-1;  
    if (player.act != LastAction::foreign_aid) {
        throw invalid_argument("You cannot block the player because he didnt forgien aid");
    }
    player.blocked();
}

void Duke::tax() {
   startTurn();
    this->addCoins(3);
    endTurn(LastAction::tax);
}

Duke::~Duke() {
}
       




}