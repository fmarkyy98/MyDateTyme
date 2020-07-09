#pragma once
#include <stdexcept>
#include <string>
#include <iostream>

class Date
{
private:
	int year = 1970;
	int month = 1;
	int day = 1;

public:
	int getYear() const { return this->year; }
	void setYear(const int year) { this->year = year; }

	int getMonth() const { return this->month; }
	void setMonth(const int month)
	{
		if (1 <= month && month <= 12)
		{
			this->month = month;
		}
		else
		{
			throw std::invalid_argument("Mounth should be in [1, 12] intervall.");
		}
	}

	int getDay() const { return this->day; }
	void setDay(const int day)
	{
		switch (this->month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (1 <= day && day <= 31)
			{
				this->day = day;
			}
			else
			{
				throw std::invalid_argument("Day should be in [1, 31] intervall in this month.");
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (1 <= day && day <= 30)
			{
				this->day = day;
			}
			else
			{
				throw std::invalid_argument("Day should be in [1, 30] intervall in this month.");
			}
			break;
		case 2:
			if ((this->year % 400 == 0 && 1 <= day && day <= 29) ||
				(this->year % 100 == 0 && 1 <= day && day <= 28) ||
				(this->year % 4 == 0 && 1 <= day && day <= 29) ||
				(1 <= day && day <= 28))
			{
				this->day = day;
			}
			else
			{
				throw std::invalid_argument("February can be tricky but hold on! If the current year is divisible by 400, day should be in [1, 29]. If the current year is divisible by 100, day should be in [1, 28]. If the current year is divisible by 4, day should be in [1, 29]. Otherwise day should be in [1, 28].");
			}
			break;
		}
	}

	Date(int year = 1970, int month = 1, int day = 1)
	{
		setYear(year);
		setMonth(month);
		setDay(day);
	}

	friend std::istream& operator >> (std::istream& is, Date& d)
	{
		int tmp;
		is >> tmp;
		d.setYear(tmp);
		is >> tmp;
		d.setMonth(tmp);
		is >> tmp;
		d.setDay(tmp);
		return is;
	}

	friend std::ostream& operator << (std::ostream& os, Date& d)
	{
		os << d.year <<".";

		if (d.month < 10)
		{
			os << "0" << d.month << ".";
		}
		else
		{
			os << d.month << ".";
		}

		if (d.day < 10)
		{
			os << "0" << d.day << ".";
		}
		else
		{
			os << d.day << ".";
		}

		return os;
	}
};

class Time
{
private:
	int hour = 0;
	int minute = 0;
	int second = 0;

public:
	int getHour() const { return this->hour; }
	void setHour(const int hour)
	{
		if (0 <= hour && hour <= 23)
		{
			this->hour = hour;
		}
		else
		{
			throw std::invalid_argument("Hour should be in [1, 23] intervall.");
		}
	}

	int getMinute() const { return this->minute; }
	void setMinute(const int minute)
	{
		if (0 <= minute && minute <= 59)
		{
			this->minute = minute;
		}
		else
		{
			throw std::invalid_argument("Minute should be in [1, 59] intervall.");
		}
	}

	int getSecond() const { return this->second; }
	void setSecond(const int second)
	{
		if (0 <= second && second <= 59)
		{
			this->second = second;
		}
		else
		{
			throw std::invalid_argument("Hour should be in [1, 59] intervall.");
		}
	}

	Time(int hour = 0, int minute = 0, int second = 0)
	{
		setHour(hour);
		setMinute(minute);
		setSecond(second);
	}

	friend std::istream& operator >> (std::istream& is, Time& t)
	{
		int tmp;
		is >> tmp;
		t.setHour(tmp);
		is >> tmp;
		t.setMinute(tmp);
		is >> tmp;
		t.setSecond(tmp);
		return is;
	}

	friend std::ostream& operator << (std::ostream& os, Time& t)
	{
		if (t.hour < 10)
		{
			os << "0" << t.hour << ":";
		}
		else
		{
			os << t.hour << ":";
		}

		if (t.minute < 10)
		{
			os << "0" << t.minute << ":";
		}
		else
		{
			os << t.minute << ":";
		}

		if (t.second < 10)
		{
			os << "0" << t.second;
		}
		else
		{
			os << t.second;
		}

		return os;
	}
};

class DateTime : public Date, public Time
{
	DateTime(int year = 1970, int month = 1, int day = 1, int hour = 0, int minute = 0, int second = 0) :
		Date(year, month, day), Time(hour, minute, second) { }
};