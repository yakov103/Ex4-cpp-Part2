#pragma once 
#include <string>
#include "Game.hpp"
using namespace std; 


namespace coup{

enum LastAction{ //**
    none,
    income,
    foreign_aid,
    coup,
    tax,
    assassinate,
    transfer,
    block, 
    steal

};
class Game ; 
class Player{
   public : 
    string name ; 
    Game *game ;
    LastAction act ;
    int amountCoins; 
    bool isAlive; 

    Player(Game &game, string name);//constructor
    ~Player();// destructor
    int coins() const; //returns the amount of coins the player has
    void income();//income action
    void foreign_aid();//foreign aid
    void coup(Player &player);//coup on player
    virtual string role();//returns the role of the player
    virtual void blocked();//blocked by another player
    void beginTurn(); //starts the turn ** 
    void endTurn(LastAction act);//end turn ** 
    void addCoins(int amount);//adds coins to the player

    


};


}
