#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <windows.h>
#include "ModulesHrytsiuk.h"

using namespace std;

void runTestSuite(const string& testFile, const string& resultFile) {
    ifstream inFile(testFile);
    ofstream outFile(resultFile, ios::app);

    if (!inFile.is_open()) {
        outFile << "Помилка: не вдалося відкрити файл з тест-кейсами: " << testFile << "\n";
        return;
    }

    outFile << "========================================\n";
    outFile << "Результати модульного тестування (Teacher)\n";
    outFile << "========================================\n";

    string id, action;
    double input_val, expected_val;

    while (inFile >> id >> action >> input_val >> expected_val) {
        outFile << "Тест " << id << " [" << action << "]: ";

        ClassLab12_Hrytsiuk ball;
        bool passed = false;
        double actual_val = 0.0;

        if (action == "INIT") {
            ClassLab12_Hrytsiuk tempBall(input_val);
            actual_val = tempBall.getRadius();
            passed = (abs(actual_val - expected_val) < 0.001);
        }
        else if (action == "SET") {
            ball.setRadius(input_val);
            actual_val = ball.getRadius();
            passed = (abs(actual_val - expected_val) < 0.001);
        }
        else if (action == "VOL") {
            ball.setRadius(input_val);
            actual_val = ball.calculateVolume();
            passed = (abs(actual_val - expected_val) < 0.01);
        }

        if (passed) {
            outFile << "PASSED (Очікувано: " << expected_val << ", Отримано: " << actual_val << ")\n";
        } else {
            outFile << "FAILED (Очікувано: " << expected_val << ", Отримано: " << actual_val << ")\n";
        }
    }

    inFile.close();
    outFile.close();
}

int main() {
    SetConsoleOutputCP(1251);

    string currentFile = __FILE__;
    string expectedPath = "\\lab12\\prj";

    ofstream resultFile("TestResults.txt");

    if (currentFile.find(expectedPath) == string::npos) {
        resultFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!\n";
        resultFile.close();

        cout << "Помилка: Проєкт знаходиться у неправильній директорії!" << endl;
        cout << "Шлях компіляції: " << currentFile << endl;
        cout << "Видаю 100 звукових сигналів..." << endl;

        for (int i = 0; i < 100; ++i) {
            Beep(750, 50);
            Sleep(20);
        }
        return 1;
    }

    resultFile << "Перевірка директорії: PASSED (Проєкт у правильній теці " << expectedPath << ")\n";
    resultFile.close();

    cout << "Перевірка шляху успішна. Запуск тестування..." << endl;

    string testFilePath = "..\\..\\TestSuite\\tests.txt";
    string resultFilePath = "TestResults.txt";

    runTestSuite(testFilePath, resultFilePath);

    cout << "Тестування завершено. Результати успішно записано у файл TestResults.txt" << endl;

    return 0;
}
