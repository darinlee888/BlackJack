//
// Created by Darin Lee on 12/29/2019.
//

#ifndef BLACKJACK_HUMANPLAYER_H
#define BLACKJACK_HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
 public:
  HumanPlayer(int id, Card visible, Card hidden);
  char optionSelect() override;

};

#endif //BLACKJACK_HUMANPLAYER_H
