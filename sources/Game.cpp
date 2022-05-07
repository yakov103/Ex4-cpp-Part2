#include "Game.hpp"
#define MAX_PLAYERS 6

namespace coup { 
        // constract  the game with 0 player 
        Game::Game(){
        this->currentPlayer = nullptr; 
        this->turnNumber = 0; 
        this->gameOver = false;
        this->gameStarted = false;
        }




        unsigned int Game::addPlayer(Player *player){
            if (playerList.size() >= MAX_PLAYERS){
                throw std::runtime_error("Too many players");
            }
            if (gameStarted || gameOver){
                throw std::runtime_error("Game already started");

             }
             if (playerList.size() == 0){
                currentPlayer = player;
             }
                playerList.push_back(player);
                return playerList.size()-1;
        }
        

        /* if contessa blocks an assasination attempt , then we revive the player back */ 

        void Game::revive(Player *player){
            if(playerLIst[player->getIndex()]  == player){
                throw std::runtime_error("Player is already alive");
            }
            else if (playerList[player->getIndex()] == nullptr){
                playerList[player->getIndex()] = player;
                player->setAlive(true);
                std::coud << "Player " << player->getName() << " is revived" << std::endl;
                return ; 
           }    
           else { 
               throw std::runtime_error("Error revive fuction");
           }
           

        }


        // when a player is killed using coup kill function , we need to remove the player from the game
        void Game::playerDead(Player *player){
        for (unsigned int i = 0; i < playerList.size(); i++){
            if (playerList[i] == player){
                playerList[i] = nullptr;
                player->setAlive(false);
                break ;
        }
        }
        if (winner() != "No winner"){
            gameOver = true;
        }

        }



        // return list of players 
        vector<string> Game::players(){
            vector<string> playerNames;
            for (unsigned int i = 0; i < playerList.size(); i++){
                if (playerList[i] != nullptr){
                    playerNames.push_back(playerList[i]->getName());
                }
            }
            return playerNames;
        }


        bool Game::gameOnline(){
        if (gameOver){
                return false; 
            }
        return gameStarted;
        }

        // return the current player
        string Game::turn(){
                return this->currentPlayer->name;
        }

        Player *Game::getPlayerTurn(string name){
            for (unsigned int i = 0; i < playerList.size(); i++){
                if (playerList[i]->getName() == name){
                    return playerList[i];
                }
            }
            cout << "Player not found" << endl;
            return nullptr;
        }

        void Game::changeTurn(){
            gameStarted = true;
            if (winner() != "No winner"){
                gameOver = true;
            }
            currentPlayerIndex+=1;
            currentPlayerIndex%=playerList.size();
            currentPlayer = playerList[currentPlayerIndex];
            if (currentPlayer == nullptr){
               changeTurn();
               return ; 
            }
            if (gameOver){
               for (unsigned int i = 0; i < playerList.size(); i++){
                   if (playerList[i] != nullptr){
                       currentPlayer = playerList[i];
                       break ;
            }
               }
            }

            if (currentPlayer == nullptr){
            throw std::runtime_error("No player left");
            }
        }


        // return winner
        string Game::winner(){ 
        unsigned int counter = 0;
        unsigned int  i ; 
        for (i = 0; i < playerList.size(); i++){
            if (playerList[i]->isAlive()){
                counter++;
            }
        }
        if (counter == 1){
            return playerList[i]->name;
        }
        if (gameOver){
                return this->currentPlayer->name;
            }
        else{
                return "No winner";
            }
        }
        
        Game::~Game(){

        }




}