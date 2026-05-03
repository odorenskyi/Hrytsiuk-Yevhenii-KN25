#include <iostream>
#include <cstring>
#include "Module_Editing_Hrytsiuk.h"

using namespace std;

void addRecord(PhoneRecord*& head, PhoneRecord*& tail, const char* city, const char* code) {
    PhoneRecord* newNode = new PhoneRecord;
    strcpy(newNode->cityName, city);
    strcpy(newNode->phoneCode, code);

    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;

    cout << "Запис [" << city << " - " << code << "] успішно додано!\n";
}

void deleteRecord(PhoneRecord*& head, PhoneRecord*& tail, const char* city) {
    if (head == nullptr) {
        cout << "Довідник порожній. Немає що видаляти.\n";
        return;
    }

    PhoneRecord* current = head;

    while (current != nullptr) {
        if (strcmp(current->cityName, city) == 0) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }

            delete current;
            cout << "Запис [" << city << "] успішно вилучено з довідника.\n";
            return;
        }
        current = current->next;
    }
    cout << "Місто [" << city << "] не знайдено у довіднику.\n";
}
