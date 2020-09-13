//
// Created by Darin Lee on 12/26/2019.
//

#include "Deck.h"
#include <chrono>
#include <random>

Deck::Deck() {
  for (int i = 0; i < 4; i++) {
    std::vector<Card> oneSuit;
    for (int j = 0; j < 13; j++) {
      oneSuit.emplace_back(j+1, i+1);
    }
    cards.push_back(oneSuit);
  }
}

Card Deck::remove(int suit, int rank) {
  if (!cards[suit][rank].inDeck) {
    return {0, 0};
  }
  cards[suit][rank].inDeck = false;
  return cards[suit][rank];
}
