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
Date& Date::operator++()	// 前置++
{
	*this += 1;
	return *this;
}

// d++
Date Date::operator++(int) // 后置++
{
	Date ret(*this);
	*this += 1;
	return ret;
}

//
Date Date::operator--()		// 前置--
{
	return *this -= 1;
}
Date Date::operator--(int)	// 后置--
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
	int year = (day / 365) + 1;//把要减去的天数转化为年数
	Date start(_year - year, 1, 1);//设置初始日期,至少早于减去day之后的日期
	int dec = *this - start;//初始日期与当前日期之间差多少天
	start += (dec - day);//相当于把原来的日期减去day
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