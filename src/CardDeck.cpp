//
// Created by zx on 1/27/22.
//

#include "headers/CardDeck.h"
#include "headers/constants.h"
#include "Card.h"

void CardDeck::_setDeck() {
    unsigned short z = 0;
    for (unsigned short s = 0; s <= 3; s++) {
        for (unsigned short o = 6; o <= 14; o++) {
            Card card = { (Suit) s , (Order) o, };
            deck[z++] = card;
        }
    }
}

CardDeck::CardDeck() {
    _setDeck();
}

string CardDeck::showCardByOrder(unsigned short order) {
    return _showCard(order);
}

void CardDeck::sortDeck() {

}

void CardDeck::showAllCards() {
    for (int i = 0; i < CARD_COUNT; i++) {
        cout << "Карта №"<< i+1 <<" : " << "масть - " << _mapBySuit(deck[i].suit) << ", тип - " << _mapByOrder(deck[i].order) << ";" << endl;
    }
}

void CardDeck::dealCardByOne() {}

void CardDeck::dealCardBySix() {}

string CardDeck::_showCard(unsigned short number) {
    Card card = deck[number];
    return "Вы вабрали карту: масть - " + _mapBySuit(card.suit) + ", тип - " + _mapByOrder(card.order) + ".\n";
}

string CardDeck::_mapByOrder(Order order) {
    switch (order) {
        case JACK:
            return "Валет";
            break;
        case LADY:
            return "Дама";
            break;
        case KING:
            return "Король";
            break;
        case ACE:
            return "Туз";
            break;
        default:
            return to_string(order);
            break;
    }
}

string CardDeck::_mapBySuit(Suit suit) {
    string suitStr;
    switch (suit) {
        case HEART:
            suitStr = "Черви";
            break;
        case DIAMOND:
            suitStr = "Буби";
            break;
        case CROSS:
            suitStr = "Крести";
            break;
        case SPADE:
            suitStr = "Пики";
            break;
    };
    return suitStr;
};
