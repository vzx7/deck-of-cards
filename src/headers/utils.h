//
// Created by zx on 1/27/22.
//

#ifndef DECK_OF_CARD_UTILS_H
#define DECK_OF_CARD_UTILS_H
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;
/**
 * Получить рандомное число в диапозоне
 * @param min
 * @param max
 * @return
 */
int getRandomNumber(int min, int max);

/**
 * Отловить символ ENTER и выйт
 * @param msg сообщение, которое выведется перед этим
 */
void enterContinue(string msg = "\nНажмите ENTER, чтобы продолжить...\n");


#endif //DECK_OF_CARD_UTILS_H
