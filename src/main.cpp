//
// Created by zx on 1/27/22.
//

#include "CardDeck.h"
#include "headers/constants.h"
#include "headers/utils.h"


/**
 * Приглашение вытянуть карту
 * @param cardDeck
 */
void enterNumber(CardDeck cardDeck) {
    cout << "Введите число от 1 до " << CARD_COUNT << "." << endl;
    unsigned short num;
    cin >> num;
    num--;
    if (num < CARD_COUNT && num >= 0) {
        cout << cardDeck.showCardByNumber(num) << endl;
    } else {
        cout << "Вы ввели некорректное число!.." << endl;
        enterNumber(cardDeck);
    }
}

int main(int argc, const char *argv[]) {

    // Получим классы колоды
    CardDeck *cardDeck = new CardDeck();
    cout << "\n\nИтак, колода состоит из "<< CARD_COUNT << " карт." << endl;

    // Проодолжим
    enterContinue("\nНажмите ENTER и мы покажем что мы можем ;)\n");

    // Покажем колоду
    cout << "Сейчас они находятся в следующем порядке:" << endl;
    cardDeck->showAllCards();

    // Проодолжим
    enterContinue();

    // Вытащить карту
    enterNumber(*cardDeck);

    // Тусанем
    cout << "Давайте теперь перетасуем колоду..." << endl;

    // Проодолжим
    enterContinue();
    cardDeck->shuffleDeck();

    cout << "\nВыдадим все карты по одной..." << endl;

    // Проодолжим
    enterContinue();
    cardDeck->showAllCards();

    // Проодолжим
    enterContinue();
    cout << "\nА теперь вытяните еще раз карту..." << endl;
    enterNumber(*cardDeck);

    // Продолжим
    enterContinue();
    cout << "А теперь раздадим по 6..." << endl;
    cout << cardDeck->dealCardBySix() << endl;
    cout << "Мы показали вам то, что умеем." << endl;
    cout << "Спасибо )" << endl;

    return 0;
}

