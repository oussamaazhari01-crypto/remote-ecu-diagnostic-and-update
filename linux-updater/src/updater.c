#include "updater.h"
#include "protocol.h"
#include "transport_uart.h"
#include <stdio.h>
#include <string.h>

void updater_run(const char* firmware_path)
{
    updater_state_t state = STATE_IDLE;
    unsigned char buffer[256];

    printf("Updater started for firmware: %s\n", firmware_path);

    // Initialize UART
    if (uart_open("/dev/ttyUSB0") != 0) {
        printf("UART init failed\n");
        state = STATE_ERROR;
        return;
    }

    // HANDSHAKE
    state = STATE_HANDSHAKE;
    printf("State: HANDSHAKE\n");

    unsigned char cmd_hello[1] = { CMD_HELLO };
    uart_send(cmd_hello, 1);

    int n = uart_receive(buffer, sizeof(buffer));
    if (n > 0) {
        printf("Received response from bootloader\n");
        state = STATE_TRANSFER;
    } else {
        printf("No response, aborting\n");
        state = STATE_ERROR;
    }

    // TRANSFER skeleton
    if (state == STATE_TRANSFER) {
        printf("State: TRANSFER\n");
        // Here you would read firmware file in chunks and send CMD_DATA_CHUNK
    }

    // VERIFY skeleton
    state = STATE_VERIFY;
    printf("State: VERIFY\n");

    // COMPLETE
    state = STATE_COMPLETE;
    printf("State: COMPLETE\n");

    uart_close();
}
