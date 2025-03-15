#include <iostream>
#include <cstring>

class String {
private:
    char* str;
    size_t length;

public:
    // Конструкторы
    String() : str(new char[1] {'\0'}), length(0) {}

    String(const char* s) {
        length = std::strlen(s);
        str = new char[length + 1];
        strcpy_s(str, length + 1, s);
    }

    // Конструктор копирования
    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
    }

    // Оператор присваивания
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy_s(str, length + 1, other.str);
        }
        return *this;
    }

    // Деструктор
    ~String() {
        delete[] str;
    }

    // Оператор конкатенации
    String operator+(const String& other) const {
        size_t newLength = length + other.length;
        char* newStr = new char[newLength + 1];

        strcpy_s(newStr, newLength + 1, str);
        strcat_s(newStr, newLength + 1, other.str);

        String result(newStr);
        delete[] newStr;
        return result;
    }

    // Оператор сравнения
    bool operator==(const String& other) const {
        return std::strcmp(str, other.str) == 0;
    }

    // Метод для определения длины строки
    size_t getLength() const {
        return length;
    }

    // Методы ввода и вывода строки
    friend std::ostream& operator<<(std::ostream& os, const String& s) {
        os << s.str;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, String& s) {
        char buffer[1024];
        is.getline(buffer, 1024);
        s = String(buffer);
        return is;
    }
};

// Тестирование класса
int main21() {

    String s1("Hello");
    String s2(" Hello");
    String s3 = s1 + s2;

    std::cout << "Stroka 1: " << s1 << "\n";
    std::cout << "Stroka 2: " << s2 << "\n";
    std::cout << "Konkatenacia: " << s3 << "\n";

    std::cout << "Vvedite stroku: ";
    String userInput;
    std::cin >> userInput;
    std::cout << "Vi vveli: " << userInput << "\n";

    std::cout << "Sravnenie strok (s1 == s2): " << (s1 == s2 ? "Yes" : "No") << "\n";
    std::cout << "Dlina stroki 1: " << s1.getLength() << "\n";

    return 0;
}
