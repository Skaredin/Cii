#include <iostream>
using namespace std;

//шаблон структоры "узел"
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T data) {
        this->data = data;
        next = nullptr;
    }
};
//шаблон класса "односвязный линейный список"
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    // Деструктор для освобождения памяти
    ~LinkedList() {
        clear();
    }
    // Функция для создания первого элемента списка
    Node<T>* first(T d) {
        Node<T>* newNode = new Node<T>(d);
        //newNode->d = d;
        //newNode->next = nullptr;
        return newNode;
    }
    // Функция для добавления элемента в конец списка
    void add(T d) {

        if (head == nullptr)
            tail = head = first(d);
        else {
            Node<T>* newNode = new Node<T>(d);

            if (tail) {
                (tail)->next = newNode; // Присоединяем новый элемент к предыдущему
            }
            tail = newNode; // Обновляем указатель на конец списка
        }
    }
    // Функция для поиска элемента по ключу
    Node<T>* find(T d) {
        Node<T>* current = head;
        while (current) {
            if (current->data == d)
                return current; // Возвращаем найденный элемент
            current = current->next;
        }
        return nullptr; // Если не найдено, возвращаем nullptr
    }
    // Функция для удаления элемента из списка
    int remove(T key) {
        Node<T>* pkey = find(key);
        if (pkey) {
            if (pkey == head) { // Если удаляемый элемент - первый
                head = head->next;
            }
            else {
                Node<T>* prev = head;
                while (prev->next != pkey) { // Находим предыдущий элемент
                    prev = prev->next;
                }
                if (pkey == tail) { // Если удаляемый элемент - последний
                    tail = prev; // Обновляем указатель на конец списка
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
    Node<T>* insert(T key, T d) {
        Node<T>* pkey = find(key);
        if (pkey) {
            Node<T>* newNode = new Node<T>(d);
            newNode->next = pkey->next; // Новый узел указывает на следующий за ключом
            pkey->next = newNode; // Связываем новый узел с ключом

            if (tail == pkey) { // Если вставляем после последнего элемента
                tail = newNode; // Обновляем указатель на конец списка
            }
            return newNode; // Возвращаем указатель на новый узел
        }
        return nullptr; // Если ключ не найден
    }
    // Метод для очистки списка
    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
    // Метод для вывода списка на экран
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

    // Добавление элементов в список
    for (int i = 1; i <= 5; ++i) {
        list.add(i);
    }

    // Вставка элемента 200 после элемента 2
    list.insert(2, 200);

    // Вывод списка на экран
    list.print();

    return 0;
}

