#include <iostream>
using namespace std;

#if 0
// ��ʼ���б����ã���ʼ�����еĳ�Ա����������ÿ����Ա����ֻ���ڳ�ʼ���б��г���һ��
class Date
{
public:
	Date(int year, int month, int day) 
		: _year(year)
		, _month(month)
		, _day(day)
		, a(10)
		, b(_year)
	{
		// ���캯�����У�����ֵ
		_year = year;
		_month = month;
		_day = day;
		//a = 10;
	}

private:
	int _year;
	int _month;
	int _day;

	const int a;
	int& b;
};

int main()
{
	const int a = 10;
	return 0;
}
#endif


#if 0
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		//, _t(19,24,30)// , _t()
	{
		cout << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{

	// Date d1(2019, 9, 16);
	return 0;
}
#endif

#if 0
// ���飺������Ҫʹ�ó�Ա��ʼ����Ա
//      ��ʼ���б��г�Ա�ĳ��ִ���������������е��������򱣳�һ��
class Date
{
public:
	Date(int year, int day)
		: _year(year)
		, _day(day)
		, _month(_day)
	{
		cout << this << endl;
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

	void TestFunc(int year)
	{}

private:
	int _year;
	int _month;
	int _day;
};
#endif

#if 0
class Date
{
public:
	// �������͵Ĺ��캯����������ת��������
	// explicit: ���ε��ι��캯������˼�ǽ�ֹ���ι��캯������ת��������
	explicit Date(int year)
		: _year(year)
	{
		cout << this << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << this << " = " << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{

	Date d1(2018);
	d1 = 2019;
	return 0;
}
#endif


// Date�ܹ������˶��ٸ���Ч����
// ���칹��  �������캯�� ��������  
// ������Ҫ���������ĸ���---����--int

#if 0
int _count = 0;
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(_day)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		++_count;
	}

	~Date()
	{
		_count--;
	}

private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	cout << _count << endl;
}

int main()
{
	Date d1(2019, 9, 16);
	Date d2(d1);
	cout << _count << endl;

	_count = 0;
	TestDate();

	_count = 100;
	cout << _count << endl;
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(_day)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		++_count;
	}

	~Date()
	{
		_count--;
	}

private:
	int _year;
	int _month;
	int _day;

public:
	static int _count;
};

int Date::_count = 0;

void TestDate()
{
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	
}

int main()
{
	Date d1(2019, 9, 16);
	Date d2(d1);
	
	// ��̬��Ա�����������������ĳ�Ա����
	// ������ĳ������Ķ���
	cout << &d1._count << " " << &d2._count << endl;
	
	// ��̬��Ա�������������
	cout << Date::_count << endl;

	cout << sizeof(Date) << endl;
	TestDate();

	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(_day)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		++_count;
	}

	~Date()
	{
		_count--;
	}

	void TestFunc()
	{
		_day++;
		cout << _count << endl;
		GetCount();
	}


	static int GetCount()
	{
		//TestFunc();
		//cout << this << endl;
		//_day++;
		return _count;
	}

private:
	int _year;
	int _month;
	int _day;
	static int _count;
};

int Date::_count = 0;

void TestDate()
{
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	cout << Date::GetCount() << endl;
}

int main()
{
	cout << Date::GetCount() << endl;
	Date d1(2019, 9, 16);
	Date d2(d1);

	cout << Date::GetCount() << endl;
	TestDate();
	cout << Date::GetCount() << endl;
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(_day)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		++_count;
	}

	~Date()
	{
		_count--;
	}

	void TestFunc()
	{
		_day++;
		cout << _count << endl;
		GetCount();
	}


	static int GetCount()
	{
		//TestFunc();
		//cout << this << endl;
		//_day++;
		return _count;
	}

private:
	int _year;
	int _month;
	int _day;
	static int _count;
};



int Date::_count = 0;


int main()
{
	int sum = 0;

	Date d1(2019,9,16);
	sum += Date::GetCount();

	Date d2(d1);
	sum += Date::GetCount();

	Date d3(d1);
	sum += Date::GetCount();
	return 0;
}
#endif

#if 0
class Time
{
	friend class Date;
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;

	friend void Print();
};

class Date
{
private:
	friend ostream& operator<<(ostream& _cout, const Date& d);

public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(_day)
		, _day(day)
	{}

	void PrintDate()const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	// ��<<�����������س���ĳ�Ա���������һ������Ϊthis
	// ��˵��÷�ʽ�볣��Ĵ�ӡ��ʽ����
// 	void operator<<(ostream& _cout)
// 	{
// 		_cout << _year << "-" << _month << "-" << _day;
// 	}

	void TestFunc()
	{
		_t._hour = 1;
		_t._minute = 1;
		_t._second = 1;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;

	friend void Print();
};



// ˵�����������س�ȫ�ֺ���
//      ��һ������������ostream&,�ڶ�������ΪҪ���������(�Զ������͵Ķ���const)
//      ����Ҫ�з���ֵ----�������
//      ������Ҫ�ڸú�������һЩ��ʽ����---���绻��
//      �����������������ó������Ԫ����
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}


void Print()
{
	Date d(2019, 9, 18);
	cout << d._year << endl;

	Time t;
	cout << t._hour << endl;
}

int main()
{
	
	Date d(2019, 9, 18);
	d.PrintDate();
	//d.operator<<(cout);
	//d << cout;
	cout << d << endl;

	//cout << d<<13<<0<<endl;
	return 0;
}
#endif


#if 0
class A
{
public:
	A(int a)
		: _a(a)
	{}

	class B
	{
	public:
		B(int b)
			: _b(b)
		{}

		void TestFunc()
		{
			A a(1);
			a._a = 10;

			A::_c = 10;
		}

	private:
		int _b;
	};

private:
	int _a;
	static int _c;
};

int A::_c = 0;


int main()
{
	A::B b(10);
	// ע�⣺�ڲ�����һ���������࣬û�а������ⲿ����
	cout << sizeof(A) << endl;
	return 0;
}
#endif


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		if (!(_year > 0 &&
			  _month > 0 && _month < 13 &&
			  _day > 0 && _day <= _GetDaysOfMonth(year, month)))
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	// + ����ı����Ҳ������е�����--->ֻ�ܰ���ֵ�÷�ʽ����
	// d + (-100)
	Date operator+(int days)
	{
		if (days < 0)
		{
			return *this - (0 - days);
		}

		Date temp(*this);
		temp._day += days;

		int daysofMonth = 0;
		// temp�е�day�Ѿ����ڱ��µ�����
		while (temp._day > (daysofMonth = temp._GetDaysOfMonth(temp._year, temp._month)))
		{
			temp._day -= daysofMonth;
			temp._month++;
			if (temp._month > 12)
			{
				temp._year++;
				temp._month = 1;
			}
		}

		return temp;
	}

	Date operator-(int days)
	{
		if (days < 0)
		{
			return *this + (0 - days);
		}

		Date temp(*this);
		temp._day -= days;

		while (temp._day <= 0)
		{
			temp._month--;
			if (temp._month < 0)
			{
				temp._year -= 1;
				temp._month = 12;
			}

			temp._day += temp._GetDaysOfMonth(temp._year, temp._month);
		}

		return temp;
	}

	// min   max
	int operator-(const Date& d)
	{
		Date minDate(*this);
		Date maxDate(d);
		if (*this > d)
		{
			swap(minDate, maxDate);
		}

		size_t count = 0;
		while (minDate != maxDate)
		{
			count++;
			minDate++;
		}

		return count;
	}

	Date& operator++()
	{
		*this = *this + 1;
		return *this;
	}

	Date operator++(int)
	{
		Date temp(*this);
		*this = *this + 1;
		return temp;
	}

	Date& operator--()
	{
		*this = *this - 1;
		return *this;
	}

	Date operator--(int)
	{
		Date temp(*this);
		*this = *this - 1;
		return temp;
	}

	bool operator>(const Date& d)const
	{
		if (_year > d._year ||
			_year == d._year && _month > d._month ||
			_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}

		return false;
	}

	bool operator==(const Date& d)const 
	{
		return _year == d._year &&
			   _month == d._month &&
			   _day == d._day;
	}

	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}

	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
private:
	int _GetDaysOfMonth(int year, int month)
	{
		int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && IsLeapYear(year))
		{
			days[2] += 1;
		}

		return days[month];
	}

	bool IsLeapYear(int year)
	{
		if ((0 == year % 4 && 0 != year % 100) ||
			(0 == year % 400))
		{
			return true;
		}

		return false;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2019, 9, 18);
	Date d2(2020, 1, 1);
	cout << d2 - d1 << endl;

	d1 = d1 - 999;
	cout << d1 << endl;
	return 0;
}