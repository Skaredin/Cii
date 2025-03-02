#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <cmath>  // Для использования fabs

#define N 5

// Функция для вычисления минимума матрицы
float minMatrix(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
    }
    return minVal;
}

// Функция для вычисления максимума матрицы
float maxMatrix(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }
    }
    return maxVal;
}

// Функция для вычисления максимума нижнетреугольной части матрицы
float maxLowerTriangle(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }
    }
    return maxVal;
}

// Функция для вычисления максимума верхнетреугольной части матрицы
float maxUpperTriangle(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }
    }
    return maxVal;
}

// Функция для вычисления минимума нижнетреугольной части матрицы
float minLowerTriangle(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
    }
    return minVal;
}

// Функция для вычисления минимума верхнетреугольной части матрицы
float minUpperTriangle(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
    }
    return minVal;
}

// Функция для вычисления минимума главной диагонали
float minMainDiagonal(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++) {
        if (m[i][i] < minVal) {
            minVal = m[i][i];
        }
    }
    return minVal;
}

// Функция для вычисления максимума главной диагонали
float maxMainDiagonal(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++) {
        if (m[i][i] > maxVal) {
            maxVal = m[i][i];
        }
    }
    return maxVal;
}

// Функция для вычисления минимума второстепенной диагонали
float minSecondaryDiagonal(float m[N][N]) {
    float minVal = m[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (m[i][N - i - 1] < minVal) {
            minVal = m[i][N - i - 1];
        }
    }
    return minVal;
}

// Функция для вычисления максимума второстепенной диагонали
float maxSecondaryDiagonal(float m[N][N]) {
    float maxVal = m[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (m[i][N - i - 1] > maxVal) {
            maxVal = m[i][N - i - 1];
        }
    }
    return maxVal;
}

// Функция для вычисления среднего арифметического всех элементов матрицы
float meanMatrix(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
    }
    return sum / (N * N);
}

// Функция для вычисления среднего арифметического элементов нижнетреугольной части матрицы
float meanLowerTriangle(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum / count;
}

// Функция для вычисления среднего арифметического элементов верхнетреугольной части матрицы
float meanUpperTriangle(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum / count;
}

// Функция для вычисления суммы элементов каждой строки матрицы
void sumRows(float m[N][N]) {
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
        std::cout << "Сумма\033[33m строки \033[32m" << i+1 << ": " << sum << "\033[0m" << std::endl;
    }
}

// Функция для вычисления суммы элементов каждого столбца матрицы
void sumColumns(float m[N][N]) {
    for (int j = 0; j < N; j++) {
        float sum = 0;
        for (int i = 0; i < N; i++) {
            sum += m[i][j];
        }
        std::cout << "Сумма\033[33m столбца \033[32m" << j+1 << ": " << sum << "\033[0m" << std::endl;
    }
}

// Функция для вычисления минимальных значений каждой строки
void minRowValues(float m[N][N]) {
    for (int i = 0; i < N; i++) {
        float minVal = m[i][0];
        for (int j = 1; j < N; j++) {
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
        std::cout << "\033[31m Минимальное \033[0m  значение в строке \033[32m" << i + 1 << ": " << minVal << "\033[0m" << std::endl;
    }
}

// Функция для вычисления минимальных значений каждого столбца
void minColumnValues(float m[N][N]) {
    for (int j = 0; j < N; j++) {
        float minVal = m[0][j];
        for (int i = 1; i < N; i++) {
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
        std::cout << "\033[31m Минимальное \033[0m значение в столбце \033[32m" << j + 1 << ": " << minVal << "\033[0m" << std::endl;
    }
}

// Функция для вычисления максимальных значений каждой строки
void maxRowValues(float m[N][N]) {
    for (int i = 0; i < N; i++) {
        float maxVal = m[i][0];
        for (int j = 1; j < N; j++) {
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }
        std::cout << "\033[31m Максимальное \033[0m значение в строке \033[32m" << i + 1 << ": " << maxVal << "\033[0m" << std::endl;
    }
}

// Функция для вычисления максимальных значений каждого столбца
void maxColumnValues(float m[N][N]) {
    for (int j = 0; j < N; j++) {
        float maxVal = m[0][j];
        for (int i = 1; i < N; i++) {
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }
        std::cout << "\033[31m Максимальное \033[0m значение в столбце \033[32m" << j + 1 << ": " << maxVal <<"\033[0m" << std::endl;
    }
}

// Функция для нахождения элемента, наиболее близкого к среднеарифметическому
float closestToMean(float m[N][N], float mean) {
    float closest = m[0][0];
    float minDiff = fabs(m[0][0] - mean);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float diff = fabs(m[i][j] - mean);
            if (diff < minDiff) {
                minDiff = diff;
                closest = m[i][j];
            }
        }
    }
    return closest;
}
// Функция для вычисления среднего арифметического значений каждой строки
void meanRowValues(float m[N][N]) {
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
        float mean = sum / N;
        std::cout << "\033[31m Среднее \033[0m арифметическое строки \033[32m" << i + 1 << ": " << mean << "\033[0m" << std::endl;
    }
}
// Функция для вычисления среднего арифметического значений каждого столбца
void meanColumnValues(float m[N][N]) {
    for (int j = 0; j < N; j++) {
        float sum = 0;
        for (int i = 0; i < N; i++) {
            sum += m[i][j];
        }
        float mean = sum / N;
        std::cout << "\033[31m Среднее \033[0m арифметическое столбца \033[32m" << j + 1 << ": " << mean << "\033[0m" << std::endl;
    }
}
// Функция для вычисления суммы элементов нижней треугольной части матрицы
float sumLowerTriangle(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += m[i][j];
        }
    }
    return sum;
}
// Функция для вычисления суммы элементов верхней треугольной части матрицы
float sumUpperTriangle(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += m[i][j];
        }
    }
    return sum;
}


// Главная функция для вывода результатов
void printMatrix(float m[N][N]) {
    std::cout << "\033[35m Матрица: \033[0m" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << std::setw(8) << std::setprecision(5) << m[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "\033[32mСкаредин А.В. РИЗ-230916у\033[0m" << std::endl;
    float m[N][N];
    int i, j;

    // Заполнение матрицы случайными числами
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            m[i][j] = rand() / 10.0;

    // Вывод матрицы
    std::cout << std::endl;
    printMatrix(m);
    std::cout << std::endl << std::endl;
    // Вызов функций для вычисления статистик
    std::cout << "Минимум матрицы: \033[32m" << minMatrix(m) <<"\033[0m" << std::endl;
    std::cout << "Максимум матрицы: \033[32m" << maxMatrix(m) << "\033[0m" << std::endl;
    std::cout << "Максимум нижней треугольной части:\033[32m " << maxLowerTriangle(m) << "\033[0m" << std::endl;
    std::cout << "Максимум верхней треугольной части: \033[32m" << maxUpperTriangle(m) << "\033[0m" << std::endl;
    std::cout << "Минимум нижней треугольной части: \033[32m" << minLowerTriangle(m) << "\033[0m" << std::endl;
    std::cout << "Минимум верхней треугольной части: \033[32m" << minUpperTriangle(m) << "\033[0m" << std::endl;
    std::cout << "Минимум главной диагонали: \033[32m" << minMainDiagonal(m) << "\033[0m" << std::endl;
    std::cout << "Максимум главной диагонали: \033[32m" << maxMainDiagonal(m) << "\033[0m" << std::endl;
    std::cout << "Минимум второстепенной диагонали: \033[32m" << minSecondaryDiagonal(m) << "\033[0m" << std::endl;
    std::cout << "Максимум второстепенной диагонали: \033[32m" << maxSecondaryDiagonal(m) << "\033[0m" << std::endl;
    std::cout << "Среднее арифметическое элементов матрицы: \033[32m" << meanMatrix(m) << "\033[0m" << std::endl;
    std::cout << "Среднее арифметическое элементов нижней треугольной части: \033[32m" << meanLowerTriangle(m) << "\033[0m" << std::endl;
    std::cout << "Среднее арифметическое элементов верхней треугольной части: \033[32m" << meanUpperTriangle(m) << "\033[0m" << std::endl;
      

    std::cout << std::endl;
    sumRows(m);
    std::cout << std::endl;

    std::cout << std::endl;
    sumColumns(m);  
    std::cout << std::endl;
   

    // Минимальные и максимальные значения строк и столбцов
    std::cout << std::endl;
    minRowValues(m);
    std::cout << std::endl;
    minColumnValues(m);
    std::cout << std::endl;
    maxRowValues(m);
    std::cout << std::endl;
    maxColumnValues(m);
    std::cout << std::endl;
    meanRowValues(m);
    std::cout << std::endl;
    meanColumnValues(m);
    std::cout << std::endl;


    std::cout << "Сумма нижней треугольной части матрицы: \033[32m" << sumLowerTriangle(m) << "\033[0m" << std::endl;
    std::cout << "Сумма верхней треугольной части матрицы: \033[32m" << sumUpperTriangle(m) << "\033[0m" << std::endl;


    // Элемент, наиболее близкий к среднеарифметическому
    float mean = meanMatrix(m);
    std::cout << "Элемент, наиболее близкий к среднему арифметическому: \033[32m" << closestToMean(m, mean) << "\033[0m" << std::endl;

    _getch();
    return 0;
}
