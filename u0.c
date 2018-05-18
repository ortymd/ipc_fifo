#include "func.h"
#include <pthread.h>
#include <unistd.h>
#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
#include  <fcntl.h>
#include  <sys/types.h>
#include  <sys/stat.h>

int main()
{
	int u0_write_fifo;
	char msg[256];
	pthread_t contact;

	mkfifo(U0_FIFO, 0777);

	pthread_create(&contact, NULL, listen_contact, U1_FIFO);

	do
	{
		printf("Input message('q' to quit):\n");
		get_user_input(msg, sizeof(msg));
		u0_write_fifo = open(U0_FIFO, O_WRONLY);
		write(u0_write_fifo, msg, sizeof(msg));
		close(u0_write_fifo);
	}while(strcmp(msg, "q") != 0);

	exit(0);	
}
