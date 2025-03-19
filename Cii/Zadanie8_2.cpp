#include <iostream>
#include <fstream>
#include <cstring>
#include <locale> // Для поддержки русского языка

using namespace std;

class Stroka3 {
private:
    char* str;  // Динамический массив символов
    int length; // Длина строки
public:
    // Конструктор по умолчанию
    Stroka3() : str(new char[1]), length(0) { str[0] = '\0'; }

    // Конструктор с параметром
    Stroka3(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy_s(str, length + 1, s); // Используем strcpy_s
    }

    // Конструктор копирования
    Stroka3(const Stroka3& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
    }

    // Оператор присваивания
    Stroka3& operator=(const Stroka3& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy_s(str, length + 1, other.str);
        }
        return *this;
    }

    // Деструктор
    ~Stroka3() {
        delete[] str;
    }

    // Перегрузка оператора ввода
    friend istream& operator>>(istream& in, Stroka3& s) {
        char buffer[256]; // Буфер для ввода строки
        in.getline(buffer, 256);
        s.length = strlen(buffer);
        delete[] s.str; // Удаляем старую строку
        s.str = new char[s.length + 1];
        strcpy_s(s.str, s.length + 1, buffer);
        return in;
    }

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& out, const Stroka3& s) {
        out << s.str;
        return out;
    }

    // Перегрузка оператора вывода в файл
    friend ofstream& operator<<(ofstream& out, const Stroka3& s) {
        out << s.str;
        return out;
    }

    // Перегрузка оператора ввода из файла
    friend ifstream& operator>>(ifstream& in, Stroka3& s) {
        char buffer[256]; // Буфер для ввода строки
        in.getline(buffer, 256);
        s.length = strlen(buffer);
        delete[] s.str;
        s.str = new char[s.length + 1];
        strcpy_s(s.str, s.length + 1, buffer);
        return in;
    }
};

int main27() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем локализацию для русского языка
    // Оформление вывода (зелёный цвет ФИО и группы)
    std::cout << "\033[32mСкаредин А.В. РИЗ-230916у\033[0m" << std::endl;
    Stroka3 s1, s2("Hello, world!");

    // Ввод строки
    cout << "Введите строку: ";
    cin >> s1;
    cout << "Вы ввели: " << s1 << endl; // Вывод строки

    // Запись в файл
    ofstream outFile("Zadanie8_2.txt");
    if (outFile.is_open()) {
        outFile << s1 << endl;
        outFile << s2 << endl;
        outFile.close();
        cout << "Строки записаны в файл Zadanie8_2.txt" << endl;
    }
    else {
        cout << "Не удалось открыть файл для записи!" << endl;
    }

    // Чтение из файла
    ifstream inFile("Zadanie8_2.txt");
    if (inFile.is_open()) {
        Stroka3 fileString;
        inFile >> fileString;
        cout << "Строка из файла: " << fileString << endl;
        inFile.close();
    }
    else {
        cout << "Не удалось открыть файл для чтения!" << endl;
    }

    return 0;
}
