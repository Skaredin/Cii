#include <iostream>
#include <cstring>
#include <locale> // Для поддержки русского языка
#include <iomanip> // Для использования манипуляторов потока

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
        in.clear(); // Сброс флагов потока
        in.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем остатки потока
        in.getline(buffer, 256); // Считываем строку с пробелами
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
};

int main() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем локализацию для русского языка

    // Оформление вывода (зелёный цвет ФИО и группы)
    std::cout << "\033[32mСкаредин А.В. РИЗ-230916у\033[0m" << std::endl;

    // Пример изменения состояния потока: устанавливаем точность вывода
    cout << fixed << setprecision(2); // Устанавливаем вывод с точностью до 2 знаков после запятой
    cout << "Пример с точностью до двух знаков: " << 123.456789 << endl;

    // Пример изменения состояния потока: вывод с заданной шириной
    cout << setw(20) << "Текст с шириной 20 символов" << endl;

    // Пример использования scientific для научного формата
    cout << scientific << setprecision(4); // Используем научный формат
    cout << "Пример с научным выводом: " << 12345.6789 << endl;

    Stroka3 s1, s2("Hello, world!");

    // Пример изменения состояния потока: устанавливаем флаг флуда
    cout << boolalpha; // Будем выводить булевы значения как "true" или "false"
    cout << "Булевое значение true: " << true << endl;
    cout << "Булевое значение false: " << false << endl;

    // Ввод строки с клавиатуры
    cout << "Введите строку: ";
    cin >> s1;  // Ввод строки с клавиатуры

    // Пример изменения состояния потока: проверка на ошибки потока
    if (cin.fail()) {
        cerr << "Ошибка ввода!" << endl;
        return 1;
    }

    // Вывод строки
    cout << "Вы ввели: " << s1 << endl;

    // Пример работы с ошибками потока: сброс флагов
    cin.clear();  // Сбрасываем флаги ошибки потока
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем остатки потока

    // Пример использования состояния потока после сброса ошибок
    cout << "Этот вывод после сброса флагов потока!" << endl;

    // Вывод заранее заданной строки
    cout << "Пример заранее заданной строки: " << s2 << endl;

    return 0;
}
