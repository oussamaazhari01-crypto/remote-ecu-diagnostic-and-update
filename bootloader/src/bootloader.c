#include "bootloader.h"
#include <stdio.h>

// Skeleton metadata structure
typedef struct {
    uint32_t active_slot;
    uint32_t update_pending;
    uint32_t firmware_version;
    uint32_t firmware_crc;
} metadata_t;

metadata_t metadata;

void bootloader_run(void)
{
    bootloader_state_t state = BL_STATE_INIT;

    while(1) {
        switch(state) {
            case BL_STATE_INIT:
                printf("Bootloader: INIT\n");
                // Init clocks/peripherals (placeholder)
                state = BL_STATE_CHECK_UPDATE;
                break;

            case BL_STATE_CHECK_UPDATE:
                printf("Bootloader: CHECK_UPDATE\n");
                if(metadata.update_pending) {
                    state = BL_STATE_FLASHING;
                } else {
                    state = BL_STATE_JUMP_TO_APP;
                }
                break;

            case BL_STATE_FLASHING:
                printf("Bootloader: FLASHING\n");
                // Receive firmware chunks via UART/CAN (placeholder)
                state = BL_STATE_VERIFY_CRC;
                break;

            case BL_STATE_VERIFY_CRC:
                printf("Bootloader: VERIFY_CRC\n");
                // Verify firmware integrity (placeholder)
                state = BL_STATE_JUMP_TO_APP;
                break;

            case BL_STATE_JUMP_TO_APP:
                printf("Bootloader: JUMP_TO_APP\n");
                jump_to_application(0x08004000); // Example start address
                break;

            case BL_STATE_ERROR:
                printf("Bootloader: ERROR\n");
                while(1); // halt
                break;
        }
    }
}

void jump_to_application(uint32_t app_address)
{
    printf("Jumping to application at 0x%08X\n", app_address);
    // Stack pointer and reset handler setup would go here
}
