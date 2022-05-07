#include "Contessa.hpp"
namespace coup{
    Contessa::Contessa(Game &game, string name) : Player(game, name)
    {
    }
    
    Contessa::~Contessa()
    {
    }
    void Contessa::block(Player &p){
        cout<< "block" << endl;
    }
}