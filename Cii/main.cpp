#include "stroka.h"
#include <cstring> // для strlen, strcmp, strcpy
#include <locale> // Для поддержки русского языка

int main22() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем локализацию для русского языка

    std::cout << "\033[32mСкаредин А.В. РИЗ-230916у\033[0m" << std::endl; // Зелёный цвет ФИО Группа

    Stroka s1("qwert"), s3, s4(s1), s5;

    std::cout << "Введите строку для s3: ";
    s3.vvod();

    s3 = "asdfg";
    std::cout << "s3: ";
    s3.vyvod();

    s5 = s1 + s3 + s4;
    std::cout << "Длина s5 = " << s5.dlina() << std::endl;

    std::cout << "s5: ";
    s5.vyvod();

    if (s1 == s5) {
        std::cout << "Строки s1 и s5 равны" << std::endl;
    }
    else if (s1 == s4) {
        std::cout << "Строки s1 и s4 равны" << std::endl;
    }

    return 0;
}
    