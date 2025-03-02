#include <iostream>
#include <cstring>  // Для strlen, strcmp, strcpy_s, strcat_s
#include <locale>   // Для поддержки русского языка
#include <cstdlib>  // Для malloc, calloc и free

// Функция определения длины строки
int dlina6(const char* str) {
    return strlen(str);
}

// Функция копирования строки 
void kopir6(char* str1, const char* str2, size_t size) {
    strcpy_s(str1, size, str2);
}

// Функция сравнения строк
inline void sravn6(const char* str1, const char* str2) {
    if (strcmp(str1, str2) == 0) {
        std::cout << "Строки одинаковы" << std::endl;
    }
    else {
        std::cout << "Строки разные" << std::endl;
    }
}

// Функция сцепления строк 
void konkat6(char* str1, const char* str2, size_t size) {
    strcat_s(str1, size, str2);
}

int main13() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем локализацию для русского языка

    std::cout << "\033[32mСкаредин А.В. РИЗ-230916у\033[0m" << std::endl; // Зелёный цвет ФИО Группа

    // Динамическое выделение памяти с использованием calloc
    char* str1 = (char*)calloc(100, sizeof(char));  // Используем calloc
    char* str2 = (char*)calloc(100, sizeof(char));  // Используем calloc

    if (!str1 || !str2) {
        std::cerr << "Ошибка выделения памяти!" << std::endl;
        return 1;
    }

    // Инициализация строк
    kopir6(str1, "qwerty", 100);
    kopir6(str2, "1234567890", 100);

    // Вывод начальных значений строк
    std::cout << "Начальное значение str1 = \033[32m" << str1
        << "\033[0m, str2 = \033[32m" << str2 << "\033[0m" << std::endl;

    std::cout << "Длина str1: \033[32m" << dlina6(str1) << "\033[0m" << std::endl;
    std::cout << "Длина str2: \033[32m" << dlina6(str2) << "\033[0m" << std::endl;

    sravn6(str1, str2);

    // Копирование str2 в str1
    kopir6(str1, str2, 100);
    std::cout << "Результат копирования: \033[32mstr1= " << str1
        << ", str2= " << str2 << "\033[0m" << std::endl;

    sravn6(str1, str2);

    // Присваивание str1 заново "qwerty"
    kopir6(str1, "qwerty", 100);
    std::cout << "Результат сравнения: \033[32mstr1= " << str1
        << ", str2= " << str2 << "\033[0m" << std::endl;

    sravn6(str1, str2);

    // Сцепление строк
    konkat6(str1, str2, 100);
    std::cout << "Результат сцепления: \033[32mstr1= " << str1
        << ", str2= " << str2 << "\033[0m" << std::endl;

    // Освобождение памяти
    free(str1);
    free(str2);

    return 0;
}
