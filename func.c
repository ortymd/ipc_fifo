#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
#include  <fcntl.h>
#include  <sys/types.h>
#include  <sys/stat.h>
#include <unistd.h>

void get_user_input(char *user_input, unsigned input_sz)
{
		fgets(user_input, input_sz, stdin);
		unsigned len = strlen(user_input) - 1;
		if(user_input[len] == '\n')
			user_input[len] = '\0';
}

void* listen_contact(void* listen_fifo)
{
	char msg[256];
	int u1_read_fifo;

	do
	{
		u1_read_fifo = open( (char*)listen_fifo, O_RDONLY );
		bzero(msg, sizeof(msg));
		read(u1_read_fifo, msg, sizeof(msg));
		printf("Got message:\n%s\n", msg);
		close(u1_read_fifo);
	}while(strcmp(msg, "q") != 0);

	return listen_fifo;		// put return to supress compiler warning
}
