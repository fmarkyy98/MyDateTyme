#include <iostream>
#include "DateTime.h"

using namespace std;

int main()
{
	Date d1(2020, 7);
	Date d2(2020, 11, 29);
	Time t1(12, 13, 30);

	cout << d1 << endl;
	cout << d2 << endl;
	cout << t1 << endl;
}
