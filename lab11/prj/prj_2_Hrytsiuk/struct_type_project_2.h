#ifndef STRUCT_TYPE_PROJECT_2_H_INCLUDED
#define STRUCT_TYPE_PROJECT_2_H_INCLUDED

const int MAX_CITY_LEN = 64;
const int MAX_CODE_LEN = 16;

struct PhoneRecord {

    char cityName[MAX_CITY_LEN];
    char phoneCode[MAX_CODE_LEN];

    PhoneRecord* next;
    PhoneRecord* prev;

};

#endif // STRUCT_TYPE_PROJECT_2_H_INCLUDED
