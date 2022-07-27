#include "shell.h"

#define MAX_NUM 1024
int main(void)
{
	char *argc[8];
	char buffer[MAX_NUM + 1] = {0};
	int i, flag, argv;

	while (1)
	{
	/*	printf("#cisfun$ > "); */

			if (fgets(buffer, MAX_NUM, stdin) == NULL)
			break;

		buffer[strlen(buffer) - 1] = '\0';
	/*	printf("[%s]\n", buffer); */

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
		/*	printf("[%c] %d\n", buffer[i], flag); */
		}
		argc[argv] = NULL;
		for (i = 0; i < argv; i++)
		/*	printf("argv[%d] = %s\n", i, argc[i]); */
		if (fork() == 0)
		{
			execvp(argc[0], argc);
	/*		exit(1); */
		}
		else
			wait(NULL);
	}
/*	printf("Thank you for using me!!! Goodbye\n"); */
	return  (0);
}
