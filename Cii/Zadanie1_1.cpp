
#include <iostream>
using namespace std;
void main(void)//Что бы конфиликта не было, нужно main изменить, так как метод 1 (Я добавляю 1(в конце) если нужно другой метод, то тут ставлю 1, а в другом убираю !)
{
	int i, k;
	int power(int, int);

	for (i = 0; i < 10; i++)
	{
		k = power(2, i);
		std::cout << "i = " << i << ", k = " << k << endl;
	}
}
int power(int x, int n)
{
	int i, p = 1;
	for (i = 1; i < n; i++) p *= x;
	return p;
}

