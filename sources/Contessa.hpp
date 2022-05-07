#include "Player.hpp"

namespace coup{
    class Contessa : public Player
    {
    private:

    public:
        Contessa(Game &game, string name);
        void block(Player &p);
        ~Contessa();
    };
}