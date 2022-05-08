#include "Player.hpp"

namespace coup { 
class Contessa : public Player {
public : 
    Contessa(Game &game, string name);
    ~Contessa();// destructor
    string role();// returns the role of the player
    void block(Player &player); // block by another player


} ;

}