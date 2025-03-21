#include <iostream>
#include <algorithm>

using namespace std;

class Money {
    long dollars;
    int cents;
public:
    Money() {}
    Money(long d, int c)
    {
        dollars = d;
        cents = c;
    }
    int operator>(const Money&) const;
    friend ostream& operator <<(ostream&, Money&);

};
int Money::operator> (const Money& amt) const {
    return
        (dollars > amt.dollars) ||
        ((dollars == amt.dollars) && (cents > amt.cents));
}
ostream& operator<<(ostream& os, Money& amt) {
    os << "$" << amt.dollars << '.' << amt.cents;
    return os;
}

void main30(void) {
    Money mas[] = { Money(19,10),
    Money(99,99),
    Money(99,95),
    Money(19,95)
    };

    sort(mas, mas + sizeof(mas) / sizeof(mas[0]), [](const Money& a, const Money& b) {
        return a > b; 
        });
    for (int i = 0; i < 4; i++)
        cout << "mas[" << i << "] = " << mas[i] << endl;
}