#include "Player.hpp"

namespace coup {

 class Assassin : public Player {
        public:
            Player *target;
            Assassin(Game &game, string name);
            ~Assassin();// destructor
            string role();// returns the role of the player
            void coup(Player &player); // coup on player
            void blocked(); // blocked by another player

   


};

}