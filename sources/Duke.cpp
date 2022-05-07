#include "Duke.hpp"
namespace coup
{
    Duke::Duke(Game &game, string name) : Player(game, name)
    {
    }

    void Duke::tax()
    {
        if(!isEnoughPlayer())
        {
            throw std::runtime_error("Not enough players");
        }
    }



    Duke::~Duke()
    {
    }
    void Duke::block(Player &p){
        cout<<"block" << endl ;
    }

}