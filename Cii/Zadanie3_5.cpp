#include <iostream>
#include <cstdlib>
#include <locale> // Библеотека русского языка!

// Функция для сортировки элементов массива по убыванию на интервале [N1, N2]
void rangeSortDesc3(int mas[], int n, int N1, int N2) {
    // Внешний цикл для прохода по индексу от N1 до N2
    for (int i = N1; i < N2 - 1; i++) {
        // Внутренний цикл для сравнения элементов
        for (int j = i + 1; j < N2; j++) {
            if (mas[i] < mas[j]) { // Если текущий элемент меньше следующего, меняем местами
                std::swap(mas[i], mas[j]);
            }
        }
    }
}

// Функция для вывода массива на экран
void printArray3(int mas[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}

int main10() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем локализацию для русского языка
    int mas[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
    int n = sizeof(mas) / sizeof(int); // Размер массива

    // Выводим исходный массив
    std::cout << "До сортировки: ";
    printArray3(mas, n);

    // Интервал сортировки от N1 до N2
    int N1 = 2, N2 = 7;

    // Сортировка элементов массива по убыванию на интервале [N1, N2]
    rangeSortDesc3(mas, n, N1, N2);

    // Выводим результат после сортировки
    std::cout << "После сортировки по убыванию на интервале от N1=" << N1 << " до N2=" << N2 << ": ";
    printArray3(mas, n);

    return 0;
}
