cmake_minimum_required(VERSION 3.6)
project(BlackJack)

set(CMAKE_CXX_STANDARD 14)

add_executable(BlackJack main.cpp Card.cpp Card.h Deck.cpp Deck.h
        Player.cpp Player.h HumanPlayer.cpp HumanPlayer.h AIPlayer.cpp AIPlayer.h)