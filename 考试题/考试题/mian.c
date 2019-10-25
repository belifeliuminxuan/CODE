#include <stdio.h>
#include <string.h>
void OutString(char *str)
{
	//int k= 0;
	int StrCount[100] = { 0 };
		for (int i = 0; i < strlen(str); ++i)
	{
		for (int j = 0; j < strlen(str); ++j)
		{
			if (str[i] == str[j])
			{
				StrCount[i]++;
				continue;
			}
		}
	}
		//数组里统计字符出现的次数
		for (int k = 0; k < 100; k++)
		{
			if (StrCount[k] != 1 && StrCount[k] != 0)
			{
				printf("%c", str[k]);
			}
			else if (StrCount[k] == 1)
			{
				printf("%c", str[k]);
			}
			else break;
		}
		
}
int main()
{
	char str[] = "abcdab";
	OutString(str);
	return 0;
}