#include "Game.hpp"
#define MAX_PLAYERS 6

namespace coup { 
        // constract  the game with 0 player 
        Game::Game(){
        this->i = turnNumber;
        turnNumber = 0; 
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
                return playerList.size();
        }


        // return list of players 
        vector<string> Game::players(){
                return this->playerList; 
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


        // return winner
        string Game::winner(){ 
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