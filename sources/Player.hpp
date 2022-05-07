#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Game.hpp"
#pragma once
using namespace std;
namespace coup{
    class Player { 
        private : 
        string name;
        unsigned int amountCoins; 
        Game *game; 
        unsigned int index;
        bool alive;
        bool used_foreign_aid;

 
        public : 

        Player(Game & game, string name_init); 
        ~Player();
        unsigned int getIntex();
        bool isEnoughPlayer();
        void income();
        void foreign_aid();
        void coup(Player &player);
        void role();
        int coins();
        void addCoins(int coins);

        
        virtual void tax ();
        virtual void transfer(Player &player, Player &player2);
        virtual void steal(Player &player);
        virtual void block (Player &player);


        ~Player();

    };


}