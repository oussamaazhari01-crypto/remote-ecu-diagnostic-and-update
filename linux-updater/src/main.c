#include <stdio.h>
#include "updater.h"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: updater <firmware.bin>\n");
        return -1;
    }

    updater_run(argv[1]);
    return 0;
}
