#ifndef TRANSPORT_UART_H
#define TRANSPORT_UART_H

#include <stddef.h>

int uart_open(const char* device);
int uart_send(const unsigned char* data, size_t len);
int uart_receive(unsigned char* buffer, size_t max_len);
void uart_close(void);

#endif
