#pragma once

#include <iostream>
#include <assert.h>
using std::cout;
using std::endl;

class Date
{
public:
	inline int GetMonthDay(int year, int month) const
	{
		static int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((month == 2)
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}

		return monthArray[month];
	}

	Date(int year, int month, int day)
	{
		if (year >= 1900
			&& month > 0 && month < 13
			&& day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			//assert(false);
			cout << "�Ƿ�����" << endl;
		}
	}

	// ��ҵ�У�ʵ��һ�¿�����ֵ + ����  ��Ϥ���ǵ��÷�

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	Date& operator++();		// ǰ��++
	Date operator++(int);	// ����++

	Date operator--();		// ǰ��--
	Date operator--(int);	// ����--

	Date operator+(int day) const;
	Date operator-(int day) const;

	Date& operator+=(int day);
	Date& operator-=(int day);

	int operator-(const Date&d);
private:
	int _year;
	int _month;
	int _day;
};

