#include <iostream>
#include <cstdlib>
#include <locale>// Библеотека русского языка !
bool isEven(int num) {
    return num % 2 == 0;
}

void customSort1(int mas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isEven(mas[i]) && isEven(mas[j]) && mas[i] > mas[j]) {
                std::swap(mas[i], mas[j]);
            }
            if (!isEven(mas[i]) && !isEven(mas[j]) && mas[i] < mas[j]) {
                std::swap(mas[i], mas[j]);
            }
        }
    }
}

void printArray1(int mas[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}

int main8() {
    setlocale(LC_ALL, "Russian");// Библеотека русского языка !
    int mas[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
    int n = sizeof(mas) / sizeof(int);

    std::cout << "До сортировки: ";
    printArray1(mas, n);

    customSort1(mas, n);

    std::cout << "После сортировки четных по возрастанию и нечетных по убыванию: ";
    printArray1(mas, n);

    return 0;
}
