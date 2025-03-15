#ifndef STROKA_H2
#define STROKA_H2

#include <iostream>

class Stroka4 {
private:
    char* str;  // Указатель на динамическую строку
    int size;   // Размер выделенной памяти

public:
    Stroka4(const char* string);  // Конструктор с параметром
    Stroka4(int length);          // Конструктор с выделением памяти
    Stroka4();                    // Конструктор по умолчанию
    Stroka4(const Stroka4& s);     // Конструктор копирования
    ~Stroka4();                    // Деструктор

    Stroka4& operator=(const Stroka4& s); // Оператор присваивания
    Stroka4 operator+(const Stroka4& s) const; // Оператор сложения
    int operator==(const Stroka4& s) const; // Оператор сравнения

    int dlina() const;  // Метод для получения длины
    void vvod();        // Метод ввода строки
    void vyvod() const; // Метод вывода строки

    const char* getStr() const { return str; }  // Геттер для доступа к строке

    // Статические функции
    static void kopir(char* str1, const char* str2);
    static void konkat(char* str1, const char* str2);
    static int dlina1(const char* str);
    static int dlina2(const char* str);
    static int dlina3(const char* str);
    static void sravn(const char* str1, const char* str2);
};

#endif // STROKA_H2
