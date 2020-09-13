#include <iostream>
#include <random>
#include <chrono>
#include <functional>
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "Deck.h"

int main() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator (seed);
  std::uniform_int_distribution<int> distribution(0,12);
  auto rng = std::bind(distribution, generator);

  Deck playingCards;
  Card cardOne = playingCards.remove(rng() % 4, rng());
  Card cardTwo = playingCards.remove(rng() % 4, rng());
  while (cardTwo.getSuit() == 0 && cardTwo.getRank() == 0) {
    cardTwo = playingCards.remove(rng() % 4, rng());
  }
  Card cardThree = playingCards.remove(rng() % 4, rng());
  while (cardThree.getSuit() == 0 && cardThree.getRank() == 0) {
    cardThree = playingCards.remove(rng() % 4, rng());
  }
  Card cardFour = playingCards.remove(rng() % 4, rng());
  while (cardFour.getSuit() == 0 && cardFour.getRank() == 0) {
    cardFour = playingCards.remove(rng() % 4, rng());
  }
  HumanPlayer playerOne(1, cardOne, cardTwo);
  AIPlayer playerTwo(2, cardThree, cardFour);

  while (!playerOne.isRevealed() || !playerTwo.isRevealed()) {
    playerOne.display();
    std::cout << std::endl;
    if (!playerOne.isRevealed()) {
      if (playerOne.optionSelect() == 'A') {
        Card newCard = playingCards.remove(rng() % 4, rng());
        while (newCard.getRank() == 0 && newCard.getSuit() == 0) {
          newCard = playingCards.remove(rng() % 4, rng());
        }
        playerOne.addCard(newCard);
      }
      else {
        playerOne.revealCards();
      }
    }
    std::cout << std::endl;
    playerTwo.display();
    std::cout << std::endl;
    if (!playerTwo.isRevealed()) {
      if (playerTwo.optionSelect() == 'A') {
        Card newCard = playingCards.remove(rng() % 4, rng());
        while (newCard.getRank() == 0 && newCard.getSuit() == 0) {
          newCard = playingCards.remove(rng() % 4, rng());
        }
        playerTwo.addCard(newCard);
      }
      else {
        playerTwo.revealCards();
      }
    }
    std::cout << std::endl;
  }

  playerOne.display();
  std::cout << std::endl;
  playerTwo.display();
  std::cout << std::endl;
  if (playerOne.getOptimalScore() > 21 && playerTwo.getOptimalScore() > 21) {
    std::cout << "Tie Game!" << std::endl;
  }
  else if (playerOne.getOptimalScore() > 21) {
    std::cout << "Player 2 Wins!" << std::endl;
  }
  else if (playerTwo.getOptimalScore() > 21) {
    std::cout << "Player 1 Wins!" << std::endl;
  }
  else if (playerOne.getOptimalScore() > playerTwo.getOptimalScore()) {
    std::cout << "Player 1 Wins!" << std::endl;
  }
  else if (playerOne.getOptimalScore() < playerTwo.getOptimalScore()) {
    std::cout << "Player 2 Wins!" << std::endl;
  }
  else {
    std::cout << "Tie Game!" << std::endl;
  }
  return 0;
}
