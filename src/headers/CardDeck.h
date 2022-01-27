//
// Created by zx on 1/27/22.
//

#ifndef DECK_OF_CARD_CARDDECK_H
#define DECK_OF_CARD_CARDDECK_H
#include <iostream>
#include <string>
#include "Card.h"

using namespace std;
class CardDeck {
private:
    void _setDeck();
public:
    Card deck[37];
    CardDeck();
    void sortDeck();
    string showCardByOrder(unsigned short order);
    void showAllCards();
    void dealCardByOne();
    void dealCardBySix();

};
#endif //DECK_OF_CARD_CARDDECK_H
