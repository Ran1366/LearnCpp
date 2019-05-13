#include "date.h"

bool Date::operator>(const Date& d) const
{
	if (_year > d._year)
	{
		return true;
	}
	else if(_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if(_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	else
	{
		return false;
	}
}
bool Date::operator==(const Date& d) const
{
	return (_year == d._year && _month == d._month && _day == d._day);
}
bool Date::operator>=(const Date& d) const
{
	return *this > d && *this == d;
}
bool Date::operator<(const Date& d) const
{
	return !(*this >= d);
}
bool Date::operator<=(const Date& d) const
{
	return !(*this > d);
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

// ++d
Date& Date::operator++()	// ǰ��++
{
	*this += 1;
	return *this;
}

// d++
Date Date::operator++(int) // ����++
{
	Date ret(*this);
	*this += 1;
	return ret;
}

//
Date Date::operator--()		// ǰ��--
{
	return *this -= 1;
}
Date Date::operator--(int)	// ����--
{
	Date ret = *this;
	*this -= 1;
	return ret;
}

Date Date::operator+(int day) const
{
	Date ret = *this;
	ret += day;
	return ret;
}

Date& Date::operator+=(int day)
{
	//if (day < 0)
	//	return *this -= -day;

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}

	return *this;
}

Date Date::operator-(int day) const
{
	Date ret = *this;
	ret -= day;
	return ret;
}
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	int year = (day / 365) + 1;//��Ҫ��ȥ������ת��Ϊ����
	Date start(_year - year, 1, 1);//���ó�ʼ����,�������ڼ�ȥday֮�������
	int dec = *this - start;//��ʼ�����뵱ǰ����֮��������
	start += (dec - day);//�൱�ڰ�ԭ�������ڼ�ȥday
	return *this = start;
}
//
int Date::operator-(const Date&d)
{
	int dec = 0;
	if (*this > d)
	{
		Date ret = d;
		while (ret != *this)
		{
			++ret;
			++dec;
		}
		return dec;
	}
	else
	{
		Date ret = *this;
		while (ret != d)
		{
			++ret;
			++dec;
		}
		return -dec;
	}
	
}