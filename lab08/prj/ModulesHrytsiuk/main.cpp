#include <cmath>
#include <stdexcept>
#include <string>

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

    discount_uah = purchase_amount * (percent / 100.0);
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
