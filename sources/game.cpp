#include <iostream>
#include <string>
#include "player.hpp"
#include "game.hpp"
#include <vector>
#include <cstdlib>
#include<algorithm>
#include <chrono>
#include <random>
using namespace std;
namespace ariel
{
Game ::Game (Player &player1 ,Player &player2):p1(player1),p2(player2),winner(nullptr),lastTurn(" "),log(" "),round(0),draws(0),numOfDraws(0),player1wins(0),player2wins(0)
{
    this->round=0;
    this->numOfDraws=0;
    player1wins=0;
    player2wins=0;
    if(player1.theplayerinGame())
    {
        throw invalid_argument("player 1 is already in the game ! ");
    }
    if(player2.theplayerinGame())
    {
        throw invalid_argument("player 2 is already in the game ! ");
    }
     if(player2.theplayerinGame() || player1.theplayerinGame())
    {
        throw invalid_argument("wait until player finish the game ! ");
    }
    vector<Card>cards;
    Suit suitarr[4]={Suit::Spades,Suit::Hearts,Suit::Clubs,Suit::Diamonds};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            cards.push_back(Card((Rank)j,suitarr[i]));
        }
    }
    unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 g(seed);
    std::shuffle(cards.begin(),cards.end(),g);
    while (!cards.empty())
    {
        if((int)cards.size()%2==0){
            player1.add(cards.back());
        }
        else player2.add(cards.back());
        cards.pop_back();
    }
    
    this->p1.setplayerinGame(true);
    this->p2.setplayerinGame(true);
   
}
void Game:: playTurn()
{ 
    if (&p1 ==&p2)
    {
    throw runtime_error("to play the game we need 2 diffrent players ..");
    //throw invalid_argument("to play the game we need 2 diffrent players ..");
    }
    if(p1.theplayerinGame() && p2.theplayerinGame())
    {  
        if (++this->round>26)
        {
            throw runtime_error("the game already ended ..");
          // throw invalid_argument("the game already ended ..");
        }
        if (p1.stacksize()==0 && p2.stacksize()==0)
        {
             throw runtime_error("the game already ended ..");
        }
        
        int draw=0;
        int recent=0;
        this->lastTurn="  ";
        Card pl1c=p1.cardinHand();
        Card pl2c=p2.cardinHand();
        p1.removethecard();
        p2.removethecard();
        this->lastTurn+="*"+to_string(this->round)+" : "+p1.getName()+"played card : "+pl1c.tostring()+ +"\n"+p2.getName()+"played card : "+pl2c.tostring()+"\n";
        while (pl1c==pl2c)
        {
        this->draws++;
        this->numOfDraws++;
        this->lastTurn+="*Draws \n";
         if(p1.stacksize()<=1 || p2.stacksize()<=1)
          {
        //split the cards on the table
             while (recent>0)
             {    
                p1.addcardesTaken();
                p2.addcardesTaken();
                recent-=2;
             }
             break;
          }
             p1.removethecard();
             p2.removethecard();

             //new cards and add them to the table
             pl1c=p1.cardinHand();
             pl2c=p2.cardinHand();
             p1.removethecard();
             p2.removethecard();

             //recent+=2;
             recent+=4;
             this->lastTurn+="*"+to_string(this->round)+" : "+p1.getName()+"played card : "+pl1c.tostring()+ +"\n"+p2.getName()+"played card : "+pl2c.tostring()+"\n";
         }
   // Player* winnerofgame=nullptr;
    //detemine the winner of the round
    if (pl2c<pl1c)
    {
        this->player1wins++;
        this->lastTurn+="*"+to_string(this->round)+" : "+p1.getName()+"played card : "+pl1c.tostring()+ +"\n"+p2.getName()+"played card : "+pl2c.tostring()+"\n";
        while (recent>0)
        {
            p1.addcardesTaken();
            --recent;
        }
        
    }
    else  if (pl1c<pl2c)
    {
        this->player2wins++;
        this->lastTurn+="*"+to_string(this->round)+" : "+p1.getName()+"played card : "+pl1c.tostring()+ +"\n"+p2.getName()+"played card : "+pl2c.tostring()+"\n";
        while (recent>0)
        {
            p2.addcardesTaken();
            recent--;
        }
    } 
    //add the result of the turn to the log
    else  this->lastTurn+="DRAW .";
        //this->log+=this->lastTurn;
    
    if(!p1.stacksize() || !p2.stacksize())
    {
        p1.setplayerinGame(false);
        p2.setplayerinGame(false);
        if (p1.cardesTaken()>p2.cardesTaken())
        {
         this->winner=&p1;
        }
        else this->winner=&p2;
    }
    this->log+=this->lastTurn;
    }

    else throw logic_error("the game is over.");

}
void Game:: printLastTurn()
{
cout<< lastTurn << endl;
}
void Game:: playAll()
{
    while (p1.stacksize()!=0 && p2.stacksize()!=0)
    {
       playTurn();
    }
    
}
void Game:: printWiner()
{
    //if (p1.theplayerinGame() || p2.theplayerinGame()) return;
    if (p1.cardesTaken()-p2.cardesTaken()==0)
    {
        cout << "draw ."<<endl;
    }
    else if (p1.cardesTaken()-p2.cardesTaken()>0)
    {
        cout << "plater 1 won"<<endl;
    }
    else cout << "plater 2 won"<<endl;
}
    
void Game:: printLog()
{
cout<<log<< endl;
}
void Game:: printStats()
{
std::cout <<"stats of the game : \n" <<p1.getName() << "this player won "<<this->p1.cardesTaken()<<"cards"<<"and has win rate of : "<< (double)player1wins / (double) round<<endl;
std::cout<<p2.getName() << "this player won "<<this->p2.cardesTaken()<<"cards"<< "and has win rate of : "<< (double)player2wins / (double) round<<endl;

}
}