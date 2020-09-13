//
// Created by Darin Lee on 12/26/2019.
//

#include "Card.h"

Card::Card(int rank, int suit) : rank(rank), suit(suit), inDeck(true) {}

int Card::getRank() {
  return rank;
}

int Card::getSuit() {
  return suit;
}

std::string Card::toString() {
  std::string output;
  if (getRank() == 1) {
    output += "Ace";
  }
  else if (getRank() == 2) {
    output += "Two";
  }
  else if (getRank() == 3) {
    output += "Three";
  }
  else if (getRank() == 4) {
    output += "Four";
  }
  else if (getRank() == 5) {
    output += "Five";
  }
  else if (getRank() == 6) {
    output += "Six";
  }
  else if (getRank() == 7) {
    output += "Seven";
  }
  else if (getRank() == 8) {
    output += "Eight";
  }
  else if (getRank() == 9) {
    output += "Nine";
  }
  else if (getRank() == 10) {
    output += "Ten";
  }
  else if (getRank() == 11) {
    output += "Jack";
  }
  else if (getRank() == 12) {
    output += "Queen";
  }
  else if (getRank() == 13) {
    output += "King";
  }
  output += " of ";
  if (getSuit() == 1) {
    output += "Diamonds";
  }
  else if (getSuit() == 2) {
    output += "Clovers";
  }
  else if (getSuit() == 3) {
    output += "Hearts";
  }
  else if (getSuit() == 4) {
    output += "Spades";
  }
  return output;
}
