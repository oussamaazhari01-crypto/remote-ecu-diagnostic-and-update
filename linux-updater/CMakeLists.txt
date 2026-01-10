cmake_minimum_required(VERSION 3.10)
project(linux_updater)

add_executable(updater
    src/main.c
    src/updater.c
    src/transport_uart.c
)
