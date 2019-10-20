#include <iostream>
using namespace std;


#include <string>

void TestString1()
{
	string s1;
	string s2("hello");
	string s3(10, '$');
	string s4(s3);

	cin >> s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

// ������ط�ʽ
void TestString2()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	
	if (s.empty())
		cout << "NULL string" << endl;
	else
		cout << "Not NULL string" << endl;

	// ֻ���string������Ч�ַ�����������ı�ײ�ռ���ܴ�С
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	if (s.empty())
		cout << "NULL string" << endl;
	else
		cout << "Not NULL string" << endl;
}

// resize / reserve
// void resize(size_t n, char ch): 
//   ����--��string���е���Ч�ַ��ı䵽n��������ַ�����ch�������
// ע�⣺ 1. ����ǽ�string���е���ЧԪ����С��ֻ�ı���ЧԪ�ظ���������ı�ײ�ռ��С
//       2. ����ǽ�string���е���ЧԪ�����࣬������Ҫ����
void TestString3()
{
	string s("hello");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10, '!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;


	s.resize(20, '8');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(6);
	cout << s << endl;

	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

// void reserve(size_t newcapacity): ����
// newcapacity > oldcapacity(string��ɿռ��С)���ռ�����--->�����ı�(����������С >= newCapacity)����ЧԪ�ظ�������
// newcapacity < oldcapacity(string��ɿռ��С)���ռ���С���ú���ֱ�ӷ��� ����newcapacity < 15
// ע�⣺ֻ�ı�������С������ı���ЧԪ�ظ���
void TestString4()
{
	string s(20, '$');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;


	s.reserve(40);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(24);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}


void TestString5()
{
	string s("hello");
	cout << s[0] << endl;
	s[0] = 'H';
	// ���Խ��---assert����
	//cout << s[10] << endl;

	cout << s.at(2) << endl;
	s.at(2) = 'L';

	// ���Խ��---�׳�out_of_range�쳣
	//cout << s.at(10) << endl;
}

void TestString6()
{
	string s1;
	s1.push_back('I');

	s1 += " Love ";

	string s2("you");
	s1 += s2;

	s1.append(1, ',');
	s1.append("���");
	s1.append(3, '!');
}

// 1. string������ݻ���---vs--PJ  1.5��
//                      linux--SGI 2��
// 2. �����ǰ֪�����Ҫ��string���Ŷ��ٸ�Ԫ�أ�������ǰͨ��reserve���ռ��ṩ��
void TestPushBack()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void TestString7()
{
	string s("12345");
	int ret = atoi(s.c_str());
}

// find  rfind
void TestString8()
{
	string s("hello world");
	size_t pos = s.find(' ');
	if (pos != string::npos)
	{
		cout << ' ' << " is in s" << pos<<endl;
	}

	pos = s.find("world");
	if (pos != string::npos)
	{
		cout << "world" << " is in s" << pos << endl;
	}

	// ��ȡ�ļ��ĺ�׺ - 20190923.cpp.cpp
	string ss("20190923.cpp.cpp");
	pos = ss.rfind('.') + 1;

	string filepox = ss.substr(pos);
	cout << filepox << endl;
}

void TestString9()
{
	string s("hello");

	for (auto e : s)
		cout << e;
	cout << endl;

	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i];
	cout << endl;

	// char*
	// C++98
	//string::iterator it = s.begin();

	// C++11
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}

void reversestring(string& s)
{
// 	char* begin = (char*)s.c_str();
// 	char* end = begin + s.size() - 1;
// 	while (begin < end)
// 	{
// 		swap(*begin, *end);
// 		begin++;
// 		end--;
// 	}

	reverse(s.begin(), s.end());
}

int main()
{
	string s;
	getline(cin, s);
	cout << s << endl;
	//TestString1();
	//TestString2();
	//TestString3();
	//TestString4();

	//TestString5();
	//TestString6();
	//TestString7();
	//TestString8();
	//TestString9();
	//TestPushBack();

// 	string s("hello");
// 	cout << s << endl;
// 	reversestring(s);
// 	cout << s << endl;
	return 0;
}