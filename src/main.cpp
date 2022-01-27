//
// Created by zx on 1/27/22.
//
#include <typeinfo>
#include "Card.h"
#include "CardDeck.h"
#include "headers/constants.h"

int main(int argc, const char *argv[]) {
    unsigned int count;
    CardDeck *cardDeck = new CardDeck();
    Card *deck = cardDeck->deck;

    cout << "Колода состоит из "<< CARD_COUNT << " карт." << endl;
    cout << "Сейчас они находятся в следующем порядке:" << endl;
    cardDeck->showAllCards();

    cout << "\nВведите число от 0 до " << CARD_COUNT << "." << endl;
    unsigned short num;
    cin >> num;

    if (num <= CARD_COUNT && num >= 0) {
        cout << cardDeck->showCardByOrder(num) << endl;
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