#include <iostream>
#include <string.h>

using namespace std;

//������ ��������� "����"
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
//������ ������ "����������� �������� ������"
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

    Node<T>* first(T d) {
        // ������� ��� �������� ������� �������� ������
        Node<T>* newNode = new Node<T>(d);
        return newNode;
    }
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    // ���������� ��� ������������ ������
    ~LinkedList() {
        clear();
    }
    Node<T>* getHead() {
        return head;
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
            cout << current->data << endl;
            current = current->next;
        }
        cout << endl;
    }
};
//����� �������
class Bus {
    string number;
    string driverName;
    string driverSurname;
    int route;

public:
    Bus() :number(""), driverName(""), driverSurname(""), route(-1) {}
    Bus(string number, string driverName, string driverSurname, int route) :
        number(number), driverName(driverName), driverSurname(driverSurname), route(route) {};

    //������ �������
    string getNumber() const { return number; }
    string getDriverName() const { return driverName; }
    string getDriverSurname() const { return driverSurname; }
    int getRoute() const { return route; }

    // ��������������� ��������� ������
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
//����� ���������� ����
class BusPark {
    int countInpark;
    int countOnRoute;
    LinkedList<Bus> inPark;// �������� � �����
    LinkedList<Bus> onRoute;// �������� �� ��������

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
    //����� ��������
    void busDeparture(const string& num) {

        Bus bus;
        Node<Bus>* node = inPark.getHead();

        for (int i = 0; i < countInpark; i++)
        {
            bus = node->data;
            if (bus.getNumber() == num) {
                inPark.remove(bus);
                onRoute.add(bus);// ��������� ������� �� �������
                countInpark--;
                countOnRoute++;
                return;
            }
            node = node->next;
        }

        cout << "������� � ������� " << num << " �� ������ � �����." << endl;
    }
    //����� ��������
    void busArrival(const string& num) {
        Bus bus;
        Node<Bus>* node = onRoute.getHead();

        for (int i = 0; i < countOnRoute; i++)
        {
            bus = node->data;
            if (bus.getNumber() == num) {
                onRoute.remove(bus);
                inPark.add(bus);// ��������� ������� � ����
                countInpark++;
                countOnRoute--;
                return;
            }
            node = node->next;
        }

        cout << "������� � ������� " << num << " � ������� �� ������ ." << endl;
    }

    void printBusesInPark() const {
        cout << "�������� � �����:" << endl;
        inPark.print();
    }

    void printBusesOnRoute() const {
        cout << "�������� �� ��������:" << endl;
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






