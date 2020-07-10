#include <iostream>
#include "DateTime.h"

using namespace std;

//#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{
	Date d1(2020, 7);
	Date d2(2020, 11, 29);
	Time t1(12, 30);

	DateTime dt1(2020, 7, 9, 12, 30);
	DateTime dt2(4, 2);

	cout << d1 << endl;
	cout << d2 << endl;
	cout << t1 << endl;
	cout << dt1 << endl;
	cout << dt2 << endl;
	dt2.AddDay(365);
	cout << dt2 << endl;
}
#else

#define CATCH_CONFIG_MAIN

#include "../Test/src/catch.hpp"

TEST_CASE("Adding non owerflowing values.")
{
	DateTime dt1;

	dt1.AddSecond(30);
	CHECK(dt1.getSecond() == 30);
	CHECK(dt1.getMinute() == 0);
	CHECK(dt1.getHour() == 0);
	CHECK(dt1.getDay() == 1);
	CHECK(dt1.getMonth() == 1);
	CHECK(dt1.getYear() == 1970);

	dt1.AddMinute(30);
	CHECK(dt1.getSecond() == 30);
	CHECK(dt1.getMinute() == 30);
	CHECK(dt1.getHour() == 0);
	CHECK(dt1.getDay() == 1);
	CHECK(dt1.getMonth() == 1);
	CHECK(dt1.getYear() == 1970);

	dt1.AddHour(12);
	CHECK(dt1.getSecond() == 30);
	CHECK(dt1.getMinute() == 30);
	CHECK(dt1.getHour() == 12);
	CHECK(dt1.getDay() == 1);
	CHECK(dt1.getMonth() == 1);
	CHECK(dt1.getYear() == 1970);

	dt1.AddDay(15);
	CHECK(dt1.getSecond() == 30);
	CHECK(dt1.getMinute() == 30);
	CHECK(dt1.getHour() == 12);
	CHECK(dt1.getDay() == 16);
	CHECK(dt1.getMonth() == 1);
	CHECK(dt1.getYear() == 1970);

	dt1.AddMonth(4);
	CHECK(dt1.getSecond() == 30);
	CHECK(dt1.getMinute() == 30);
	CHECK(dt1.getHour() == 12);
	CHECK(dt1.getDay() == 16);
	CHECK(dt1.getMonth() == 5);
	CHECK(dt1.getYear() == 1970);

	dt1.AddYear(50);
	CHECK(dt1.getSecond() == 30);
	CHECK(dt1.getMinute() == 30);
	CHECK(dt1.getHour() == 12);
	CHECK(dt1.getDay() == 16);
	CHECK(dt1.getMonth() == 5);
	CHECK(dt1.getYear() == 2020);
}

#endif


