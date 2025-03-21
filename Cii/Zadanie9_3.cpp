#include <iostream>
using namespace std;
template <class T>
class Tstack {
protected:
    int numItem;
    T* item;
    int size;
public:
    Tstack(int size = 10) : numItem(0), size(size) {
        item = new T[size];
    }

    ~Tstack() {
        delete[] item;
    }

    void push(T t);
    T pop();
    bool isEmpty() const { return numItem == 0; }
    T getTopElement() { return item[numItem - 1]; }
    int getCount() { return numItem; }
};

template <class T>
void Tstack<T>::push(T t) {
    if (numItem < size) {
        item[numItem++] = t;
    }
    else {
        cout << "Stack overflow!" << endl;
    }
}

template <class T>
T Tstack<T>::pop() {
    if (numItem > 0) {
        return item[--numItem];
    }
    else {
        cout << "Stack underflow!" << endl;
        return T(); 
    }
}
//���������� �/� ������� � �������������� ������
int main33() {
    setlocale(LC_ALL, "");
    const int n = 3; // ���������� �������
    int arr[n] = { 1,5,3 }; // �������� ������ �������

    Tstack<int> stack(n); // ���� ��� ���������� �������� �������
    Tstack<int> result(n); // ���� ��� ��������������� �������

    // ����������� ������� � ����
    for (int i = 0; i < n; i++) {
        stack.push(arr[i]);
    }

    // ���������� ������� �� ����� � ����������
    while (!stack.isEmpty()) {
        int temp = stack.pop();

        // ����������� ������ � ��������� � ��������������� �������
        while (!result.isEmpty() && result.getTopElement() > temp) {
            stack.push(result.pop());
        }
        result.push(temp);
    }

    // ����� ��������������� �������
    cout << "��������������� ������: ";
    while (!result.isEmpty()) {
        cout << result.pop() << " ";
    }
    cout << endl;
    return 0;
}