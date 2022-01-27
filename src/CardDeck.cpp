//
// Created by zx on 1/27/22.
//

#include "headers/CardDeck.h"
#include "Card.h"

void CardDeck::_setDeck() {
    for (int s = 1; s < 4; s++) {
        for (int o = 6; o < 14; o++) {
            Card card = { (Suit) s , (Order) o, };
            cout << "Order " << (s - 1) * 9 + (o - 5) << endl; // TODO убрать
            deck[(s - 1) * 9 + (o - 5)] = card;
        }
    }
}

CardDeck::CardDeck() {
    _setDeck();
}

string CardDeck::showCardByOrder(unsigned short order) {
    return "";
}

void CardDeck::sortDeck() {

}

void CardDeck::showAllCards() {}

void CardDeck::dealCardByOne() {}

void CardDeck::dealCardBySix() {}
