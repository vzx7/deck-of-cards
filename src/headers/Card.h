//
// Created by zx on 1/27/22.
//

#ifndef DECK_OF_CARD_CARD_H
#define DECK_OF_CARD_CARD_H


#include "Suit.h"
#include "Order.h"

struct Card {
    Suit suit;
    Order order;
};

#endif //DECK_OF_CARD_CARD_H
