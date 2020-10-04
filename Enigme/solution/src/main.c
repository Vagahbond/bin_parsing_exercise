#include <memory.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    FILE *input = fopen("../../assets/file.bin", "rb");

    char *buffer = calloc(32, sizeof(char));

    while (fread(buffer, 32, sizeof(char), input) != 0) {
        buffer[31] = 0x00;
        printf("%s\n", buffer);
    }

    return 0;
}
