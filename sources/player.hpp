#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include <vector>
#include "card.hpp"
using namespace std;
namespace ariel
{
class Player{
    private:
        bool playerinGame;
        string playerName;
        int cardsTaken;
        //int stackSize;
        vector<Card>cardstuck;
    public:
        //to create player with his name
        Player (string pName);
        //prints the amount of cards left. should be 21 but can be less if a draw was played
        int stacksize();
        //prints the amount of cards this player has won. 
        int cardesTaken();
		void addcardesTaken();
      //  void setcardsTaken(int numOfCards);
        string getName();
        bool theplayerinGame();
        void setplayerinGame(bool playingOrno);
		void add(Card &card);
	    Card& cardinHand();
		void removethecard();
};
}
#endif