#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* main -function
* Description: that prints "$ ", wait for the user to enter a command,
* prints it on the next line
* Return: 0
*/
int main(void)
{
	char *buffer = malloc(1024);
	size_t len = 1024;

	while (1)
	{
		printf("#cisfun$ ");
		getline(&buffer, &len, stdin);
		printf("%s", buffer);
	}
	return (0);
}

