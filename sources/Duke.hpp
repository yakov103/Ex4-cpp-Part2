#include "Player.hpp"

namespace coup { 
    class Duke : public Player {
        public:
            Duke(Game &game, string name);
            ~Duke();// destructor
            string role();// returns the role of the player
            void block(Player &player); // block by another player
            void tax(); // tax action


};
}