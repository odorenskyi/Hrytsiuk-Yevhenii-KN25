#include <iostream>
#include <windows.h>

#include "struct_type_project_2.h"

#include "Module_Files_Honcharenko.h"
#include "Module_Editing_Hrytsiuk.h"
#include "Module_Search_Nikolenko.h"

using namespace std;

int main() {


    PhoneRecord* head = nullptr;
    PhoneRecord* tail = nullptr;

    const char* filename = "directory.bin";

    cout << "=== СТАРТ ПРОГРАМИ ===\n";

    loadFromFile(filename, head, tail);

    int choice;
    char inputCity[MAX_CITY_LEN];
    char inputCode[MAX_CODE_LEN];
    char searchBuffer[MAX_CITY_LEN];

    do {
        cout << "\n======================================================\n";
        cout << "  ЕЛЕКТРОННИЙ ДОВІДНИК ТЕЛЕФОННИХ КОДІВ МІСТ УКРАЇНИ  \n";
        cout << "======================================================\n";
        cout << "1. Додати новий запис \n";
        cout << "2. Вилучити запис \n";
        cout << "3. Вивести довідник на екран \n";
        cout << "4. Пошук за містом або кодом \n";
        cout << "5. Зберегти у файл \n";
        cout << "0. Вийти з програми\n";
        cout << "------------------------------------------------------\n";
        cout << "Ваш вибір: ";
        cin >> choice;


        cin.ignore();

        switch(choice) {
            case 1:
                cout << "\n--- ДОДАВАННЯ ЗАПИСУ ---\n";
                cout << "Введіть назву міста: ";
                cin.getline(inputCity, MAX_CITY_LEN);
                cout << "Введіть телефонний код: ";
                cin.getline(inputCode, MAX_CODE_LEN);

                addRecord(head, tail, inputCity, inputCode);
                break;

            case 2:
                cout << "\n--- ВИЛУЧЕННЯ ЗАПИСУ ---\n";
                cout << "Введіть назву міста, яке потрібно вилучити: ";
                cin.getline(inputCity, MAX_CITY_LEN);

                deleteRecord(head, tail, inputCity);
                break;

            case 3:

                printDirectory(head);
                break;

            case 4:
                cout << "\n--- ПОШУК ---\n";
                cout << "Введіть назву міста або код для пошуку: ";
                cin.getline(searchBuffer, MAX_CITY_LEN);

                searchRecord(head, searchBuffer);
                break;

            case 5:
                cout << "\n--- ЗБЕРЕЖЕННЯ ---\n";

                saveToFile(filename, head);
                break;

            case 0:
                cout << "\nЗавершення роботи. Автоматичне збереження даних...\n";
                saveToFile(filename, head);

                while (head != nullptr) {
                    PhoneRecord* temp = head;
                    head = head->next;
                    delete temp;
                }
                cout << "Пам'ять очищено. До побачення!\n";
                break;

            default:
                cout << "Невірний вибір. Спробуйте ще раз (введіть цифру від 0 до 5).\n";
        }
    } while (choice != 0);

    return 0;
}
