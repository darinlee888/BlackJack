//
// Created by Darin Lee on 12/29/2019.
//

#ifndef BLACKJACK_AIPLAYER_H
#define BLACKJACK_AIPLAYER_H

#include "Player.h"

class AIPlayer : public Player {
 public:
  AIPlayer(int id, Card visible, Card hidden);
  char optionSelect() override;
  void display() override;

};

#endif //BLACKJACK_AIPLAYER_H
