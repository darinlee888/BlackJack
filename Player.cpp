//
// Created by Darin Lee on 12/26/2019.
//

#include "Player.h"
#include <iostream>

Player::Player(int id, Card visible, Card hidden) :
  playerId(id), visibleCard(visible), hiddenCard(hidden), revealed(false) {
  if (visible.getRank() == 1 && hidden.getRank() == 1) {
    possibleScores.push_back(2);
    possibleScores.push_back(12);
    optimalScore = 1;
  }
  else if (visible.getRank() == 1) {
    possibleScores.push_back(1 + pointValue(hidden));
    possibleScores.push_back(11 + pointValue(hidden));
    optimalScore = 11 + pointValue(hidden);
  }
  else if (hidden.getRank() == 1) {
    possibleScores.push_back(pointValue(visible) + 1);
    possibleScores.push_back(pointValue(visible) + 11);
    optimalScore = pointValue(visible) + 11;
  }
  else {
    possibleScores.push_back(pointValue(visible) + pointValue(hidden));
    optimalScore = pointValue(visible) + pointValue(hidden);
  }
  if (optimalScore == 21) {
    revealed = true;
  }
}

int Player::getId() {
  return playerId;
}

Card Player::getVisibleCard() {
  return visibleCard;
}

Card Player::getHiddenCard() {
  return hiddenCard;
}

void Player::addCard(Card newCard) {
  if (optimalScore < 21) {
    extraCards.push_back(newCard);
    if (newCard.getRank() == 1) {
      std::vector<int> newScores(possibleScores);
      for (int i = 0; i < possibleScores.size(); i++) {
        newScores[i] += 1;
        newScores.push_back(possibleScores[i] + 11);
      }
      possibleScores = newScores;
    }
    else {
      for (int & possibleScore : possibleScores) {
        possibleScore += pointValue(newCard);
      }
    }
    updateScores();
  }
}

int Player::pointValue(Card notAce) {
  if (notAce.getRank() < 10) {
    return notAce.getRank();
  }
  return 10;
}

void Player::updateScores() {
  if (possibleScores.size() == 1) {
    optimalScore = possibleScores.front();
  }
  else {
    std::vector<int> updatedScores;
    int closest = 1;
    for (int possibleScore : possibleScores) {
      if (possibleScore <= 21) {
        updatedScores.push_back(possibleScore);
        if (possibleScore > closest) {
          closest = possibleScore;
        }
      }
    }
    optimalScore = closest;
  }
  if (optimalScore >= 21) {
    revealed = true;
  }
}

void Player::display() {
  std::cout << "Player " << playerId << ":" << std::endl;
  std::cout << "Visible Card: " << visibleCard.toString() << std::endl;
  std::cout << "Hidden Card: " << hiddenCard.toString() << std::endl;
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

void Player::revealCards() {
  revealed = true;
}

int Player::getOptimalScore() {
  return optimalScore;
}

bool Player::isRevealed() {
  return revealed;
}
