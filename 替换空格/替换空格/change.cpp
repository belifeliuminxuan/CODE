#include <iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) 
	{
		char Change[sizeof(str)];
		for (int i = 0; i < length; ++i)
		{
			if (str[i] != ' ')
			{
				Change[i] = str[i];
			}
			else
			{
				Change[i] = '%';
				Change[i + 1] = '2';
				Change[i + 2] = '0';

			}
		}
		cout << Change;
	}
	
};
int main()
{
	char *str = "we are student";
	Solution s1;
		s1.replaceSpace(str, sizeof(str));
	return 0;
}