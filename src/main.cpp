//
// Created by zx on 1/27/22.
//

#include "Card.h"
#include "CardDeck.h"

int main(int argc, const char *argv[]) {
    unsigned int count;
    CardDeck *cardDeck;
    Card *deck = cardDeck->deck;

    cout << "Колода состоит из 36 карт." << endl;
    cout << "Сейчас они находятся в следующем порядке:" << endl;
    cardDeck->showAllCards();

    cout << "Введите число от 6 до 14." << endl;
    unsigned short order;
    cin >> order;
    if (order < 15 && order > 5) {
        cardDeck->showCardByOrder(order);
    }
    cout << "Давайте теперь отсортируем колоду." << endl;
    cardDeck->sortDeck();

    cout << "И покажем новый порядок..." << endl;
    cardDeck->showAllCards();

    cout << "Раздадим по одной карте..." << endl;
    cardDeck->dealCardByOne();

    cout << "А теперь раздадим по 6..." << endl;
    cardDeck->dealCardBySix();

    cout << "Мы показали вам то, что умеем." << endl;
    cout << "Спасибо )" << endl;

    return 0;
}