#include <stdio.h>
#include <stdlib.h>

/**
* main -function
* Description: that prints "$ ", wait for the user to enter a command,
* prints it on the next line
* Return: 0
*/
int main(void)
{
	char *cache = malloc(1024);
	size_t len = 1024;

	while (1)
	{
		printf("$ ");
		getline(&cache, &len, stdin);
		printf("%s", cache);
	}
	return (0);
}
