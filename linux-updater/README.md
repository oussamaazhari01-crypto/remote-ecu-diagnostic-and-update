# Linux Firmware Updater Architecture

The Linux updater is a user-space application responsible for securely
delivering firmware updates to the embedded device bootloader.

## Responsibilities

- Detect target device connection
- Perform bootloader handshake
- Transfer firmware image in chunks
- Handle acknowledgments and retries
- Verify update completion
- Log update status and errors

## Architecture Overview

The updater follows a layered design:

- CLI Interface
- Update Controller (state machine)
- Transport Layer (UART / CAN / USB)
- File Manager (firmware image handling)
- Logger

## Update State Machine

1. IDLE
2. DEVICE_DETECTED
3. HANDSHAKE
4. TRANSFER
5. VERIFY
6. COMPLETE
7. ERROR / RETRY

## Safety Considerations

- Timeout-based retries
- Transfer resume support
- Update abort and rollback trigger
- Version compatibility checks
