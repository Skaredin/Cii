#include <iostream>
#include <string.h>

using namespace std;

//шаблон структоры "узел"
template <typename T>
struct Node {
    T data;
    Node* next;
public:
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

    Node<T>* first(T d) {
        // Функция для создания первого элемента списка
        Node<T>* newNode = new Node<T>(d);
        return newNode;
    }
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    // Деструктор для освобождения памяти
    ~LinkedList() {
        clear();
    }
    Node<T>* getHead() {
        return head;
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
            cout << current->data << endl;
            current = current->next;
        }
        cout << endl;
    }
};
//класс автобус
class Bus {
    string number;
    string driverName;
    string driverSurname;
    int route;

public:
    Bus() :number(""), driverName(""), driverSurname(""), route(-1) {}
    Bus(string number, string driverName, string driverSurname, int route) :
        number(number), driverName(driverName), driverSurname(driverSurname), route(route) {};

    //методы доступа
    string getNumber() const { return number; }
    string getDriverName() const { return driverName; }
    string getDriverSurname() const { return driverSurname; }
    int getRoute() const { return route; }

    // Переопределение оператора вывода
    friend ostream& operator<<(ostream& os, const Bus& bus) {
        os << "Bus Number: " << bus.number << ", Driver: " << bus.driverName << " " << bus.driverSurname << ", Route: " << bus.route;
        return os;
    }
    bool operator==(const Bus& bus) {
        if (number == bus.number && driverName == bus.driverName && driverSurname == bus.driverSurname && route == bus.route)
            return true;
        else return false;
    }

};
//класс автобусный парк
class BusPark {
    int countInpark;
    int countOnRoute;
    LinkedList<Bus> inPark;// автобусы в парке
    LinkedList<Bus> onRoute;// автобусы на маршруте

public:
    BusPark() {
        countInpark = countOnRoute = 0;
    }
    BusPark(Bus buses[], int countInpark) :BusPark() {
        this->countInpark = countInpark;
        for (int i = 0; i < countInpark; i++)
            inPark.add(buses[i]);
    }
    void addBusInPark(const string& num, const string& name, const string& surname, int rt) {
        inPark.add(Bus(num, name, surname, rt));
        countInpark++;
    }
    //выезд автобуса
    void busDeparture(const string& num) {

        Bus bus;
        Node<Bus>* node = inPark.getHead();

        for (int i = 0; i < countInpark; i++)
        {
            bus = node->data;
            if (bus.getNumber() == num) {
                inPark.remove(bus);
                onRoute.add(bus);// Добавляем автобус на маршрут
                countInpark--;
                countOnRoute++;
                return;
            }
            node = node->next;
        }

        cout << "Автобус с номером " << num << " не найден в парке." << endl;
    }
    //заезд автобуса
    void busArrival(const string& num) {
        Bus bus;
        Node<Bus>* node = onRoute.getHead();

        for (int i = 0; i < countOnRoute; i++)
        {
            bus = node->data;
            if (bus.getNumber() == num) {
                onRoute.remove(bus);
                inPark.add(bus);// Добавляем автобус в парк
                countInpark++;
                countOnRoute--;
                return;
            }
            node = node->next;
        }

        cout << "Автобус с номером " << num << " в поездке не найден ." << endl;
    }

    void printBusesInPark() const {
        cout << "Автобусы в парке:" << endl;
        inPark.print();
    }

    void printBusesOnRoute() const {
        cout << "Автобусы на маршруте:" << endl;
        onRoute.print();
    }
};

int main()
{
    setlocale(LC_ALL, "");
    Bus buses[] = { Bus("1", "name1", "surname1", 1),Bus("2", "name2", "surname2", 2),
    Bus("3", "name3", "surname3", 3), Bus("4", "name4", "surname4", 4), Bus("5", "name5", "surname5", 5),
    Bus("6", "name6", "surname6", 6) };

    BusPark park(buses, 6);

    park.busDeparture("1");
    park.busDeparture("4");
    park.busDeparture("3");

    park.printBusesInPark();
    park.printBusesOnRoute();

    park.busArrival("1");
    park.printBusesInPark();
    park.printBusesOnRoute();

    park.busArrival("1");
    park.busArrival("4");
    park.busArrival("3");
    park.printBusesInPark();
    park.printBusesOnRoute();

}






