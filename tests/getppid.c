#include <stdio.h>
#include <unistd.h>

/**
* main - PID
*
* Return: Always 0.
*/
int main(void)
{
	pid_t my_pid;
/*
* The pid_t data type is a signed integer type which is capable of representing
* process ID
*/
	my_pid = getpid();
	/* process child*/
	printf("child %u\n", my_pid);
	my_pid = getppid();
	/* proccess fahter*/
	printf("father %u\n", my_pid);
	return (0);
}

