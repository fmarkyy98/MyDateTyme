#pragma once
#include <stdexcept>
#include <string>
#include <iostream>

class Date
{
protected:
	int year = 1970;
	int month = 1;
	int day = 1;

public:
	int numberOfLargestPossibleDay()
	{
		switch (this->month)
		{
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;
		case 2:
			if (this->year % 400 == 0)
			{
				return 29;
			}
			if (this->year % 100 == 0)
			{
				return 28;
			}
			if (this->year % 4 == 0)
			{
				return 29;
			}
			return 28;
			break;
		}
		return 31;
	}

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
		if (1 <= day && day <= this->numberOfLargestPossibleDay())
		{
			this->day = day;
		}
		else
		{
			throw std::invalid_argument("Day should be in [1, " + std::to_string(this->numberOfLargestPossibleDay()) + "] intervall in this month.");
		}
	}

	Date(int year = 1970, int month = 1, int day = 1)
	{
		setYear(year);
		setMonth(month);
		setDay(day);
	}

	void AddYear(const int year)
	{
		this->year += year;
	}

	void AddMonth(const int month)
	{
		this->month += month;
		this->AddYear(this->month / 12);
		this->month %= 12;
	}

	void AddDay(const int day)
	{
		this->day += day;
		this->AddMonth(this->day / this->numberOfLargestPossibleDay());
		this->day %= this->numberOfLargestPossibleDay();
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
		os << d.year << ".";

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
protected:
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
			throw std::invalid_argument("Hour should be in [0, 23] intervall.");
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
			throw std::invalid_argument("Minute should be in [0, 59] intervall.");
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
			throw std::invalid_argument("Hour should be in [0, 59] intervall.");
		}
	}

	Time(int hour = 0, int minute = 0, int second = 0)
	{
		setHour(hour);
		setMinute(minute);
		setSecond(second);
	}

	virtual void AddHour(const int hour)
	{
		this->hour += hour;
		this->hour %= 24;
	}

	void AddMinute(const int minute)
	{
		this->minute += minute;
		this->AddHour(this->minute / 60);
		this->minute %= 60;
	}

	void AddSecond(const int second)
	{
		this->second += second;
		this->AddMinute(this->second / 60);
		this->second %= 60;
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
public:
	DateTime(int year = 1970, int month = 1, int day = 1, int hour = 0, int minute = 0, int second = 0) :
		Date(year, month, day), Time(hour, minute, second) { }

	DateTime(Date date, Time time) : Date(date), Time(time) { }

	Date getDate()
	{
		Date result(this->year, this->month, this->day);
		return result;
	}

	Time getTime()
	{
		Time result(this->hour, this->minute, this->second);
		return result;
	}

	void AddHour(const int hour) override
	{
		this->hour += hour;
		this->AddDay(this->hour / 24);
		this->hour %= 24;
	}

	friend std::istream& operator >> (std::istream& is, DateTime& dt)
	{
		int tmp;
		is >> tmp;
		dt.setYear(tmp);
		is >> tmp;
		dt.setMonth(tmp);
		is >> tmp;
		dt.setDay(tmp);
		is >> tmp;
		dt.setHour(tmp);
		is >> tmp;
		dt.setMinute(tmp);
		is >> tmp;
		dt.setSecond(tmp);
		return is;
	}

	friend std::ostream& operator << (std::ostream& os, DateTime& dt)
	{
		Date date = dt.getDate();
		Time time = dt.getTime();
		os << date << " " << time;
		return os;
	}
};