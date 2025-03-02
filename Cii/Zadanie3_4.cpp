#include <iostream> 
#include <cstdlib>
#include <locale> // Библиотека русского языка !

// Функция для сортировки элементов массива по возрастанию на интервале [N1, N2]
void rangeSort2(int mas[], int n, int N1, int N2) {
    // Внешний цикл для прохода по индексам от N1 до N2
    for (int i = N1; i < N2 - 1; i++) {
        // Внутренний цикл для сравнения элементов в интервале [N1, N2]
        for (int j = i + 1; j < N2; j++) {
            // Если текущий элемент больше следующего, меняем их местами
            if (mas[i] > mas[j]) {
                std::swap(mas[i], mas[j]);
            }
        }
    }
}

// Функция для вывода массива на экран
void printArray2(int mas[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}

int main9() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем локализацию для русского языка
    int mas[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
    int n = sizeof(mas) / sizeof(int); // Размер массива

    // Выводим исходный массив
    std::cout << "До сортировки: ";
    printArray2(mas, n);

    // Интервал сортировки от N1 до N2
    int N1 = 2, N2 = 7;

    // Сортировка элементов массива по возрастанию на интервале [N1, N2]
    rangeSort2(mas, n, N1, N2);

    // Выводим результат после сортировки
    std::cout << "После сортировки на интервале от N1=" << N1 << " до N2=" << N2 << ": ";
    printArray2(mas, n);

    return 0;
}
