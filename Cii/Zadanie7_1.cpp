#include <iostream>  // ����������� ���������� ��� ������ � ������-�������
#include <cstdlib>   // ����������� ���������� ��� ������ �� ���������� �������
#include <ctime>     // ����������� ���������� ��� ������ � ��������
#include <conio.h>   // ����������� ���������� ��� ������ � ������������ ������ (_kbhit(), _getch())
#include <locale> // ��� ��������� �������� �����
using namespace std; // ������������� ������������ ������������ ����

// ������� ����� Point (�����)
class Point {
protected:
    int x, y;   // ���������� �����
    int color;  // ���� �����
public:
    // ����������� ������, �������������� ���������� � ����
    Point(int XN, int YN, int Color) : x(XN), y(YN), color(Color) {}

    // ����������� ����� ��� ����������� �����
    virtual void show() { cout << "Point at (" << x << ", " << y << ") with color " << color << endl; }

    // ����������� ����� ��� ������� �����
    virtual void hide() { cout << "Hiding Point at (" << x << ", " << y << ")" << endl; }

    // ����� ��� ����������� ����� � �������� ������
    void move(int maxX, int maxY);
};

// ���������� ������ move() ������ Point
void Point::move(int maxX, int maxY) {
    int dx, dy;
    srand(time(0)); // ������������� ���������� ��������� �����

    do {
        dx = rand() % 3 - 1; // ��������� �������� �� X (-1, 0, 1)
        dy = rand() % 3 - 1; // ��������� �������� �� Y (-1, 0, 1)

        hide(); // �������� ������ ����� ������������
        x = max(0, min(x + dx, maxX)); // ������������ ���������� � �������� ������
        y = max(0, min(y + dy, maxY));
        show(); // ���������� ������ ����� �����������

    } while (!_kbhit()); // ���� ������� �������
    _getch(); // ������� ������������� �����
}

// ����� Krug (����), ����������� �� Point
class Krug : public Point {
private:
    int radius; // ������ �����
public:
    // ����������� ������ Krug
    Krug(int XN, int YN, int R, int Color) : Point(XN, YN, Color), radius(R) { show(); }

    // ���������������� ����� show() ��� �����
    void show() override {
        cout << "Krug at (" << x << ", " << y << ") with radius " << radius << " and color " << color << endl;
    }

    // ���������������� ����� hide() ��� �����
    void hide() override {
        cout << "Hiding Krug at (" << x << ", " << y << ")" << endl;
    }
};

// ����� Ring (������), ����������� �� Krug
class Ring : public Krug {
private:
    int width; // ������� ������
public:
    // ����������� ������ Ring
    Ring(int XN, int YN, int R, int Color, int Wid) : Krug(XN, YN, R, Color), width(Wid) {}

    // ���������������� ����� show() ��� ������
    void show() override {
        Krug::show(); // �������� ����� show() �� ������������� ������
        cout << "Ring at (" << x << ", " << y << ") with width " << width << endl;
    }
};

// ������� ������� ���������


int main() {
    setlocale(LC_ALL, "Russian"); // ������������� ����������� ��� �������� �����

    // ���������� ������ (������ ���� ��� � ������)
    std::cout << "\033[32m�������� �.�. ���-230916�\033[0m" << std::endl;
    const int SCREEN_WIDTH = 80;  // ������ ����������� "������"
    const int SCREEN_HEIGHT = 25; // ������ ����������� "������"

    Krug krug(40, 12, 5, 1);  // ������� ����
    Ring ring(30, 10, 9, 5, 1); // ������� ������

    while (true) {
        if (_kbhit()) { // ���������, ���� �� ������ �������
            char key = _getch();
            if (key == 27) break; // ���� ������ ������� ESC (��� 27), ������� �� ���������
            krug.move(SCREEN_WIDTH, SCREEN_HEIGHT); // ���������� ����
            ring.move(SCREEN_WIDTH, SCREEN_HEIGHT); // ���������� ������
        }
    }

    return 0; // ��������� ���������
}
