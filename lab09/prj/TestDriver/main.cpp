#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>

#include "ModulesHrytsiuk.h"

using namespace std;

double my_abs(double val) {
    return val < 0.0 ? -val : val;
}

void print_test_result(string test_name, bool passed) {
    cout << left << setw(15) << test_name << ": ";
    if (passed) {
        cout << "[PASS]" << endl;
    } else {
        cout << "[FAILED]" << endl;
    }
}

void run_task9_1_tests() {
    cout << "--- Тестування задачі 9.1 (Знижки) ---" << endl;
    double d_uah, f_amt;
    int percent;

    percent = task9_1_discount(50.0, d_uah, f_amt);
    print_test_result("TC-01", (percent == 5 && my_abs(d_uah - 2.5) < 0.01 && my_abs(f_amt - 47.5) < 0.01));

    percent = task9_1_discount(100.0, d_uah, f_amt);
    print_test_result("TC-02", (percent == 7 && my_abs(d_uah - 7.0) < 0.01 && my_abs(f_amt - 93.0) < 0.01));

    percent = task9_1_discount(350.0, d_uah, f_amt);
    print_test_result("TC-03", (percent == 12 && my_abs(d_uah - 42.0) < 0.01 && my_abs(f_amt - 308.0) < 0.01));
    cout << endl;
}

void run_task9_2_tests() {
    cout << "--- Тестування задачі 9.2 (Розміри) ---" << endl;

    string res1 = task9_2_size_converter(46);
    print_test_result("TC-01", (res1 == "Міжнародний: M, UK: 36, Франція: 3"));

    string res2 = task9_2_size_converter(45);
    print_test_result("TC-02", (res2 == "Розмір не знайдено"));

    string res3 = task9_2_size_converter(54);
    print_test_result("TC-03", (res3 == "Міжнародний: XXXL, UK: 44, Франція: -"));
    cout << endl;
}

void run_task9_3_tests() {
    cout << "--- Тестування задачі 9.3 (Біти) ---" << endl;

    print_test_result("TC-01", (task9_3_bit_counter(11) == 1));
    print_test_result("TC-02", (task9_3_bit_counter(5) == 2));
    print_test_result("TC-03", (task9_3_bit_counter(8) == 3));
    cout << endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "ЗАПУСК МОДУЛЬНИХ ТЕСТІВ (UNIT TESTS)\n" << string(40, '=') << "\n\n";

    run_task9_1_tests();
    run_task9_2_tests();
    run_task9_3_tests();

    cout << string(40, '=') << "\nТестування завершено.\n";

    system("pause");
    return 0;
}
