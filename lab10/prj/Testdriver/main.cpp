#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>

#include "ModulesHrytsiuk.h"

using namespace std;

string readFileContent(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return "";
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

void logResult(ofstream& protocol, const string& tc_id, const string& input_args, bool passed) {
    string status = passed ? "[PASSED]" : "[FAILED]";

    cout << left << setw(12) << tc_id << " | " << setw(20) << input_args << " | " << status << endl;

    protocol << left << setw(12) << tc_id << " | " << setw(20) << input_args << " | " << status << "\n";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    ofstream protocol("test_protocol.txt", ios::out | ios::trunc);
    if (!protocol.is_open()) {
        cout << "Ïîìèëêà: íå âäàëîñÿ ñòâîðèòè ôàéë ïðîòîêîëó!" << endl;
        return 1;
    }

    protocol << "=== ÏÐÎÒÎÊÎË ÀÂÒÎÌÀÒÈÇÎÂÀÍÎÃÎ ÒÅÑÒÓÂÀÍÍß (ËÐ 10) ===\n";
    protocol << "Ðîçðîáíèê: Ãðèöþê ªâãåí³é, ÊÍ-25\n\n";

    cout << "ÇÀÏÓÑÊ ÀÂÒÎÌÀÒÈÇÎÂÀÍÈÕ ÒÅÑÒ²Â...\n";
    cout << string(50, '-') << endl;

    protocol << "--- Çàäà÷à 10.1 ---\n";
    cout << "--- Çàäà÷à 10.1 ---\n";

    struct TC10_1 { string id, in_f, out_f, text, expected; };
    const TC10_1 tests10_1[] = {
        {"TC-10.1-01", "in_1.txt", "out_1.txt", "Ïðèâ³ò, ñâ³ò!", "Ïðèâ³<?>, ñâ³<?>!"},
        {"TC-10.1-02", "in_2.txt", "out_2.txt", "Óñï³õ", "<?>ñï³õ"}
    };

    for (const auto& tc : tests10_1) {
        ofstream in_file(tc.in_f);
        in_file << tc.text;
        in_file.close();

        task10_1_file_write(tc.in_f, tc.out_f);

        string result_content = readFileContent(tc.out_f);
        bool passed = (result_content.find(tc.expected) != string::npos);

        logResult(protocol, tc.id, "File: " + tc.in_f, passed);
    }

    protocol << "\n--- Çàäà÷à 10.2 ---\n";
    cout << "\n--- Çàäà÷à 10.2 ---\n";

    struct TC10_2 { string id, in_f, out_f, text, expected; };
    const TC10_2 tests10_2[] = {
        {"TC-10.2-01", "in_3.txt", "out_3.txt", "ÀÁÂÃÄ", "ÀÂÄ"},
        {"TC-10.2-02", "in_4.txt", "out_4.txt", "123456", "135"}
    };

    for (const auto& tc : tests10_2) {
        ofstream in_file(tc.in_f);
        in_file << tc.text;
        in_file.close();

        task10_2_file_append(tc.in_f, tc.out_f);

        string result_content = readFileContent(tc.out_f);
        bool passed = (result_content.find(tc.expected) != string::npos);

        logResult(protocol, tc.id, "File: " + tc.in_f, passed);
    }

    protocol << "\n--- Çàäà÷à 10.3 ---\n";
    cout << "\n--- Çàäà÷à 10.3 ---\n";

    struct TC10_3 { string id, out_f; double x, y, z; int b; string exp_bin; };
    const TC10_3 tests10_3[] = {
        {"TC-10.3-01", "out_5.txt", 1.0, 2.0, 3.0, 5, "101"},
        {"TC-10.3-02", "out_5.txt", 0.0, 0.0, 0.0, 10, "1010"}
    };

    ofstream clean_out("out_5.txt", ios::trunc); clean_out.close();

    for (const auto& tc : tests10_3) {
        task10_3_math_append(tc.out_f, tc.x, tc.y, tc.z, tc.b);

        string result_content = readFileContent(tc.out_f);
        bool passed = (result_content.find(tc.exp_bin) != string::npos);

        string args = "x,y,z | b=" + to_string(tc.b);
        logResult(protocol, tc.id, args, passed);
    }

    protocol.close();
    cout << string(50, '-') << endl;
    cout << "Òåñòóâàííÿ çàâåðøåíî. Ðåçóëüòàòè çàïèñàíî ó ôàéë test_protocol.txt\n";

    system("pause");
    return 0;
}
