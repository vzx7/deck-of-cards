//
// Created by zx on 1/27/22.
//

#include "headers/CardDeck.h"
#include "headers/constants.h"
#include "Card.h"
#include "headers/utils.h"


CardDeck::CardDeck() {
    // Нужно для рандомизации чисел, чтобы тусовать карты
    srand(static_cast<unsigned int>(time(0)));
    _setDeck();
}

string CardDeck::showCardByNumber(unsigned short number) {
    Card card = deck[number];
    return "Вы вабрали карту: масть - " + _mapBySuit(card.suit) + ", тип - " + _mapByOrder(card.order) + ".\n";
}

void CardDeck::shuffleDeck() {
    Card newDeck[CARD_COUNT];
    unsigned short numbers[CARD_COUNT];
    unsigned short min = 0;
    unsigned short max = CARD_COUNT - 1;
    for (int i = 0; i < CARD_COUNT; i++) {
        unsigned short slot = getRandomNumber(min, max);

        while (_isInArray(slot, numbers)) {
            if (i == 35 && min == 0 && max == 1) {
                slot = 0;
                break;
            } else {
                slot = getRandomNumber(min, max);
            }
        }

        if (min == slot) {
            short nMin = _getMin(slot + 1, numbers);
            min = nMin >= max ? max - 1 : nMin;
        } else if(max == slot) {
            short nMax = _getMax(slot - 1, numbers);
            max = nMax <= min ? min + 1 : nMax;
        }

        numbers[i] = slot;
        newDeck[slot] = deck[i];
    }

    for (int i = 0; i < CARD_COUNT; i++) {
        deck[i] = newDeck[i];
    }
}

void CardDeck::showAllCards() {
    for (int i = 0; i < CARD_COUNT; i++) {
        cout << "Карта №"<< i+1 <<" : " << "масть - " << _mapBySuit(deck[i].suit) << ", тип - " << _mapByOrder(deck[i].order) << ";" << endl;
    }
}

string CardDeck::dealCardBySix() {
    unsigned short count = 6;
    unsigned short i = 0;
    unsigned short arr[count];
    Card cards[count];
    while (i < count) {
        unsigned short n = getRandomNumber(0, CARD_COUNT - 1);
        unsigned short j = 0;

        while (j <= count) {
             if (arr[j] == n) {
                 n = getRandomNumber(0, CARD_COUNT - 1);
                 break;
             }
            j++;
        }

        arr[i] = n;
        cards[i] = deck[n];
        i++;
    }
    string part = "Карты выданы так:\n";
    for (int j = 0; j < count; ++j) {
        int num = (j + 1);
        part += "Карта " + to_string(num)  + "№: " + "Масть - " + _mapBySuit(cards[j].suit) + ", тип - " + _mapByOrder(cards[j].order) + ".\n";
    }

    return part;
}

void CardDeck::_setDeck() {
    unsigned short z = 0;
    for (unsigned short s = 0; s <= 3; s++) {
        for (unsigned short o = 6; o <= 14; o++) {
            Card card = { (Suit) s , (Order) o, };
            deck[z++] = card;
        }
    }
}

short CardDeck::_getMin(short slot, unsigned short (&numbers)[CARD_COUNT]) {
    for (int i = 0; i < CARD_COUNT; ++i) {
        if(_isInArray(slot, numbers)) {
            slot =  _getMin(slot + 1, numbers);
            break;
        }
    }
    return slot;
}

short CardDeck::_getMax(short slot, unsigned short (&numbers)[CARD_COUNT]) {
    for (int i = 0; i < CARD_COUNT; ++i) {
        if(_isInArray(slot, numbers)) {
            slot =  _getMax(slot - 1, numbers);
            break;
        }
    }
    return slot;
}

bool CardDeck::_isInArray(unsigned short slot, unsigned short (&numbers)[CARD_COUNT]) {
    unsigned short i = 0;
    bool isFind = false;
    for (int i = 0; i <= CARD_COUNT; i++) {
        if(numbers[i] == slot) {
            isFind = true;
            break;
        }
    }
    return isFind;
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


