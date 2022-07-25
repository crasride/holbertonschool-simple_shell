#include <stdio.h>
#include <stdlib.h>

/**
* main - functions
* @ac:arg n-1
* @av:arg n-2
* Description: that prints all the arguments, without using ac
* Return: 0
*/
int main(int ac, char **av)
{
	int i = 0;
	/* integer variable */

	while (av[i]) /* condition */
	{
		printf("%s ", av[i]);
		i++;
	}
	printf("\n");
	return (0);
}
