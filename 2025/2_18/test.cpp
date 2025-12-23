#include <iostream>

#include<stdlib.h>

#include <iomanip>

using namespace std;

class Date
{
public:
    int GetMonthDay(int year, int month)
    {
        // assert(0 < year && 0 < month && month < 13);
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

    int GetYearDay(int year)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            return 366;
        return 365;
    }

    Date(int year = 1900, int month = 1, int day = 1)
    {
        // assert(0 < year && 0 < month && month < 13 && 0 < day && day < GetMonthDay(year, month) + 1);
        _year = year;
        _month = month;
        _day = day;
    }

    Date(const Date& d) :
        _year(d._year),
        _month(d._month),
        _day(d._day)
    {
    }

    Date& operator=(const Date& d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
        return *this;
    }

    ~Date()
    {
        _year = 0;
        _month = 0;
        _day = 0;
    }

    Date& operator+=(int day)
    {
        _day += day;
        while (_day > GetMonthDay(_year, _month))
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


    bool operator>(const Date& d)
    {
        if (_year != d._year)//先比年后比月再比日
            return _year > d._year ? true : false;
        if (_month != d._month)
            return _month > d._month ? true : false;
        return _day > d._day ? true : false;
    }

    bool operator==(const Date& d)
    {
        return _day == d._day && _month == d._month && _year == d._year;
    }

    bool operator >= (const Date& d)
    {
        return *this > d || *this == d;
    }

    bool operator < (const Date& d)
    {
        return !(*this >= d);
    }

    bool operator <= (const Date& d)
    {
        return !(*this > d);
    }

    bool operator != (const Date& d)
    {
        return !(*this == d);
    }

    int operator-(const Date& d)
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
        return record ? differ : differ;//根据record选择返回正数还是负数
    }
    void print()
    {
        cout << _year << setfill('0') << setw(2) << _month << setfill('0') << setw(2) << _day << endl;
    }
private:
    int _year;
    int _month;
    int _day;
};

//int main()
//{
//    int num = 0;
//    cin >> num;
//    Date* Date_Arr = (Date*)malloc(num * sizeof(Date));
//    int In_Year;
//    int In_Month;
//    int In_Day;
//    int In_Add;
//    for (int i = 0; i < num; ++i)
//    {
//        cin >> In_Year >> In_Month >> In_Day >> In_Add;
//        new(Date_Arr + i) Date(In_Year, In_Month, In_Day);
//        *(Date_Arr + i) += In_Add;
//    }
//    for (int i = 0; i < num; ++i)
//    {
//        (*(Date_Arr + i)).print();
//    }
//}
// 64 位输出请用 printf("%lld")


class Solution
{
public:
    int myAtoi(string str)
    {
        string::iterator it = str.begin();//迭代器读取
        while (*it == '0' || *it == 32)//检查空格和0
        {
            ++it;
        }
        int symbol = 1;//正负符号记录
        if (*it == '-' || *it == '+')
        {
            if (*it == '-')
                symbol = -1;
            ++it;
        }
        while (*it == '0')//检查空格和0
        {
            ++it;
        }
        int result = 0;//最终结果
        while (47 < *it && *it < 58)//有效字符范围
        {
            if (result > 214748364 || (result == 214748364 && *it >= 56))
            {
                return symbol > 0 ? 2147483647 : -2147483648;
            }
            result = result * 10 + ((*it) - 48);
            ++it;
        }
        return symbol * result;
    }
};

int main()
{
    //Solution().myAtoi("2147483646");
    Solution().myAtoi("-2147483648");
}