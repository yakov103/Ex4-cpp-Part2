#include "Contessa.hpp"

namespace coup { 
Contessa::Contessa(Game &game, string name) : Player(game, name) {
}

string Contessa::role() {
    return "Contessa";
}

void Contessa::block(Player &player) {
    if (player.act != LastAction::assassinate) {
        throw invalid_argument("You cannot block the player because he didnt assisanted ");
    }
    this->player.blocked();
}

Contessa::~Contessa () {}


}