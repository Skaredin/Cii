#include <iostream>  // Подключение библиотеки для работы с вводом-выводом
#include <cstdlib>   // Подключение библиотеки для работы со случайными числами
#include <ctime>     // Подключение библиотеки для работы с временем
#include <conio.h>   // Подключение библиотеки для работы с клавиатурным вводом (_kbhit(), _getch())
#include <locale> // Для поддержки русского языка
using namespace std; // Использование стандартного пространства имен

// Базовый класс Point (Точка)
class Point {
protected:
    int x, y;   // Координаты точки
    int color;  // Цвет точки
public:
    // Конструктор класса, инициализирует координаты и цвет
    Point(int XN, int YN, int Color) : x(XN), y(YN), color(Color) {}

    // Виртуальный метод для отображения точки
    virtual void show() { cout << "Point at (" << x << ", " << y << ") with color " << color << endl; }

    // Виртуальный метод для скрытия точки
    virtual void hide() { cout << "Hiding Point at (" << x << ", " << y << ")" << endl; }

    // Метод для перемещения точки в пределах экрана
    void move(int maxX, int maxY);
};

// Реализация метода move() класса Point
void Point::move(int maxX, int maxY) {
    int dx, dy;
    srand(time(0)); // Инициализация генератора случайных чисел

    do {
        dx = rand() % 3 - 1; // Случайное смещение по X (-1, 0, 1)
        dy = rand() % 3 - 1; // Случайное смещение по Y (-1, 0, 1)

        hide(); // Скрываем объект перед перемещением
        x = max(0, min(x + dx, maxX)); // Ограничиваем координаты в пределах экрана
        y = max(0, min(y + dy, maxY));
        show(); // Отображаем объект после перемещения

    } while (!_kbhit()); // Ждем нажатия клавиши
    _getch(); // Ожидаем подтверждение ввода
}

// Класс Krug (Круг), наследуется от Point
class Krug : public Point {
private:
    int radius; // Радиус круга
public:
    // Конструктор класса Krug
    Krug(int XN, int YN, int R, int Color) : Point(XN, YN, Color), radius(R) { show(); }

    // Переопределенный метод show() для круга
    void show() override {
        cout << "Krug at (" << x << ", " << y << ") with radius " << radius << " and color " << color << endl;
    }

    // Переопределенный метод hide() для круга
    void hide() override {
        cout << "Hiding Krug at (" << x << ", " << y << ")" << endl;
    }
};

// Класс Ring (Кольцо), наследуется от Krug
class Ring : public Krug {
private:
    int width; // Толщина кольца
public:
    // Конструктор класса Ring
    Ring(int XN, int YN, int R, int Color, int Wid) : Krug(XN, YN, R, Color), width(Wid) {}

    // Переопределенный метод show() для кольца
    void show() override {
        Krug::show(); // Вызываем метод show() из родительского класса
        cout << "Ring at (" << x << ", " << y << ") with width " << width << endl;
    }
};

// Главная функция программы


int main() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем локализацию для русского языка

    // Оформление вывода (зелёный цвет ФИО и группы)
    std::cout << "\033[32mСкаредин А.В. РИЗ-230916у\033[0m" << std::endl;
    const int SCREEN_WIDTH = 80;  // Ширина консольного "экрана"
    const int SCREEN_HEIGHT = 25; // Высота консольного "экрана"

    Krug krug(40, 12, 5, 1);  // Создаем круг
    Ring ring(30, 10, 9, 5, 1); // Создаем кольцо

    while (true) {
        if (_kbhit()) { // Проверяем, была ли нажата клавиша
            char key = _getch();
            if (key == 27) break; // Если нажата клавиша ESC (код 27), выходим из программы
            krug.move(SCREEN_WIDTH, SCREEN_HEIGHT); // Перемещаем круг
            ring.move(SCREEN_WIDTH, SCREEN_HEIGHT); // Перемещаем кольцо
        }
    }

    return 0; // Завершаем программу
}
