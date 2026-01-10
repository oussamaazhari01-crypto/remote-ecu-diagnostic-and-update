#ifndef UPDATER_H
#define UPDATER_H

typedef enum {
    STATE_IDLE,
    STATE_HANDSHAKE,
    STATE_TRANSFER,
    STATE_VERIFY,
    STATE_COMPLETE,
    STATE_ERROR
} updater_state_t;

void updater_run(const char* firmware_path);

#endif