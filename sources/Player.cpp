#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>

const short START_COINS = 0;
const short MAX_COINS = 10;
const short COUP_COST = 7;

namespace coup { 
        Player::Player(Game & game, string name_init){
        this->name = name_init; 
        this->game = &game; 
        this->amountCoins = START_COINS;
        this->alive = true;
        this->used_foreign_aid = false;
        this->index = game.addPlayer(this);

        //game.addPlayer(name_init); 

        }
        void Player::income(){
            this->amountCoins++;  

        }

        void Player::addCoins(int coins){
            this->amountCoins += coins; 
        }

        void Player::foreign_aid(){
            this->amountCoins+=2; 

        }
        void Player::coup(Player &player){
            cout << "coup" << endl ; 

        }
        void Player::role(){
            cout << "roles" << endl ; 
        }
        int Player::coins(){
            return (int)this->amountCoins; 
        }

        bool Player::isEnoughPlayer(){
          if (this->game->players().size() < 2 && !game->gameOnline()){
            throw std::runtime_error("Not enough players");
          }
          return 
        }

        Player::~Player(){

        }





}