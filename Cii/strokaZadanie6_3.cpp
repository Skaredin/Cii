#include "strokaZadanie6_3.h"
#include <iostream>
#include <cstring> // для strlen, strcmp, strcpy

void Stroka2::kopir(char* str1, const char* str2) {
    int i = 0;
    while (str2[i] != '\0') {
        str1[i] = str2[i]; // Копируем символы
        i++;
    }
    str1[i] = '\0'; // Завершаем строку
}

void Stroka2::konkat(char* str1, const char* str2) {
    int i = 0, j = 0;
    while (str1[i] != '\0') { // Ищем конец первой строки
        i++;
    }
    while (str2[j] != '\0') { // Добавляем символы второй строки
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0'; // Завершаем строку
}

int Stroka2::dlina1(const char* str) {
    return strlen(str);
}

int Stroka2::dlina2(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int Stroka2::dlina3(const char* str) {
    const char* ptr = str;
    while (*ptr) {
        ptr++;
    }
    return ptr - str;
}

void Stroka2::sravn(const char* str1, const char* str2) {
    if (strcmp(str1, str2) == 0) {
        std::cout << "Строки одинаковы" << std::endl;
    }
    else {
        std::cout << "Строки разные" << std::endl;
    }
}

Stroka2::Stroka2(const char* string) {
    kopir(str, string);
}

Stroka2::Stroka2() {
    str[0] = '\0';
}

Stroka2::Stroka2(const Stroka2& s) {
    kopir(str, s.str);
}

Stroka2& Stroka2::operator=(const Stroka2& s) {
    if (this != &s) {
        kopir(str, s.str);
    }
    return *this;
}

Stroka2 Stroka2::operator+(const Stroka2& s) const {
    Stroka2 temp;
    kopir(temp.str, str);
    konkat(temp.str, s.str);
    return temp;
}

int Stroka2::operator==(const Stroka2& s) const {
    return strcmp(str, s.str) == 0;
}

int Stroka2::dlina() const {
    return dlina1(str); // Используем вариант 1
}

void Stroka2::vvod() {
    std::cin >> str;
}

void Stroka2::vyvod() const {
    std::cout << str << std::endl;
}
