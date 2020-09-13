//
// Created by Darin Lee on 12/29/2019.
//

#include "AIPlayer.h"
#include <iostream>
#include <chrono>
#include <random>

AIPlayer::AIPlayer(int id, Card visible, Card hidden) : Player(id, visible, hidden) {}

char AIPlayer::optionSelect() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator (seed);
  std::uniform_int_distribution<int> distribution(1,9);
  if (optimalScore > 11) {
    if (distribution(generator) > 21 - optimalScore) {
      return 'R';
    }
    return 'A';
  }
  return 'A';
}

void AIPlayer::display() {
  std::cout << "Player " << playerId << ":" << std::endl;
  std::cout << "Visible Card: " << visibleCard.toString() << std::endl;
  if (revealed) {
    std::cout << "Hidden Card: " << hiddenCard.toString() << std::endl;
  }
  if (!extraCards.empty()) {
    std::cout << "Extra Cards: " << std::endl;
    for (auto & extraCard : extraCards) {
      std::cout << extraCard.toString() << std::endl;
    }
  }
  if (revealed) {
    std::cout << "Player " << playerId << " has a score of " << optimalScore << "." << std::endl;
  }
}
