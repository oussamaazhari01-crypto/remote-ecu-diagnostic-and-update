# Bootloader Architecture

The bootloader is a standalone firmware component executed immediately
after MCU reset. It is responsible for managing firmware updates and
safely transferring execution to the main application.

## Position in Memory
- Located at the beginning of internal Flash
- Isolated from application firmware
- Protected against overwrite during updates

## Responsibilities
- Initialize minimal system resources
- Check firmware update conditions
- Receive firmware update commands
- Write application firmware to Flash
- Verify firmware integrity using CRC
- Perform a safe jump to the application firmware

## Non-Responsibilities
- No application-level logic
- No real-time control
- No dependency on application firmware

## Boot Flow
1. MCU reset
2. Bootloader execution
3. Update condition check
4. Firmware update handling OR jump to application
