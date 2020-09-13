//
// Created by Darin Lee on 12/26/2019.
//

#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "Card.h"
#include <vector>

class Player {
 public:
  Player(int id, Card visible, Card hidden);
  int getId();
  Card getVisibleCard();
  Card getHiddenCard();
  int getOptimalScore();
  bool isRevealed();
  void addCard(Card newCard);
  void revealCards();
  virtual char optionSelect() = 0;
  virtual void display();

 protected:
  int pointValue(Card notAce);
  void updateScores();
  int playerId;
  Card visibleCard;
  Card hiddenCard;
  std::vector<Card> extraCards;
  int optimalScore;
  std::vector<int> possibleScores;
  bool revealed;

};

#endif //BLACKJACK_PLAYER_H
