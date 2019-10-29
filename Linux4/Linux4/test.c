#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
	pid_t pid;
	int ret;
	int status;
	pid = fork();
	if (pid <0)
	{
		printf("failure\n");
		return -1;
	} 
	if(pid==0)
	{
		printf("helloworld\n");
		sleep(10);
		exit(1);
	}
	if (pid > 0)
	{
		pid_t pid1;
		pid1 = fork();
		if (pid1 < 0)
		{
			printf("failure\n");
			exit(2);
		}
		if (pid1 == 0)
		{
			printf("hello linux\n");
			sleep(20);
			exit(3);
		}
		printf("hello linus\n");
		printf("hello windows\n");
		ret = waitpid(pid1, &status, 0);
		printf("%d %d\n", ret, WEXITSTATUS(status));
	}
	while (1);

	return 0;
}