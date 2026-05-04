#ifndef MODULE_FILES_HONCHARENKO_H_INCLUDED
#define MODULE_FILES_HONCHARENKO_H_INCLUDED
#include "struct_type_project_2.h"

void saveToFile(const char* filename, PhoneRecord* head);

void loadFromFile(const char* filename, PhoneRecord*& head, PhoneRecord*& tail);


#endif // MODULE_FILES_HONCHARENKO_H_INCLUDED
