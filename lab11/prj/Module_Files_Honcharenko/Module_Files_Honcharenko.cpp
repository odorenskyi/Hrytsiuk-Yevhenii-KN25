#include <iostream>
#include <cstdio>
#include <cstring>
#include "Module_Files_Honcharenko.h"

using namespace std;

void saveToFile(const char* filename, PhoneRecord* head) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        cout << "Помилка: не вдалося відкрити файл для запису!\n";
        return;
    }

    PhoneRecord* current = head;
    int count = 0;

    while (current != nullptr) {
        fwrite(current->cityName, sizeof(char), MAX_CITY_LEN, file);
        fwrite(current->phoneCode, sizeof(char), MAX_CODE_LEN, file);
        current = current->next;
        count++;
    }
    fclose(file);
    cout << "Успішно збережено " << count << " записів у файл бази даних.\n";
}

void loadFromFile(const char* filename, PhoneRecord*& head, PhoneRecord*& tail) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        cout << "Базу даних не знайдено. Створено новий порожній довідник.\n";
        return;
    }

    char tempCity[MAX_CITY_LEN];
    char tempCode[MAX_CODE_LEN];
    int count = 0;

    while (fread(tempCity, sizeof(char), MAX_CITY_LEN, file) == MAX_CITY_LEN) {
        fread(tempCode, sizeof(char), MAX_CODE_LEN, file);

        PhoneRecord* newNode = new PhoneRecord;
        strcpy(newNode->cityName, tempCity);
        strcpy(newNode->phoneCode, tempCode);
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        count++;
    }
    fclose(file);
    cout << "Успішно завантажено " << count << " записів з бази даних.\n";
}
