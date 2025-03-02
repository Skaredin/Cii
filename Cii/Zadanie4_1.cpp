#include <iostream>
#include <cstring> // для strcmp, strcpy
#include <locale> // Для поддержки русского языка

// Функция копирования строки
void kopir(char* str1, const char* str2) {
    int i = 0;
    while (str2[i] != '\0') {
        str1[i] = str2[i]; // Копируем символы
        i++;
    }
    str1[i] = '\0'; // Завершаем строку
}

// Функция сравнения строк
void sravn(const char* str1, const char* str2) {
    if (strcmp(str1, str2) == 0) {
        std::cout << "Строки одинаковы" << std::endl;
    }
    else {
        std::cout << "Строки разные" << std::endl;
    }
}

// Функция сцепления строк
void konkat(char* str1, const char* str2) {
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

int main(void) {
   
    setlocale(LC_ALL, "Russian"); // Устанавливаем локализацию для русского языка
    
    std::cout << "\033[32mСкаредин А.В. РИЗ-230916у\033[0m" << std::endl; // Зелёный цвет ФИО ГРуппа
    // Инициализация строк
    char str1[100] = "qwerty", str2[] = "1234567890";

    // Вывод начальных значений строк
    std::cout << "Начальное значение str1= " << str1 << ", str2= " << str2 << std::endl << std::endl;;

    sravn(str1, str2);

    // Копирование str2 в str1
    kopir(str1, str2);
    std::cout << "результат копирования: str1= " << str1 << ", str2=" << str2 << std::endl << std::endl;;

    // Сравнение str1 и str2 после копирования
    sravn(str1, str2);

    // Присваивание str1 заново "qwerty"
    kopir(str1, "qwerty");

    std::cout << "результат сравнения: str1= " << str1 << ", str2=" << str2 << std::endl << std::endl;;

    // Сравнение строк после восстановления str1
    sravn(str1, str2);

    // Сцепление str1 и str2
    konkat(str1, str2);
    std::cout << "результат сцепления: str1= " << str1 << ", str2=" << str2 << std::endl << std::endl;;

    return 0;
}
