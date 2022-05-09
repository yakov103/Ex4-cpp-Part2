#include "Contessa.hpp"

namespace coup { 
Contessa::Contessa(Game &game, string name) : Player(game, std::move(name)) {
}


string Contessa::role() {
    return "Contessa";
}

void Contessa::block(Player &player) {
    amountCoins = amountCoins+1 ;
    amountCoins = amountCoins-1;  
    if (player.act != LastAction::assassinate) {
        throw invalid_argument("You cannot block the player because he didnt assisanted ");
    }
    player.blocked();
}

Contessa::~Contessa () {}


}