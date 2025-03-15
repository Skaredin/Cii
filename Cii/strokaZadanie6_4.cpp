#include "strokaZadanie6_4.h"
#include <iostream>
#include <cstring>

void Stroka4::kopir(char* str1, const char* str2) {
    strcpy_s(str1, strlen(str2) + 1, str2);
}

void Stroka4::konkat(char* str1, const char* str2) {
    strcat_s(str1, strlen(str1) + strlen(str2) + 1, str2);
}


int Stroka4::dlina1(const char* str) {
    return strlen(str);
}

int Stroka4::dlina2(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int Stroka4::dlina3(const char* str) {
    const char* ptr = str;
    while (*ptr) {
        ptr++;
    }
    return ptr - str;
}

void Stroka4::sravn(const char* str1, const char* str2) {
    if (strcmp(str1, str2) == 0) {
        std::cout << "Строки одинаковы" << std::endl;
    }
    else {
        std::cout << "Строки разные" << std::endl;
    }
}

// Конструктор с параметром
Stroka4::Stroka4(const char* string) {
    size = strlen(string) + 1;
    str = new char[size];
    kopir(str, string);
}

// Конструктор, выделяющий память под строку заданного размера
Stroka4::Stroka4(int length) {
    size = length + 1;
    str = new char[size];
    str[0] = '\0'; // Инициализируем пустую строку
}

// Конструктор по умолчанию
Stroka4::Stroka4() {
    size = 80;
    str = new char[size];
    str[0] = '\0';
}

// Конструктор копирования
Stroka4::Stroka4(const Stroka4& s) {
    size = s.size;
    str = new char[size];
    kopir(str, s.str);
}

// Деструктор
Stroka4::~Stroka4() {
    delete[] str;
}

// Оператор присваивания
Stroka4& Stroka4::operator=(const Stroka4& s) {
    if (this != &s) {
        delete[] str;
        size = s.size;
        str = new char[size];
        kopir(str, s.str);
    }
    return *this;
}

// Оператор сложения
Stroka4 Stroka4::operator+(const Stroka4& s) const {
    Stroka4 temp(dlina() + s.dlina()); // Создаём объект с нужным размером
    kopir(temp.str, str);
    konkat(temp.str, s.str);
    return temp;
}

// Оператор сравнения
int Stroka4::operator==(const Stroka4& s) const {
    return strcmp(str, s.str) == 0;
}

// Метод для получения длины строки
int Stroka4::dlina() const {
    return dlina1(str);
}

// Метод ввода строки
void Stroka4::vvod() {
    std::cin >> str;
}

// Метод вывода строки
void Stroka4::vyvod() const {
    std::cout << str << std::endl;
}
