//
// Created by Darin Lee on 12/26/2019.
//

#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <string>

class Deck;

class Card {
 public:
  Card(int rank, int suit);
  int getRank();
  int getSuit();
  std::string toString();

 private:
  int rank;
  int suit;
  bool inDeck;

  friend Deck;
};

#endif //BLACKJACK_CARD_H
