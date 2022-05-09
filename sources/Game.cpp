#include "Game.hpp"
namespace coup{

    Game::Game(){ // constructor
        gameStarted = false;
        currentPlayer = 0 ; 
    }

    Game::~Game(){ // destructor
    }

vector <string> Game::players(){ // returns the names of the players
    vector <string> playerNames;
    for(unsigned int i = 0; i < playersVec.size(); i++){
        if( playersVec[i]->isAlive ){
            playerNames.push_back(playersVec[i]->name);
        }
    }
    return playerNames; //returns a vector of player names
}

string Game::turn(){ // returns the name of the current player
    if (this->players().empty()){
        throw invalid_argument("No players in game");
    }
    return playersVec[currentPlayer]->name; //returns the name of the current player
    }

string Game::winner(){ // returns the name of the winner
    if (!(this->gameStarted) || this->players().size() != 1){
        throw invalid_argument("No players in game");
    }
    for (unsigned int i = 0; i < this->playersVec.size(); i++){
        if (this->playersVec[i]->isAlive){
            return this->playersVec[i]->name;
        }
    }


    return playersVec[0]->name; //returns the name of the winner
}

void Game::addPlayer(Player* player){ // adds a player to the game
    if (this->playersVec.size() >= MAXPLAYERS){
        throw invalid_argument("Too many players");
    }
    if (this->gameStarted){
        throw invalid_argument("Game already started");
    }
    this->playersVec.push_back(player);
}

void Game::nextTurn(){
    if (this->players().empty()){
        throw invalid_argument("No players in game");
    }
    currentPlayer+=1;
    currentPlayer%= playersVec.size();
    if (!playersVec[currentPlayer]->isAlive){
        nextTurn();
    }
}


}//namespace coup