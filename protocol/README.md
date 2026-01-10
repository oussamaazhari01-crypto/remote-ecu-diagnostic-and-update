# Firmware Update Protocol Specification

This document defines the communication protocol between the Linux updater
and the embedded bootloader.

## Transport

- Physical layer: UART / CAN / USB
- Packet-based communication
- Little-endian encoding

## Packet Format

| Field        | Size (bytes) |
|-------------|--------------|
| Header      | 2            |
| Command ID  | 1            |
| Length      | 2            |
| Payload     | N            |
| CRC32       | 4            |

## Command Set

### 0x01 – HELLO
Sent by updater to initiate communication.

Response:
- ACK
- NACK

### 0x02 – START_UPDATE
Indicates start of firmware update session.

Payload:
- Firmware version
- Image size

### 0x03 – DATA_CHUNK
Transfers a firmware block.

Payload:
- Sequence number
- Data bytes

### 0x04 – END_UPDATE
Marks end of firmware transfer.

### 0x05 – ABORT
Aborts update process.

## Responses

- ACK (0x80)
- NACK (0x81)
- ERROR (0x82)

## Error Codes

| Code | Meaning |
|-----|--------|
| 0x01 | Invalid command |
| 0x02 | CRC mismatch |
| 0x03 | Flash write error |
| 0x04 | Timeout |
