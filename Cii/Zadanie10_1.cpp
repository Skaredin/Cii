#include <iostream>
using namespace std;

struct Node {
    int d;
    Node* next;
};

// Функция для создания первого элемента списка
Node* first(int d) {
    Node* pv = new Node;
    pv->d = d;
    pv->next = nullptr;
    return pv;
}

// Функция для добавления элемента в конец списка
void add(Node** pend, int d) {
    Node* pv = new Node;
    pv->d = d;
    pv->next = nullptr;

    if (*pend) {
        (*pend)->next = pv; // Присоединяем новый элемент к предыдущему
    }
    *pend = pv; // Обновляем указатель на конец списка
}

// Функция для поиска элемента по ключу
Node* find(Node* const pbeg, int d) {
    Node* pv = pbeg;
    while (pv) {
        if (pv->d == d)
            return pv; // Возвращаем найденный элемент
        pv = pv->next;
    }
    return nullptr; // Если не найдено, возвращаем nullptr
}

// Функция для удаления элемента из списка
int remove(Node** pbeg, Node** pend, int key) {
    Node* pkey = find(*pbeg, key);
    if (pkey) {
        if (pkey == *pbeg) { // Если удаляемый элемент - первый
            *pbeg = (*pbeg)->next;
        }
        else {
            Node* prev = *pbeg;
            while (prev->next != pkey) { // Находим предыдущий элемент
                prev = prev->next;
            }
            if (pkey == *pend) { // Если удаляемый элемент - последний
                *pend = prev; // Обновляем указатель на конец списка
            }
            else
                prev->next = pkey->next; // Пропускаем удаляемый элемент

        }
        delete pkey; // Освобождаем память
        return 1; // Успешное удаление
    }
    return 0; // Если элемент не найден
}

// Функция для вставки элемента после заданного значения
Node* insert(Node* const pbeg, Node** pend, int key, int d) {
    Node* pkey = find(pbeg, key);
    if (pkey) {
        Node* newNode = new Node;
        newNode->d = d;
        newNode->next = pkey->next; // Новый узел указывает на следующий за ключом
        pkey->next = newNode; // Связываем новый узел с ключом

        if (*pend == pkey) { // Если вставляем после последнего элемента
            *pend = newNode; // Обновляем указатель на конец списка
        }
        return newNode; // Возвращаем указатель на новый узел
    }
    return nullptr; // Если ключ не найден
}

// Программа для односвязного списка
int main34() {
    // Формирование первого элемента списка
    Node* pbeg = first(1);
    Node* pend = pbeg;

    // Добавление в конец списка четырех элементов 2, 3, 4, 5
    for (int i = 2; i < 6; i++) add(&pend, i);
    Node* pv = pbeg;
    while (pv) {
        cout << pv->d << ' ';
        pv = pv->next;
    }
    cout << endl;

    // Вставка элемента 200 после элемента 2
    insert(pbeg, &pend, 5, 200);

    // Удаление элемента 5
    if (!remove(&pbeg, &pend, 5)) cout << "Элемент не найден" << endl;

    // Вывод списка на экран
    pv = pbeg;
    while (pv) {
        cout << pv->d << ' ';
        pv = pv->next;
    }
    cout << endl;

    return 0;
}
