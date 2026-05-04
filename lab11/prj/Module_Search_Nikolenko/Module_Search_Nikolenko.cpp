#include <iostream>
#include <cstring>
#include "Module_Search_Nikolenko.h"

using namespace std;

void printDirectory(PhoneRecord* head) {
    if (head == nullptr) {
        cout << "Довідник порожній. Немає даних для виведення.\n";
        return;
    }

    cout << "\n======================================================\n";
    cout << "          ТЕЛЕФОННИЙ ДОВІДНИК МІСТ УКРАЇНИ            \n";
    cout << "======================================================\n";

    PhoneRecord* current = head;
    int count = 1;

    while (current != nullptr) {
        cout << count << ". Місто: " << current->cityName
             << " \t| Код: " << current->phoneCode << "\n";
        current = current->next;
        count++;
    }
    cout << "======================================================\n";
};

void searchRecord(PhoneRecord* head, const char* searchKey) {
    if (head == nullptr) {
        cout << "Довідник порожній.\n";
        return;
    }

    bool isFound = false;
    PhoneRecord* current = head;

    cout << "\n--- Результати пошуку для запиту: '" << searchKey << "' ---\n";

    while (current != nullptr) {
        if (strcmp(current->cityName, searchKey) == 0 ||
            strcmp(current->phoneCode, searchKey) == 0) {

            cout << "ЗНАЙДЕНО -> Місто: " << current->cityName
                 << "\t| Код: " << current->phoneCode << "\n";
            isFound = true;
            }
        current = current->next;
    }
    if (!isFound) {
        cout << "Записів, що відповідають запиту, не знайдено.\n";
    }
};
