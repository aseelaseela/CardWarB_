#ifndef CARD_HPP
#define CARD_HPP
#include "iostream"
#include <string>
using namespace std;
namespace ariel
{
enum Rank
{
    Ace =1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    No_Rank
};
enum Suit
{
    Clubs= 1,
    Diamonds,
    Hearts,
    Spades,
};
class Card
{
 private:
    Rank rank;
    Suit suit;
  public:
      //empty constructor
      //Card();
      //constructor
      Card (Rank crank , Suit suit);
      //copy constructor
      //Card (const Card &other) noexcept;
      //return the rank
      Rank getRank() const{
        return rank;
      }
      //return the suit
      Suit getSuit () const{
        return suit;
      }
       string tostring();
      //compare two cards :
   // bool operator>(const Card &other)const;
    bool operator<(const Card &other)const;
    bool operator==(const Card &other)const;
   // bool operator!=(const Card &other)const;



};
}

#endif