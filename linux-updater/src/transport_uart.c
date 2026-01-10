#include "transport_uart.h"
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <string.h>

static int uart_fd = -1;

int uart_open(const char* device)
{
    struct termios tty;

    uart_fd = open(device, O_RDWR | O_NOCTTY | O_SYNC);
    if (uart_fd < 0) {
        perror("UART open failed");
        return -1;
    }

    memset(&tty, 0, sizeof tty);
    if (tcgetattr(uart_fd, &tty) != 0) {
        perror("tcgetattr");
        return -1;
    }

    cfsetospeed(&tty, B115200);
    cfsetispeed(&tty, B115200);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;
    tty.c_cflag |= CLOCAL | CREAD;
    tty.c_cflag &= ~(PARENB | PARODD | CSTOPB);

    tcsetattr(uart_fd, TCSANOW, &tty);
    return 0;
}

int uart_send(const unsigned char* data, size_t len)
{
    return write(uart_fd, data, len);
}

int uart_receive(unsigned char* buffer, size_t max_len)
{
    return read(uart_fd, buffer, max_len);
}

void uart_close(void)
{
    if (uart_fd >= 0)
        close(uart_fd);
}
