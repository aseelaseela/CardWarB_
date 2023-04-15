#include "player.hpp"
using namespace std;
namespace ariel
{
    Player :: Player (string name)
    {
        this->playerName=name;
        this->playerinGame=false;
        this->cardsTaken=0;
    }
    //prints the amount of cards left. should be 21 but can be less if a draw was played
    int Player :: stacksize()
    {
        return (int)this->cardstuck.size();
    }
    //prints the amount of cards this player has won. 
    int Player :: cardesTaken()
    {
        return this->cardsTaken;
    }
    void Player :: addcardesTaken()
    {
        this->cardsTaken++;
    } 
    string Player :: getName()
    {
        return this->playerName;
    }
    bool Player:: theplayerinGame()
    {
        return this->playerinGame;
    }
    void Player::setplayerinGame(bool playingOrno)
    {
        this->playerinGame=playingOrno;
    }
    void Player ::add(Card &card)
    { 
        bool flag=false;
        for (size_t i = 0; i < this->stacksize() ; i++)
        {
            Card d=this->cardstuck.at(i);
            if (d.getSuit()==card.getSuit() && d.getRank()==card.getRank())
            {
               flag=true;
            }
        }
        if(flag)
        this->cardstuck.push_back(card);
        else throw invalid_argument("the card existed");
        
    }
     Card& Player :: cardinHand()
    {
        return this->cardstuck.back();
    }
    void Player :: removethecard()
    {
        this->cardstuck.pop_back();
    }
}