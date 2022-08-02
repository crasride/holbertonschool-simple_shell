#include "shell.h"
#define MAX_NUM 1024
/**
* main - Function
* Return: 0
*/
int main(void)
{
	char *argc[8];
	char buffer[MAX_NUM + 1] = {0};
	int i, flag, argv;

	while (1)
	{
		if (fgets(buffer, MAX_NUM, stdin) == NULL)
			return (2);
		buffer[strlen(buffer) - 1] = '\0';

		i = 0;
		flag = 0;
		argv = 0;

		for (; buffer[i] != '\0' ; i++)
		{
			if (!isspace(buffer[i]) && flag == 0)
			{
				flag = 1;
				argc[argv++] = buffer + i;
			}
			else if (isspace(buffer[i]))
			{
				flag = 0;
				buffer[i] = '\0';
			}
		}
		argc[argv] = NULL;
		if (argv)
		{
			if (fork() == 0)
			{
				execvp(argc[0], argc);
				return (2);
			}
			else
				wait(NULL);
		}
	    	if (strcmp(argc[0], "exit") == 0) 
	     		return (2);
	}
	return (0);
}
