#include "Game.hpp"

namespace coup{
class Game;
Player::Player(Game &game, string name){
    this->name = name;
    this->game = &game;
    this->isAlive = true;
    this->act = LastAction::none;
    this->amountCoins = 0;
    game.addPlayer(this);
}

Player::~Player(){
    game->playersVec.erase(std::remove(game->playersVec.begin(), game->playersVec.end(), this), game->playersVec.end());
}
void Player::income(){
    if (amountCoins >= MAXMONEY){
        throw invalid_argument("Player already has max amount of money, must coup");
    }
    startTurn();
    this->addCoins(1);
    endTurn(LastAction::income);
}

int Player::coins (){
    return amountCoins;
}

void Player::foreign_aid(){
        if (amountCoins >= MAXMONEY){
        throw invalid_argument("Player already has max amount of money, must coup");
    }
    startTurn();
    this->addCoins(2);
    endTurn(LastAction::foreign_aid);
}
void Player::coup(Player &player){
    startTurn();
    if (amountCoins < COUPPRICE){
        throw invalid_argument("Player does not have enough money to coup");
    }
    if (!player.isAlive){
        throw invalid_argument("Player is already dead");
    }
    player.isAlive = false;
    this->addCoins(-COUPPRICE);
    endTurn(LastAction::coup);
}

string Player::role(){
    return "still just a Player ";
}
void Player::blocked(){
    if (act == LastAction::foreign_aid){ 
        this->amountCoins -= 2 ; 
        act = LastAction::none;
    }   
    else { 
        throw invalid_argument("Player is not blocking");
    }

}

void Player::startTurn(){
    if (!isAlive){
        throw invalid_argument("Player is already dead");
    }
    if (game->players().size() < 3 ){
        throw invalid_argument("Not enough players to start game");
    }
    if (game->turn() != this->name){
        throw invalid_argument("Player already has started turn");
    }
    game->gameStarted = true;
}
void Player::endTurn(LastAction act){
    this->act = act;
    game->nextTurn();
}
void Player::addCoins(int amount){
    this->amountCoins += amount;
}

}// namespace coup


