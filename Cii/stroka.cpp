#include "stroka.h"

Stroka::Stroka(const char* string) {
    strcpy_s(str, sizeof(str), string);  // Используем strcpy_s
}

Stroka::Stroka() {
    str[0] = '\0';
}

Stroka::Stroka(const Stroka& s) {
    strcpy_s(str, sizeof(str), s.str);  // Используем strcpy_s
}

Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) {
        strcpy_s(str, sizeof(str), s.str);  // Используем strcpy_s
    }
    return *this;
}

Stroka Stroka::operator+(const Stroka& s) const {
    Stroka temp;
    strcpy_s(temp.str, sizeof(temp.str), str);  // Используем strcpy_s
    strcat_s(temp.str, sizeof(temp.str), s.str);  // Используем strcat_s
    return temp;
}

int Stroka::operator==(const Stroka& s) const {
    return strcmp(str, s.str) == 0;
}

int Stroka::dlina() const {
    return strlen(str);
}

void Stroka::vvod() {
    std::cin >> str;
}

void Stroka::vyvod() const {
    std::cout << str << std::endl;
}
