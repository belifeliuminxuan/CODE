#include <iostream>
#include <string>
using namespace std;

 void TestString()
{
	string s("helloworld!");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.resize(10, 'a');
	cout << s << endl;
	cout << s.size() << endl;
}
int main()
{
	TestString();
	return 0;
}