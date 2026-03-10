#include <cmath>
#include <stdexcept>

constexpr double PI = 3.14159265358979323846;

double s_calculation(double x, double y, double z) {
    if (z < 0.0) {
        throw std::invalid_argument("z не може бути від'ємним");
    }
    double term1 = pow(x + y + z, 2.0);
    double term2 = 2.0 * PI * sqrt(z / 3.0);
    return term1 - term2;
}
