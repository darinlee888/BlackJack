//
// Created by Darin Lee on 12/26/2019.
//

#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include "Card.h"
#include <vector>

class Deck {
 public:
  Deck();
  Card remove(int suit, int rank);

 private:
  std::vector<std::vector<Card>> cards;
};

#endif //BLACKJACK_DECK_H
