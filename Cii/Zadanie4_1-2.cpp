#include <iostream>
#include <cstring> // для strlen, strcmp, strcpy
#include <locale> // Для поддержки русского языка


// Вариант 1: Определение длины строки с использованием strlen
 int dlina1(const char* str) {
    return strlen(str);
}

// Вариант 2: Определение длины строки с использованием цикла while
int dlina2(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Вариант 3: Определение длины строки с использованием указателей
int dlina3(const char* str) {
    const char* ptr = str;
    while (*ptr) {
        ptr++;
    }
    return ptr - str;
}


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

// Функция определения длины строки
void dlina(const char* str) {
    std::cout << "Длина строки \"" << str << "\" = " << strlen(str) << std::endl;
}

int main11(void) {
    setlocale(LC_ALL, "Russian"); // Устанавливаем локализацию для русского языка

    std::cout << "\033[32mСкаредин А.В. РИЗ-230916у\033[0m" << std::endl; // Зелёный цвет ФИО Группа

    // Инициализация строк
    char str1[100] = "qwerty", str2[] = "1234567890";

    // Вывод начальных значений строк
    std::cout << "Начальное значение str1= \033[32m" << str1 << "\033[0m, str2= \033[32m" << str2 << "\033[0m" << std::endl;


    std::cout << "Длина str1 (\033[32m strlen \033[0m): \033[32m" << dlina1(str1) << "\033[0m" << std::endl;

    std::cout << "Длина str2 (\033[32m while \033[0m): \033[32m" << dlina2(str2) << "\033[0m" << std::endl;
    std::cout << "Длина str1 (\033[32m указатели \033[0m): \033[32m" << dlina3(str1) << "\033[0m" << std::endl << std::endl;   

   
    dlina(str1);
    dlina(str2);
    std::cout << std::endl;

    sravn(str1, str2);

    // Копирование str2 в str1
    kopir(str1, str2);
    std::cout << "результат копирования: \033[32mstr1= " << str1 << ", str2= " << str2 << "\033[0m" << std::endl;
    dlina(str1);
    dlina(str2);
    // Сравнение str1 и str2 после копирования
    std::cout << "\033[32m";  // Устанавливаем зелёный цвет
    sravn(str1, str2);        // Вызываем функцию сравнения (она сама печатает результат)
    std::cout << "\033[0m";   // Сбрасываем цвет

    std::cout << std::endl;    

    // Присваивание str1 заново "qwerty"
    kopir(str1, "qwerty");
    std::cout << "результат сравнения: \033[32mstr1= " << str1 << ", str2= " << str2 << "\033[0m" << std::endl;
    dlina(str1);
    dlina(str2);
    std::cout << std::endl;

    // Сравнение строк после восстановления str1
    sravn(str1, str2);

    // Сцепление str1 и str2
    konkat(str1, str2);
    std::cout << "результат сцепления: \033[32mstr1= " << str1 << ", str2= " << str2 << "\033[0m" << std::endl;
    dlina(str1);
    dlina(str2);
    std::cout << std::endl;

    return 0;
}
