#ifndef MODULE_EDITING_HRYTSIUK_H_INCLUDED
#define MODULE_EDITING_HRYTSIUK_H_INCLUDED

#include "struct_type_project_2.h"

void addRecord(PhoneRecord*& head, PhoneRecord*& tail, const char* city, const char* code);

void deleteRecord(PhoneRecord*& head, PhoneRecord*& tail, const char* city);

#endif // MODULE_EDITING_HRYTSIUK_H_INCLUDED
