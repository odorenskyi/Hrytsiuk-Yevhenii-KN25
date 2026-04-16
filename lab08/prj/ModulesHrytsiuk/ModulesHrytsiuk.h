#ifndef MODULESHRYTSIUK_H_INCLUDED
#define MODULESHRYTSIUK_H_INCLUDED

#include <string>

double s_calculation(double x, double y, double z);
int task9_1_discount(double purchase_amount, double& discount_uah, double& final_amount);
std::string task9_2_size_converter(int ukr_size);
int task9_3_bit_counter(int n);

void task10_1_file_write(const std::string& in_filename, const std::string& out_filename);
void task10_2_file_append(const std::string& in_filename, const std::string& out_filename);
void task10_3_math_append(const std::string& out_filename, double x, double y, double z, int b);

#endif
