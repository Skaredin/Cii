#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <cmath>  // ��� ������������� fabs

#define N 5

// ������� ��� ���������� �������� �������
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

// ������� ��� ���������� ��������� �������
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

// ������� ��� ���������� ��������� ���������������� ����� �������
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

// ������� ��� ���������� ��������� ����������������� ����� �������
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

// ������� ��� ���������� �������� ���������������� ����� �������
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

// ������� ��� ���������� �������� ����������������� ����� �������
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

// ������� ��� ���������� �������� ������� ���������
float minMainDiagonal(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++) {
        if (m[i][i] < minVal) {
            minVal = m[i][i];
        }
    }
    return minVal;
}

// ������� ��� ���������� ��������� ������� ���������
float maxMainDiagonal(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++) {
        if (m[i][i] > maxVal) {
            maxVal = m[i][i];
        }
    }
    return maxVal;
}

// ������� ��� ���������� �������� �������������� ���������
float minSecondaryDiagonal(float m[N][N]) {
    float minVal = m[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (m[i][N - i - 1] < minVal) {
            minVal = m[i][N - i - 1];
        }
    }
    return minVal;
}

// ������� ��� ���������� ��������� �������������� ���������
float maxSecondaryDiagonal(float m[N][N]) {
    float maxVal = m[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (m[i][N - i - 1] > maxVal) {
            maxVal = m[i][N - i - 1];
        }
    }
    return maxVal;
}

// ������� ��� ���������� �������� ��������������� ���� ��������� �������
float meanMatrix(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
    }
    return sum / (N * N);
}

// ������� ��� ���������� �������� ��������������� ��������� ���������������� ����� �������
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

// ������� ��� ���������� �������� ��������������� ��������� ����������������� ����� �������
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

// ������� ��� ���������� ����� ��������� ������ ������ �������
void sumRows(float m[N][N]) {
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
        std::cout << "�����\033[33m ������ \033[32m" << i+1 << ": " << sum << "\033[0m" << std::endl;
    }
}

// ������� ��� ���������� ����� ��������� ������� ������� �������
void sumColumns(float m[N][N]) {
    for (int j = 0; j < N; j++) {
        float sum = 0;
        for (int i = 0; i < N; i++) {
            sum += m[i][j];
        }
        std::cout << "�����\033[33m ������� \033[32m" << j+1 << ": " << sum << "\033[0m" << std::endl;
    }
}

// ������� ��� ���������� ����������� �������� ������ ������
void minRowValues(float m[N][N]) {
    for (int i = 0; i < N; i++) {
        float minVal = m[i][0];
        for (int j = 1; j < N; j++) {
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
        std::cout << "\033[31m ����������� \033[0m  �������� � ������ \033[32m" << i + 1 << ": " << minVal << "\033[0m" << std::endl;
    }
}

// ������� ��� ���������� ����������� �������� ������� �������
void minColumnValues(float m[N][N]) {
    for (int j = 0; j < N; j++) {
        float minVal = m[0][j];
        for (int i = 1; i < N; i++) {
            if (m[i][j] < minVal) {
                minVal = m[i][j];
            }
        }
        std::cout << "\033[31m ����������� \033[0m �������� � ������� \033[32m" << j + 1 << ": " << minVal << "\033[0m" << std::endl;
    }
}

// ������� ��� ���������� ������������ �������� ������ ������
void maxRowValues(float m[N][N]) {
    for (int i = 0; i < N; i++) {
        float maxVal = m[i][0];
        for (int j = 1; j < N; j++) {
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }
        std::cout << "\033[31m ������������ \033[0m �������� � ������ \033[32m" << i + 1 << ": " << maxVal << "\033[0m" << std::endl;
    }
}

// ������� ��� ���������� ������������ �������� ������� �������
void maxColumnValues(float m[N][N]) {
    for (int j = 0; j < N; j++) {
        float maxVal = m[0][j];
        for (int i = 1; i < N; i++) {
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
            }
        }
        std::cout << "\033[31m ������������ \033[0m �������� � ������� \033[32m" << j + 1 << ": " << maxVal <<"\033[0m" << std::endl;
    }
}

// ������� ��� ���������� ��������, �������� �������� � ���������������������
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
// ������� ��� ���������� �������� ��������������� �������� ������ ������
void meanRowValues(float m[N][N]) {
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
        float mean = sum / N;
        std::cout << "\033[31m ������� \033[0m �������������� ������ \033[32m" << i + 1 << ": " << mean << "\033[0m" << std::endl;
    }
}
// ������� ��� ���������� �������� ��������������� �������� ������� �������
void meanColumnValues(float m[N][N]) {
    for (int j = 0; j < N; j++) {
        float sum = 0;
        for (int i = 0; i < N; i++) {
            sum += m[i][j];
        }
        float mean = sum / N;
        std::cout << "\033[31m ������� \033[0m �������������� ������� \033[32m" << j + 1 << ": " << mean << "\033[0m" << std::endl;
    }
}
// ������� ��� ���������� ����� ��������� ������ ����������� ����� �������
float sumLowerTriangle(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += m[i][j];
        }
    }
    return sum;
}
// ������� ��� ���������� ����� ��������� ������� ����������� ����� �������
float sumUpperTriangle(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += m[i][j];
        }
    }
    return sum;
}


// ������� ������� ��� ������ �����������
void printMatrix(float m[N][N]) {
    std::cout << "\033[35m �������: \033[0m" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << std::setw(8) << std::setprecision(5) << m[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "\033[32m�������� �.�. ���-230916�\033[0m" << std::endl;
    float m[N][N];
    int i, j;

    // ���������� ������� ���������� �������
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            m[i][j] = rand() / 10.0;

    // ����� �������
    std::cout << std::endl;
    printMatrix(m);
    std::cout << std::endl << std::endl;
    // ����� ������� ��� ���������� ���������
    std::cout << "������� �������: \033[32m" << minMatrix(m) <<"\033[0m" << std::endl;
    std::cout << "�������� �������: \033[32m" << maxMatrix(m) << "\033[0m" << std::endl;
    std::cout << "�������� ������ ����������� �����:\033[32m " << maxLowerTriangle(m) << "\033[0m" << std::endl;
    std::cout << "�������� ������� ����������� �����: \033[32m" << maxUpperTriangle(m) << "\033[0m" << std::endl;
    std::cout << "������� ������ ����������� �����: \033[32m" << minLowerTriangle(m) << "\033[0m" << std::endl;
    std::cout << "������� ������� ����������� �����: \033[32m" << minUpperTriangle(m) << "\033[0m" << std::endl;
    std::cout << "������� ������� ���������: \033[32m" << minMainDiagonal(m) << "\033[0m" << std::endl;
    std::cout << "�������� ������� ���������: \033[32m" << maxMainDiagonal(m) << "\033[0m" << std::endl;
    std::cout << "������� �������������� ���������: \033[32m" << minSecondaryDiagonal(m) << "\033[0m" << std::endl;
    std::cout << "�������� �������������� ���������: \033[32m" << maxSecondaryDiagonal(m) << "\033[0m" << std::endl;
    std::cout << "������� �������������� ��������� �������: \033[32m" << meanMatrix(m) << "\033[0m" << std::endl;
    std::cout << "������� �������������� ��������� ������ ����������� �����: \033[32m" << meanLowerTriangle(m) << "\033[0m" << std::endl;
    std::cout << "������� �������������� ��������� ������� ����������� �����: \033[32m" << meanUpperTriangle(m) << "\033[0m" << std::endl;
      

    std::cout << std::endl;
    sumRows(m);
    std::cout << std::endl;

    std::cout << std::endl;
    sumColumns(m);  
    std::cout << std::endl;
   

    // ����������� � ������������ �������� ����� � ��������
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


    std::cout << "����� ������ ����������� ����� �������: \033[32m" << sumLowerTriangle(m) << "\033[0m" << std::endl;
    std::cout << "����� ������� ����������� ����� �������: \033[32m" << sumUpperTriangle(m) << "\033[0m" << std::endl;


    // �������, �������� ������� � ���������������������
    float mean = meanMatrix(m);
    std::cout << "�������, �������� ������� � �������� ���������������: \033[32m" << closestToMean(m, mean) << "\033[0m" << std::endl;

    _getch();
    return 0;
}
