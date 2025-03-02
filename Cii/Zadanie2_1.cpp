#include <iostream>  
#include <iomanip>  
#include <cstdlib>  
#include <conio.h>  

#define N 5  

void main5() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем русскую локаль для поддержки кириллицы в консоли
    std::cout << "\033[32mСкаредин А.В. РИЗ-230916у\033[0m" << std::endl; // Зелёный цвет ФИО ГРуппа
    float m[N][N];
    int i, j;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            m[i][j] = rand() / 10.0;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            std::cout << std::setw(8) << std::setprecision(5) << m[i][j];
        std::cout << std::endl;
    }

    _getch();
  
}
