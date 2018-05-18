#ifndef FUNC_H
#define FUNC_H

#define U0_FIFO "/tmp/u0"
#define U1_FIFO "/tmp/u1"

void get_user_input(char* user_input, unsigned input_sz);
void* listen_contact(void* listen_fifo);

#endif
