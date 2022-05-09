#include "Duke.hpp"

namespace coup {
Duke::Duke(Game &game, string name) : Player(game, name) {
}


string Duke::role() {
    return "Duke";
}



void Duke::block(Player &player) {
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