#include <iostream>  
#include <iomanip>  
#include <cstdlib>  
#include <conio.h>  

#define N 5  

void main5() {
    setlocale(LC_ALL, "Russian"); // ������������� ������� ������ ��� ��������� ��������� � �������
    std::cout << "\033[32m�������� �.�. ���-230916�\033[0m" << std::endl; // ������ ���� ��� ������
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
