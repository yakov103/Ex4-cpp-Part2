#include "Game.hpp"
namespace coup{

    Game::Game(){
        gameStarted = false;
        currentPlayer = 0 ; 
    }

    Game::~Game(){
        for (auto player : playersVec){
            delete player;
        }
    }

vector <string> Game::players(){
    vector <string> playerNames;
    for(unsigned int i = 0; i < playersVec.size(); i++){
        playerNames.push_back(playersVec[i]->name);
    }
    return playerNames; //returns a vector of player names
}

string Game::turn(){
    if (this->playersVec.size() == 0){
        throw invalid_argument("No players in game");
    }
    return playersVec[currentPlayer]->name; //returns the name of the current player
    }

string Game::winner(){
    if (!(this->gameStarted) || this->playersVec.size() != 1){
        throw invalid_argument("No players in game");
    }
    return playersVec[0]->name; //returns the name of the winner
}

void Game::addPlayer(Player* player){
    if (this->playersVec.size() >= MAXPLAYERS){
        throw invalid_argument("Too many players");
    }
    if (this->gameStarted){
        throw invalid_argument("Game already started");
    }
    this->playersVec.push_back(player);
}

void Game::nextTurn(){
    if (this->playersVec.size() == 0){
        throw invalid_argument("No players in game");
    }
    currentPlayer+=1;
    currentPlayer%= playersVec.size();
    if (!playersVec[currentPlayer]->isAlive){
        nextTurn();
    }
}


}//namespace coup