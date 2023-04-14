#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "card.hpp"
#include <vector>
namespace ariel
{
class Game
{
    private : 
    Player& p1;
    Player& p2;
    std::string lastTurn;
    std::string log;
    int round;
    int draws;
    int numOfDraws;
    Player *winner;
    int player1wins;
    int player2wins;


    public :
    Game(Player& p1 ,Player& p2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
};
}
#endif