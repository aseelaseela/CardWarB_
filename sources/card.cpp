#include "card.hpp"
#include <string>
#include <iostream>
using namespace std;
namespace ariel
{
    // empty constructor
    //Card::Card() : rank(Rank::No_Rank), suit(Suit::Hearts)
    //{};
    // constructor
    Card::Card(Rank rank, Suit suit) 
    {
        this->rank=rank;
        this->suit=suit;
    }
    // copy constructor
    //Card::Card(const Card &other) noexcept :  rank(other.rank),suit(other.suit)
    //{};
    string Card::tostring(){
        string str1,str2;
        Rank rank=this->getRank();
        Suit suit=this->getSuit();
        switch (rank)
        {
        case Rank::Ace:
            str1="Ace";
            break;
        case Rank::Two:
            str1="Two";
            break;   
        case Rank::Three:
            str1="Three";
            break;
        case Rank::Four:
            str1="Four";
            break;   
        case Rank::Five:
            str1="Five";
            break; 
        case Rank::Six:
            str1="Six";
            break; 
         case Rank::Seven:
            str1="Seven";
            break;      
        case Rank::Eight:
            str1="Eight";
            break;   
        case Rank::Nine:
            str1="Nine";
            break; 
        case Rank::Ten:
            str1="Ten";
            break; 
         case Rank::Jack:
            str1="Jack";
            break; 
           case Rank::Queen:
            str1="Queen";
            break; 
        case Rank:: King:
            str1="King";
            break; 
                                     
        default:
            str1="?";
            break;
        }
        switch (suit)
        {  
        case Suit::Clubs:
            str2="Clubs";
            break;
        case Suit::Diamonds:
            str2="Diamonds";
            break;
        case Suit::Hearts:
            str2="Hearts";
            break;      
        case Suit::Spades:
            str2="Spades";  
            break;      
        default:
            str2="?";
            break;
        }
        return (str1 + " of the " +str2);
      }
     //compare two cards :
    //bool Card::operator>(const Card &other) const{
      //  if (this->rank==Rank::Two&& other.rank==Rank::Ace)
       // {
         //   return false;
        //}
        //return rank>other.rank;
    //}
    bool Card::operator<(const Card &other) const{
        if (this->rank==Rank::Ace&& other.rank==Rank::Two)
        {
            return true;
        } else if(this->rank > Rank::Two && other.rank==Rank::Ace) return true;
        return rank<other.rank;
    }
    bool Card::operator==(const Card &other) const{
        return rank==other.rank;
    }
    //bool Card::operator!=(const Card &other) const{
      //  return rank!=other.rank;
    //}
}