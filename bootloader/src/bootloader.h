#ifndef BOOTLOADER_H
#define BOOTLOADER_H

#include <stdint.h>

typedef enum {
    BL_STATE_INIT,
    BL_STATE_CHECK_UPDATE,
    BL_STATE_FLASHING,
    BL_STATE_VERIFY_CRC,
    BL_STATE_JUMP_TO_APP,
    BL_STATE_ERROR
} bootloader_state_t;

void bootloader_run(void);
void jump_to_application(uint32_t app_address);

#endif
