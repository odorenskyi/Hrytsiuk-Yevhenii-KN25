#include <iostream>
#include <iomanip>
#include <cmath>
#include "ModulesHrytsiuk.h"

using namespace std;

void runTestCase(int tc_id, double x, double y, double z, double expected) {
    double actual;

    try {
        actual = s_calculation(x, y, z);
    } catch (...) {
        actual = NAN;
    }

    cout << "TC-" << tc_id << " | x=" << x << ", y=" << y << ", z=" << z << endl;
    cout << "Очiкувано: " << expected << " | Фактично: " << actual << " | Статус: ";

    if (isnan(expected) && isnan(actual)) {
        cout << "passed" << endl;
    }
    else if (abs(actual - expected) < 0.01) {
        cout << "passed" << endl;
    }
    else {
        cout << "failed" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "");

    cout << "Протокол модульного тестування функцiї s_calculation" << endl;
    cout << "----------------------------------------------------" << endl;

    runTestCase(1, 0.0, 0.0, 0.0, 0.0000);
    runTestCase(2, 1.0, 1.0, 3.0, 18.7168);
    runTestCase(3, -2.5, 4.5, 1.2, 6.2662);
    runTestCase(4, 10.0, -20.0, 12.0, -8.5664);
    runTestCase(5, 5.0, 5.0, -1.0, NAN);

    cout << endl;
    system("pause");
    return 0;
}
