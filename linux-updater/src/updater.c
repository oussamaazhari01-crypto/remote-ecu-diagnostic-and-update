#include "updater.h"
#include <stdio.h>

void updater_run(const char* firmware_path)
{
    updater_state_t state = STATE_IDLE;

    printf("Updater started for firmware: %s\n", firmware_path);

    state = STATE_HANDSHAKE;
    printf("State: HANDSHAKE\n");

    state = STATE_TRANSFER;
    printf("State: TRANSFER\n");

    state = STATE_VERIFY;
    printf("State: VERIFY\n");

    state = STATE_COMPLETE;
    printf("State: COMPLETE\n");
}
