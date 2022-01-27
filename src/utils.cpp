//
// Created by zx on 1/27/22.
//

#include "headers/utils.h"

int getRandomNumber(int min, int max) {
    srand(static_cast<unsigned int>(time(0)));
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void enterContinue(string msg) {
    string b;
    cout << msg << endl;
    getline(cin, b);
    if (b == "") {
        return;
    } else {
        cout << "Разве \"" << b << "\" похожа на ENTER?..." << endl;
        enterContinue();
    }
}