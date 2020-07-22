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
	DateTime dt;

	dt.AddSecond(30);
	CHECK(dt.getSecond() == 30);
	CHECK(dt.getMinute() == 0);
	CHECK(dt.getHour() == 0);
	CHECK(dt.getDay() == 1);
	CHECK(dt.getMonth() == 1);
	CHECK(dt.getYear() == 1970);

	dt.AddMinute(30);
	CHECK(dt.getSecond() == 30);
	CHECK(dt.getMinute() == 30);
	CHECK(dt.getHour() == 0);
	CHECK(dt.getDay() == 1);
	CHECK(dt.getMonth() == 1);
	CHECK(dt.getYear() == 1970);

	dt.AddHour(12);
	CHECK(dt.getSecond() == 30);
	CHECK(dt.getMinute() == 30);
	CHECK(dt.getHour() == 12);
	CHECK(dt.getDay() == 1);
	CHECK(dt.getMonth() == 1);
	CHECK(dt.getYear() == 1970);

	dt.AddDay(15);
	CHECK(dt.getSecond() == 30);
	CHECK(dt.getMinute() == 30);
	CHECK(dt.getHour() == 12);
	CHECK(dt.getDay() == 16);
	CHECK(dt.getMonth() == 1);
	CHECK(dt.getYear() == 1970);

	dt.AddMonth(4);
	CHECK(dt.getSecond() == 30);
	CHECK(dt.getMinute() == 30);
	CHECK(dt.getHour() == 12);
	CHECK(dt.getDay() == 16);
	CHECK(dt.getMonth() == 5);
	CHECK(dt.getYear() == 1970);

	dt.AddYear(50);
	CHECK(dt.getSecond() == 30);
	CHECK(dt.getMinute() == 30);
	CHECK(dt.getHour() == 12);
	CHECK(dt.getDay() == 16);
	CHECK(dt.getMonth() == 5);
	CHECK(dt.getYear() == 2020);
}

TEST_CASE("Adding the maximum value of signed integer in seconds.")
{
	DateTime dt;
	dt.AddSecond(0x7FFFFFFF);
	CHECK(dt.getSecond() == 7);
	CHECK(dt.getMinute() == 14);
	CHECK(dt.getHour() == 3);
	CHECK(dt.getDay() == 19);
	CHECK(dt.getMonth() == 1);
	CHECK(dt.getYear() == 2038);
}

TEST_CASE("Chacking some leapday handleing.")
{
	Date d1(4, 2);
	d1.AddDay(365);
	CHECK(d1.getDay() == 31);
	CHECK(d1.getMonth() == 1);
	CHECK(d1.getYear() == 5);

	Date d2(100, 2);
	d2.AddDay(365);
	CHECK(d2.getDay() == 1);
	CHECK(d2.getMonth() == 2);
	CHECK(d2.getYear() == 101);

	Date d3(400, 2, 17);
	d3.AddDay(365);
	CHECK(d3.getDay() == 16);
	CHECK(d3.getMonth() == 2);
	CHECK(d3.getYear() == 401);
}

TEST_CASE("Adding months is semms bugy to me.") // So I found the bug :D
{
	Date d(0);
	d.AddMonth(48);
	CHECK(d.getDay() == 1);
	CHECK(d.getMonth() == 1);
	CHECK(d.getYear() == 4);
}

#endif


