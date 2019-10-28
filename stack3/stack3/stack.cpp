#include <iostream>
#include <Windows.h>
#include <vector>
#include <stack>
using namespace std;

class Mystack
{
public:
	int PushElem()
	{
		int elem = 0;

		for (int j = 0; j < 100; j++)
		{
			cout << "Please enter the value of the element: " << endl;
			cin >> elem;
			if (elem != -1)
			{
				_elem.push(elem);
			}
			else
			{
				break;
			}
		}
		cout << "The element at the top of the stack is:" << _elem.top() << endl;
		_elem.pop();
		return 0;
	}
private:
	stack<int> _elem;
};

int main()
{
	Mystack S;
	S.PushElem();
	system("pause");
	return 0;
}
