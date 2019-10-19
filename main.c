#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct Student
{
	char _name[20];
	char _schoolnumber[20];
}Student;
int main()
{
	int fd;
	int rd;
	int wr_len_name = 0;
	int wr_len_schoolnumber=0;
	int sumstr=0;
	int flag=1;
	int str1;
	int str2;
	int str3;
	char str_1[]={"My name is:"};
	char str_2[]={"My schoolnumber is:"};
	char str_3[]={"    "};
	char str_read[256];	
	fd = open("Schoolnumber.txt", O_CREAT | O_RDWR|O_APPEND, 0777);
	if (fd < 0)
	{
		printf("Open file schoolnumber.txt failuse!\n");
		return -1;
	}
	printf("Open file schoolnumber.txt success!\n");
	while(flag!=-1&&flag==1)
	{
	Student* add = (Student*)malloc(sizeof(Student));
	printf("Please enter your name:\n");
	scanf("%s", add->_name);
	printf("Please enter your student number:\n");
	scanf("%s", add->_schoolnumber);
	printf("Start write,please wait...\n");
	strcat(add->_schoolnumber,"\r\n");
		str1=write(fd,str_1,strlen(str_1));
	wr_len_name = write(fd, add->_name, strlen(add->_name));
		str3=write(fd,str_3,strlen(str_3));
		str2=write(fd,str_2,strlen(str_2));
	wr_len_schoolnumber = write(fd, add->_schoolnumber, strlen(add->_schoolnumber));
	printf("Do you want to continue typing?,Enter - 1 to exit, 1 to continue...\n");
	scanf ("%d",&flag);
	sumstr+=strlen(str_1)+strlen(str_2)+strlen(str_3)+strlen(add->_name)+strlen(add->_schoolnumber);
	}
	
 if (wr_len_name&&wr_len_schoolnumber)
 {	
	printf("Write to file schoolnumber.txt success!\n");
	printf("Wrile length is:[%d]!\n",sumstr);
 }
 else
 {
	 printf ("write to file schoolnumber failure...\n");
 }
	close(fd);
	printf("The contents read from the file are:\n");
	printf("______________________________________________________________________\n");
 	rd=open("Schoolnumber.txt", O_RDONLY|O_APPEND, 0444);
	read(rd,str_read,sumstr);
	for(int i=0;i<sumstr;++i)
{
	printf("%c",str_read[i]);
}
	printf("\n");
	printf("______________________________________________________________________\n");
	close(fd);
return 0;
}
