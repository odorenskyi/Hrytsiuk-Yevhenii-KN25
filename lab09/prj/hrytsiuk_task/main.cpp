#include <iostream>
#include <string>
#include <Windows.h>


#include "ModulesHrytsiuk.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char menu_choice;
    char exit_choice;

    while (true) {
        cout << "\n================ ГОЛОВНЕ МЕНЮ ================\n";
        cout << "s - Обчислення функції s_calculation\n";
        cout << "f - Задача 9.1 (Обчислення знижки)\n";
        cout << "g - Задача 9.2 (Конвертер розмірів білизни)\n";
        cout << "h - Задача 9.3 (Бітовий аналізатор)\n";
        cout << "==============================================\n";
        cout << "Оберіть дію: ";
        cin >> menu_choice;

        switch (menu_choice) {
            case 's': {
                double x, y, z;
                cout << "Введіть значення x, y, z (через пробіл): ";
                cin >> x >> y >> z;
                try {
                    double result = s_calculation(x, y, z);
                    cout << "Результат s_calculation: " << result << endl;
                } catch (const exception& e) {
                    cout << "Помилка: " << e.what() << endl;
                }
                break;
            }
            case 'f': {
                double amount, d_uah = 0, f_amt = 0;
                cout << "Введіть суму покупки (грн): ";
                cin >> amount;
                int percent = task9_1_discount(amount, d_uah, f_amt);
                if (percent == 0 && amount < 0) {
                    cout << "Помилка: Сума не може бути від'ємною!\n";
                } else {
                    cout << "Відсоток знижки: " << percent << "%\n";
                    cout << "Сума знижки: " << d_uah << " грн\n";
                    cout << "Сума до сплати: " << f_amt << " грн\n";
                }
                break;
            }
            case 'g': {
                int size;
                cout << "Введіть український розмір чоловічої білизни: ";
                cin >> size;
                string result = task9_2_size_converter(size);
                cout << "Результат: " << result << endl;
                break;
            }
            case 'h': {
                int n;
                cout << "Введіть натуральне число N (від 0 до 190550): ";
                cin >> n;
                int count = task9_3_bit_counter(n);
                cout << "Результат підрахунку бітів: " << count << endl;
                break;
            }
            default:
                cout << "\a";
                cout << "Помилка: Невідома команда! Символ зігноровано.\n";
                break;
        }

        cout << "\nБажаєте завершити роботу? (Введіть J або j для виходу, будь-який інший символ для продовження): ";
        cin >> exit_choice;

        if (exit_choice == 'J' || exit_choice == 'j') {
            cout << "Завершення роботи програми..." << endl;
            break;
        }
    }

    return 0;
}
