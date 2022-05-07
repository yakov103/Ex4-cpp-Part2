#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>

const short START_COINS = 0;
const short MAX_COINS = 10;
const short COUP_COST = 7;

namespace coup { 
        Player::Player(Game & game, string name_init){
        this->name = move(name_init);
        this->game = &game; 
        this->amountCoins = START_COINS;
        this->alive = true;
        this->used_foreign_aid = false;
        this->index = game.addPlayer(this);

        //game.addPlayer(name_init); 

        }
        Player::~Player(){
        }
        void Player::addCoins(int coins){
            this->amountCoins += coins; // add coins to the player
        }
        // return the current game 
        Game* Player::getGame(){
            return this->game;
        }

        string Player::getName(){
            return this->name;
        }
        bool Player::isAlive(){
            return this->alive;
        }
        bool Player::isForeignAid(){
            return this->used_foreign_aid;
        }
        
        void Player::income(){
          if (this->amountCoins == MAX_COINS){
            throw std::runtime_error("Player already has max coins , he must coup !");
          }
          if (!isPlayerTurn()){
          throw std::runtime_error("It is not your turn !");
          }
          this->amountCoins += 1;
          used_foreign_aid = false;
          game->changeTurn();
        } 

        void Player::foreign_aid(){
           if (this->amountCoins == MAX_COINS){
            throw std::runtime_error("Player already has max coins , he must coup !");
          }
          if (!isPlayerTurn()){
          throw std::runtime_error("It is not your turn !");
          }
          this->amountCoins += 2;
          used_foreign_aid = true;
          game->changeTurn(); 

        }
        void Player::coup(Player &player){
            cout << "coup" << endl ; 

        }
        void Player::role(){
           return "still no role yet"; 
        }
        int Player::coins(){
            return (int)this->amountCoins; 
        }

        bool Player::isPlayerTurn(){
          if (this->game->players().size() < 2 && !game->gameOnline()){
            throw std::runtime_error("Not enough players");
          }
          return game->turn() == this->name;
        }

        Player::~Player(){

        }





}