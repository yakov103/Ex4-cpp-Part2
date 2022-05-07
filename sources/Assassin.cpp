#include "Assassin.hpp"
namespace coup
{
    Assassin::Assassin(Game &game, string name) : Player(game, name)
    {
    }
     void Assassin::role(){
        cout<<"Assassin"<<endl;
    }
    void Assassin::block (Player p){

    }

    Assassin::~Assassin()
    {
    }
   

}