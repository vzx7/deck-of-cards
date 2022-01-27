cmake_minimum_required(VERSION 3.21)
project(deck_of_card)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/headers)

add_executable(deck_of_card
        src/headers/Card.h
        src/CardDeck.cpp
        src/main.cpp)


