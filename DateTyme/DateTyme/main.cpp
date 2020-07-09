#include <iostream>
#include "DateTime.h"

using namespace std;

int main()
{
	Date d1(2020, 7);
	Date d2(2020, 11, 29);
	Time t1(12, 30);

	DateTime dt1(2020, 7, 9, 12, 30);
	DateTime dt2;

	cout << d1 << endl;
	cout << d2 << endl;
	cout << t1 << endl;
	cout << dt1 << endl;
	cout << dt2 << endl;
	dt2.AddSecond(2147483647);
	cout << dt2 << endl;
}
