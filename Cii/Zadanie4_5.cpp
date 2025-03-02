#include <iostream>
#include <cstring>  // Для strlen, strcmp, strcpy_s, strcat_s
#include <locale>   // Для поддержки русского языка
#include <cstdlib>  // Для malloc, calloc и free

// Функция определения длины строки
int dlina7(const char* str) {
    return strlen(str);
}

// Функция копирования строки 
void kopir7(char* str1, const char* str2, size_t size) {
    strcpy_s(str1, size, str2);
}

// Функция сравнения строк
inline void sravn7(const char* str1, const char* str2) {
    if (strcmp(str1, str2) == 0) {
        std::cout << "Строки одинаковы" << std::endl;
    }
    else {
        std::cout << "Строки разные" << std::endl;
    }
}

// Функция сцепления строк 
void konkat7(char* str1, const char* str2, size_t size) {
    strcat_s(str1, size, str2);
}

int main14() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем локализацию для русского языка

    std::cout << "\033[32mСкаредин А.В. РИЗ-230916у\033[0m" << std::endl; // Зелёный цвет ФИО Группа

    // Динамическое выделение памяти с использованием calloc для массива строк
    const int numStrings = 3; // Количество строк в массиве
    char* strArray[numStrings]; // Массив указателей на строки

    // Выделение памяти для каждой строки
    for (int i = 0; i < numStrings; ++i) {
        strArray[i] = (char*)calloc(100, sizeof(char));
        if (!strArray[i]) {
            std::cerr << "Ошибка выделения памяти!" << std::endl;
            return 1;
        }
    }

    std::cout << "\n\033[34mСтрока до копирования strArray[0]: \033[33m Данные:" << strArray[0] << " \033[32m Длина:" << dlina7(strArray[0]) << "\033[0m";
    std::cout << "\n\033[34mСтрока до копирования strArray[1]: \033[33m Данные:" << strArray[1] << " \033[32m Длина:" << dlina7(strArray[1]) << "\033[0m";
    std::cout << "\n\033[34mСтрока до копирования strArray[2]: \033[33m Данные:" << strArray[2] << " \033[32m Длина:" << dlina7(strArray[2]) << "\033[0m" << std::endl;


    // Инициализация строк в массиве
    kopir7(strArray[0], "qwerty", 100);
    kopir7(strArray[1], "1234567890", 100);
    kopir7(strArray[2], "hello world", 100);

    // Вывод длины строк
    std::cout << "\n\033[35mСтрока после копирования strArray[0]: \033[33m Данные:" << strArray[0] <<" \033[32m Длина:" << dlina7(strArray[0]) << "\033[0m";
    std::cout << "\n\033[35mСтрока после копирования strArray[1]: \033[33m Данные:" << strArray[1] << " \033[32m Длина:" << dlina7(strArray[1]) << "\033[0m";
    std::cout << "\n\033[35mСтрока после копирования strArray[2]: \033[33m Данные:" << strArray[2] << " \033[32m Длина:" << dlina7(strArray[2]) << "\033[0m" << std::endl << std::endl;

         
    std::cout << "\n\033[31mСтроки strArray[0] и strArray[0]: \033[33m" << strArray[0] << "  и  " << strArray[0] << " \033[31m ";
    // Сравнение строк strArray[0], strArray[0]
    sravn7(strArray[0], strArray[0]);
    std::cout << "\033[0m";

    std::cout << "\n\033[36mСтроки strArray[0] и strArray[1]: \033[33m" << strArray[0] << "  и  " << strArray[1] << " \033[32m";
    // Сравнение строк strArray[0], strArray[1]
    sravn7(strArray[0], strArray[1]);
    std::cout << "\033[0m";

    std::cout << "\n\033[36mСтроки strArray[1] и strArray[2]: \033[33m" << strArray[1] << "  и  " << strArray[2] << " \033[32m";
    // Сравнение строк strArray[1], strArray[2]
    sravn7(strArray[1], strArray[2]);
    std::cout << "\033[0m";
     

    std::cout << "\n\033[31m" << "strArray[0] не забывайте что мы прибавляем к strArray[0] другие типы и он сохраняет структуру !" << "\033[0m" << std::endl;

    // Сцепление строк
    konkat7(strArray[0], "", 100);
    std::cout << "Результат сцепления 1 (strArray[0] и \"\"): \033[32m" << strArray[0] << "\033[0m";

    // Сцепление строк
    konkat7(strArray[0], strArray[2], 100);
    std::cout << "\nРезультат сцепления 2 (strArray[0] и strArray[2]): \033[32m" << strArray[0] << "\033[0m" ;

    // Сцепление строк
    konkat7(strArray[0], strArray[1], 100);
    std::cout << "\nРезультат сцепления 3 (strArray[0] и strArray[1]): \033[32m" << strArray[0] << "\033[0m" << std::endl;

    // Сцепление строк
    konkat7(strArray[0], strArray[2], 100);
    std::cout << "\nРезультат сцепления 4 (strArray[0] и strArray[2]): \033[32m" << strArray[0] << "\033[0m" << std::endl;


    // Освобождение памяти
    for (int i = 0; i < numStrings; ++i) {
        free(strArray[i]);
    }

    return 0;
}
