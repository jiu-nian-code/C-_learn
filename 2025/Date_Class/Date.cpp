#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h""

int Date::GetMonthDay(int year, int month)
{
	assert(0 < year && 0 < month && month < 13);
	int Big_Month[] = { 1, 3, 5, 7, 8, 10, 12 };//大月
	bool result;//记录month是不是大月
	for (auto e : Big_Month)
	{
		if (month == e)
			return 31;//是大月返回31
	}
	if (month != 2)
		return 30;//不是大月也不是2月返回30
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)//判断是不是闰年
	{
		return 29;
	}
	return 28;
}

int Date::GetYearDay(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 366;
	return 365;
}

Date::Date(int year, int month, int day)
{
	assert(0 < year && 0 < month && month < 13 && 0 < day && day < GetMonthDay(year, month) + 1);
	_year = year;
	_month = month;
	_day = day;
}

Date::Date(const Date& d):
	_year(d._year),
	_month(d._month),
	_day(d._day)
{
}

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

Date::~Date()
{
	_year = 0;
	_month = 0;
	_day = 0;
}

Date& Date::operator+=(int day)
{
	_day += day;
	while(_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month > 12)
		{
			_month -= 12;
			++_year;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date obj(*this);
	obj._day += day;
	while (obj._day > GetMonthDay(obj._year, obj._month))
	{
		obj._day -= GetMonthDay(obj._year, obj._month);
		++obj._month;
		if (obj._month > 12)
		{
			obj._month -= 12;
			++obj._year;
		}
	}
	return obj;
}

Date Date::operator-(int day)
{
	Date obj(*this);
	obj._day -= day;
	while (obj._day < 0)
	{
		--obj._month;
		if (obj._month == 0)
		{
			obj._month = 12;
			--obj._year;
		}
		obj._day += GetMonthDay(obj._year, obj._month);
	}
	return obj;
}

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day < 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date& Date::operator++()
{
	++_year;
	++_month;
	++_day;
	return *this;
}

Date Date::operator++(int)
{
	Date ret = *this;
	++_year;
	++_month;
	++_day;
	return ret;
}

Date Date::operator--(int)
{
	Date ret = *this;
	--_year;
	--_month;
	--_day;
	return ret;
}

Date& Date::operator--()
{
	--_year;
	--_month;
	--_day;
	return *this;
}

bool Date::operator>(const Date& d)
{
	if (_year != d._year)//先比年后比月再比日
		return _year > d._year ? true : false;
	if (_month != d._month)
		return _month > d._month ? true : false;
	return _day > d._day ? true : false;
}

bool Date::operator==(const Date& d)
{
	return _day == d._day && _month == d._month && _year == d._year;
}

bool Date::operator >= (const Date& d)
{
	return *this > d || *this == d;
}

bool Date:: operator < (const Date& d)
{
	return !(*this >= d);
}

bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}

bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

int Date::operator-(const Date& d)
{
	if (*this == d)//相等直接返回0
		return 0;
	bool record = true;//记录是要返回正数还是负数
	const Date* Bigger_Date = this;
	const Date* Smaller_Date = &d;
	if (*this < d)//相反就交换
	{
		std::swap(Bigger_Date, Smaller_Date);
		record = false;
	}
	int differ = 0;//相差的天数
	int Year_Differ = Bigger_Date->_year - Smaller_Date->_year;//相差的年数
	while (Year_Differ--)
	{
		differ += GetYearDay(Smaller_Date->_year + Year_Differ);
	}
	int Month_Differ = Bigger_Date->_month - Smaller_Date->_month;//相差的月数
	if (Bigger_Date->_month > Smaller_Date->_month)//补齐年的差距后可能会出现较大的月数比较小的月数小
	{
		while (Month_Differ--)
		{
			differ += GetMonthDay(Bigger_Date->_year, Smaller_Date->_month + Month_Differ);
		}
	}
	else
	{
		while (Month_Differ++)
		{
			differ -= GetMonthDay(Bigger_Date->_year, Bigger_Date->_month - Month_Differ);
		}
	}
	differ += Bigger_Date->_day - Smaller_Date->_day;//补齐日的差距
	return record ? differ : -differ;//根据record选择返回正数还是负数
}