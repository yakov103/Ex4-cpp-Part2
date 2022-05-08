#include "Player.hpp"

using namespace std ;

namespace coup { 
class Captain : public Player {
    public: 
    int steal_amount ;
    Player *steal_from ;

    Captain (Game *game, string name) ;
    ~Captain () ;
    void block (Player *player) ;
    void blocked () ;
    string role()  ;
    void steal (Player *player) ;

};






}