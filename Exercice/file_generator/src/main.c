#include <stdio.h>


int main(int argc, char* argv) {
    FILE *output;
    output = fopen('TEMP/file.bin', "wb");

    char *buffer = malloc(sizeof(char) * 130);


    buffer = 0x4D75736963202020;
    buffer[8] = 0x50434D20;
    buffer[12] = 0x0002;
    buffer[]

    return 0;
}