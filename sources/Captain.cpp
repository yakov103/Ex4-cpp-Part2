#include "Captain.hpp"
namespace coup
{
    Captain::Captain(Game &game, string name) : Player(game,name)
    {
    }

    Captain::~Captain()
    {
    }
    void Captain::block(Player &p){
        cout<<"block"<<endl ;
    }
    void Captain::steal(Player &p){
        cout << "stral" << endl;
    }
}