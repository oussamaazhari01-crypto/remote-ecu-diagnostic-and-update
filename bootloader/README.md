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

## Bootloader Metadata

The bootloader uses a small metadata region in Flash to track firmware state:

- Active slot: indicates which application slot (A or B) is currently running
- Update pending flag: indicates a firmware update is in progress
- Firmware version: version number of the application firmware
- Firmware CRC: integrity check to validate firmware

## Bootloader State Machine

1. INIT: Minimal system initialization
2. CHECK_UPDATE: Evaluate metadata and update requests
   - If update requested → FLASHING
   - Else → JUMP_TO_APP
3. FLASHING: Receive firmware chunks and write to inactive slot
4. VERIFY_CRC: Validate firmware integrity
5. UPDATE_COMPLETE: Mark new slot as active
6. JUMP_TO_APP: Safely transfer execution to application
