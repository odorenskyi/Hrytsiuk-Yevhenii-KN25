#include <cmath>
#include <stdexcept>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>

constexpr double PI = 3.14159265358979323846;

double s_calculation(double x, double y, double z) {
    if (z < 0.0) {
        throw std::invalid_argument("z не може бути від'ємним");
    }
    double term1 = pow(x + y + z, 2.0);
    double term2 = 2.0 * PI * sqrt(z / 3.0);
    return term1 - term2;
}

int task9_1_discount(double purchase_amount, double &discount_uah, double &final_amount) {
    if (purchase_amount < 0) {
        discount_uah = 0;
        final_amount = 0;
        return 0;
    }

    int percent = 0;
    if (purchase_amount < 100) {
        percent = 5;
    } else if (purchase_amount < 200) {
        percent = 7;
    } else if (purchase_amount < 300) {
        percent = 9;
    } else if (purchase_amount < 400) {
        percent = 12;
    } else if (purchase_amount < 500) {
        percent = 15;
    } else if (purchase_amount <= 1000) {
        percent = 20;
    } else {
        percent = 25;
    }

    discount_uah = (purchase_amount * percent) / 100.0;
    final_amount = purchase_amount - discount_uah;

    return percent;
}


std::string task9_2_size_converter(int ukr_size) {
    switch (ukr_size) {
        case 44: return "Міжнародний: S, UK: 34, Франція: 2";
        case 46: return "Міжнародний: M, UK: 36, Франція: 3";
        case 48: return "Міжнародний: L, UK: 38, Франція: 4";
        case 50: return "Міжнародний: XL, UK: 40, Франція: 5";
        case 52: return "Міжнародний: XXL, UK: 42, Франція: 6";
        case 54: return "Міжнародний: XXXL, UK: 44, Франція: -";
        default: return "Розмір не знайдено";
    }
}


int task9_3_bit_counter(int N) {
    if (N < 0) return 0;

    bool d3_is_one = (N & (1 << 3)) != 0;

    int count = 0;
    int temp = N;

    while (temp > 0) {
        int current_bit = temp & 1;

        count += d3_is_one ? (current_bit == 0 ? 1 : 0) : (current_bit == 1 ? 1 : 0);

        temp >>= 1;
    }

    return count;
}

void task10_1_file_write(const std::string& in_filename, const std::string& out_filename) {
    using namespace std;

    ifstream in_file(in_filename);
    if (!in_file.is_open()) return;

    string sentence;
    getline(in_file, sentence);
    in_file.close();

    string modified_sentence = sentence;
    string targets[] = {"к", "т", "У", "л", "Й"};
    for (const string& target : targets) {
        size_t pos = 0;
        while ((pos = modified_sentence.find(target, pos)) != string::npos) {
            modified_sentence.replace(pos, target.length(), "<?>");
            pos += 3;
        }
    }

    int letter_count = 0;
    for (char c : sentence) {
        if (c != ' ' && c != '.' && c != ',' && c != '!' && c != '?' && c != '-' && c != ';' && c != ':') {
            letter_count++;
        }
    }

    ofstream out_file(out_filename, ios::out | ios::trunc);
    if (!out_file.is_open()) return;

    out_file << "Розробник: Грицюк Євгеній, КН-25\n";
    out_file << "Установа: ЦНТУ, м. Кропивницький, Україна, 2026 рік\n\n";
    out_file << modified_sentence << "\n\n";

    if (letter_count % 2 == 0) {
        out_file << "В хаті сонячній промінь косо\nНа долівку ляга з вікна...\n";
        out_file << "Твої чорні шовкові коси\nПрипорошила вже сивина.\n";
    } else {
        out_file << "Коли малим ти вперше став на ноги -\nЯка ж то радість матері була!\n";
        out_file << "Від тихої колиски до порога\nВона тебе за руку провела.\n";
    }

    out_file.close();
}

void task10_2_file_append(const std::string& in_filename, const std::string& out_filename) {
    using namespace std;

    ifstream in_file(in_filename);
    if (!in_file.is_open()) return;

    string sentence;
    getline(in_file, sentence);
    in_file.close();

    ofstream out_file(out_filename, ios::app);
    if (!out_file.is_open()) return;

    out_file << "\n--- Задача 10.2 ---\n";
    out_file << "Непарні символи речення: ";

    for (size_t i = 0; i < sentence.length(); i += 2) {
        out_file << sentence[i];
    }
    out_file << "\n";

    time_t now = time(0);
    string time_str = ctime(&now);
    out_file << "Дата й час дозапису: " << time_str;

    out_file.close();
}

void task10_3_math_append(const std::string& out_filename, double x, double y, double z, int b) {
    using namespace std;

    ofstream out_file(out_filename, ios::app);
    if (!out_file.is_open()) return;

    double s_result = s_calculation(x, y, z);

    out_file << "\n--- Задача 10.3 ---\n";
    out_file << "Результат виконання функції s_calculation з аргументами ";
    out_file << "x=" << x << ", y=" << y << ", z=" << z << " дорівнює: " << s_result << ".\n";

    string bin_str = "";
    int temp = b;
    if (temp == 0) {
        bin_str = "0";
    } else {
        while (temp > 0) {
            bin_str = (temp % 2 == 0 ? "0" : "1") + bin_str;
            temp /= 2;
        }
    }

    out_file << "Число " << b << " у двійковому коді: " << bin_str << ".\n";

    out_file.close();
}
