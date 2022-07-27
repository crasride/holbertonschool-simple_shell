#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<pthread.h>
#include<string.h>
#include<sys/ioctl.h>
#include<fcntl.h>
#include<stdbool.h>
#include<pwd.h>
#include<sys/wait.h>
#include<signal.h>
#include<sys/select.h>
#include<poll.h>
#include<dirent.h>

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


