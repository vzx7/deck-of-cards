//
// Created by zx on 1/27/22.
//

#ifndef DECK_OF_CARD_CARDDECK_H
#define DECK_OF_CARD_CARDDECK_H
#include <iostream>
#include <string>
#include "Card.h"
#include "constants.h"

using namespace std;

class CardDeck {
private:
    /**
     * Настроить колоду
     */
    void _setDeck();

    /**
     * Смапить масть
     * @param suit
     * @return
     */
    string _mapBySuit(Suit suit);

    /**
     * Смапить тип карты
     * @param order
     * @return
     */
    string _mapByOrder(Order order);

    /**
     * Метод проверка нахождения индекса слота в перечне
     * @param slot
     * @param numbers
     * @return
     */
    bool _isInArray(unsigned short slot,  unsigned short (&numbers)[CARD_COUNT]);

    /**
     * Вернуть минимальное ограничение для выполнения рандомного подбора числа
     * @param slot
     * @param numbers
     * @return
     */
    short _getMin(short slot,  unsigned short (&numbers)[CARD_COUNT]);

    /**
     * Вернуть максимальное ограничение для выполнения рандомного подбора числа
     * @param slot
     * @param numbers
     * @return
     */
    short _getMax(short slot,  unsigned short (&numbers)[CARD_COUNT]);
public:
    /**
     * колода
     */
    Card deck[CARD_COUNT];
    CardDeck();

    /**
     * Перетасовать колоду
     */
    void shuffleDeck();

    /**
     * Показать карту по номеру
     * @param number
     * @return
     */
    string showCardByNumber(unsigned short number);

    /**
     * Показать всю колоду
     */
    void showAllCards();

    /**
     * Раздать по 6
     * @return
     */
    string dealCardBySix();

};
#endif //DECK_OF_CARD_CARDDECK_H
