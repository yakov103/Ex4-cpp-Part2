#include "Player.hpp"

using namespace std;
namespace coup{
    class Captain : public Player
    {
    private:
    public:
        Captain(Game &game, string name);
        void block(Player &p);
        void steal(Player &p);
        ~Captain();
    };


}