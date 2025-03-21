#include <iostream>
using namespace std;

//������ ��������� "����"
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T data) {
        this->data = data;
        next = nullptr;
    }
};
//������ ������ "����������� �������� ������"
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    // ���������� ��� ������������ ������
    ~LinkedList() {
        clear();
    }
    // ������� ��� �������� ������� �������� ������
    Node<T>* first(T d) {
        Node<T>* newNode = new Node<T>(d);
        //newNode->d = d;
        //newNode->next = nullptr;
        return newNode;
    }
    // ������� ��� ���������� �������� � ����� ������
    void add(T d) {

        if (head == nullptr)
            tail = head = first(d);
        else {
            Node<T>* newNode = new Node<T>(d);

            if (tail) {
                (tail)->next = newNode; // ������������ ����� ������� � �����������
            }
            tail = newNode; // ��������� ��������� �� ����� ������
        }
    }
    // ������� ��� ������ �������� �� �����
    Node<T>* find(T d) {
        Node<T>* current = head;
        while (current) {
            if (current->data == d)
                return current; // ���������� ��������� �������
            current = current->next;
        }
        return nullptr; // ���� �� �������, ���������� nullptr
    }
    // ������� ��� �������� �������� �� ������
    int remove(T key) {
        Node<T>* pkey = find(key);
        if (pkey) {
            if (pkey == head) { // ���� ��������� ������� - ������
                head = head->next;
            }
            else {
                Node<T>* prev = head;
                while (prev->next != pkey) { // ������� ���������� �������
                    prev = prev->next;
                }
                if (pkey == tail) { // ���� ��������� ������� - ���������
                    tail = prev; // ��������� ��������� �� ����� ������
                }
                else
                    prev->next = pkey->next; // ���������� ��������� �������

            }
            delete pkey; // ����������� ������
            return 1; // �������� ��������
        }
        return 0; // ���� ������� �� ������
    }
    // ������� ��� ������� �������� ����� ��������� ��������
    Node<T>* insert(T key, T d) {
        Node<T>* pkey = find(key);
        if (pkey) {
            Node<T>* newNode = new Node<T>(d);
            newNode->next = pkey->next; // ����� ���� ��������� �� ��������� �� ������
            pkey->next = newNode; // ��������� ����� ���� � ������

            if (tail == pkey) { // ���� ��������� ����� ���������� ��������
                tail = newNode; // ��������� ��������� �� ����� ������
            }
            return newNode; // ���������� ��������� �� ����� ����
        }
        return nullptr; // ���� ���� �� ������
    }
    // ����� ��� ������� ������
    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
    // ����� ��� ������ ������ �� �����
    void print() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data << ' ';
            current = current->next;
        }
        cout << endl;
    }
};

int main35() {
    setlocale(LC_ALL, "");

    LinkedList<int> list;

    // ���������� ��������� � ������
    for (int i = 1; i <= 5; ++i) {
        list.add(i);
    }

    // ������� �������� 200 ����� �������� 2
    list.insert(2, 200);

    // ����� ������ �� �����
    list.print();

    return 0;
}

