//
// Created by Darin Lee on 12/29/2019.
//

#include "HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(int id, Card visible, Card hidden) : Player(id, visible, hidden) {}

char HumanPlayer::optionSelect() {
  std::cout << "Would you like to add more cards or reveal your cards?" << std::endl;
  std::cout << "[A]dd or [R]eveal" << std::endl;
  char choice;
  std::cin >> choice;
  while (choice != 'A' && choice != 'R') {
    std::cout << "Try again. [A]dd or [R]eveal" << std::endl;
  }
  return choice;
}
