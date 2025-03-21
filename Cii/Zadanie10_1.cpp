#include <iostream>
using namespace std;

struct Node {
    int d;
    Node* next;
};

// ������� ��� �������� ������� �������� ������
Node* first(int d) {
    Node* pv = new Node;
    pv->d = d;
    pv->next = nullptr;
    return pv;
}

// ������� ��� ���������� �������� � ����� ������
void add(Node** pend, int d) {
    Node* pv = new Node;
    pv->d = d;
    pv->next = nullptr;

    if (*pend) {
        (*pend)->next = pv; // ������������ ����� ������� � �����������
    }
    *pend = pv; // ��������� ��������� �� ����� ������
}

// ������� ��� ������ �������� �� �����
Node* find(Node* const pbeg, int d) {
    Node* pv = pbeg;
    while (pv) {
        if (pv->d == d)
            return pv; // ���������� ��������� �������
        pv = pv->next;
    }
    return nullptr; // ���� �� �������, ���������� nullptr
}

// ������� ��� �������� �������� �� ������
int remove(Node** pbeg, Node** pend, int key) {
    Node* pkey = find(*pbeg, key);
    if (pkey) {
        if (pkey == *pbeg) { // ���� ��������� ������� - ������
            *pbeg = (*pbeg)->next;
        }
        else {
            Node* prev = *pbeg;
            while (prev->next != pkey) { // ������� ���������� �������
                prev = prev->next;
            }
            if (pkey == *pend) { // ���� ��������� ������� - ���������
                *pend = prev; // ��������� ��������� �� ����� ������
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
Node* insert(Node* const pbeg, Node** pend, int key, int d) {
    Node* pkey = find(pbeg, key);
    if (pkey) {
        Node* newNode = new Node;
        newNode->d = d;
        newNode->next = pkey->next; // ����� ���� ��������� �� ��������� �� ������
        pkey->next = newNode; // ��������� ����� ���� � ������

        if (*pend == pkey) { // ���� ��������� ����� ���������� ��������
            *pend = newNode; // ��������� ��������� �� ����� ������
        }
        return newNode; // ���������� ��������� �� ����� ����
    }
    return nullptr; // ���� ���� �� ������
}

// ��������� ��� ������������ ������
int main34() {
    // ������������ ������� �������� ������
    Node* pbeg = first(1);
    Node* pend = pbeg;

    // ���������� � ����� ������ ������� ��������� 2, 3, 4, 5
    for (int i = 2; i < 6; i++) add(&pend, i);
    Node* pv = pbeg;
    while (pv) {
        cout << pv->d << ' ';
        pv = pv->next;
    }
    cout << endl;

    // ������� �������� 200 ����� �������� 2
    insert(pbeg, &pend, 5, 200);

    // �������� �������� 5
    if (!remove(&pbeg, &pend, 5)) cout << "������� �� ������" << endl;

    // ����� ������ �� �����
    pv = pbeg;
    while (pv) {
        cout << pv->d << ' ';
        pv = pv->next;
    }
    cout << endl;

    return 0;
}
