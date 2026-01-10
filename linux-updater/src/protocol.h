#ifndef PROTOCOL_H
#define PROTOCOL_H

typedef enum {
    CMD_HELLO = 0x01,
    CMD_START_UPDATE = 0x02,
    CMD_DATA_CHUNK = 0x03,
    CMD_END_UPDATE = 0x04,
    CMD_ABORT = 0x05
} command_t;

#endif
