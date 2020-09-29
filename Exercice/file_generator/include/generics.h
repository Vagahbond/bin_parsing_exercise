#ifndef INCLUDE_GENERICS
#define INCLUDE_GENERICS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *readfile(const char *path)
{
    FILE *f = fopen(path, "rb");

    if (f == NULL) {
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *content = (char *) malloc(size + 1);
    content[size] = '\0';
    fread(content, sizeof(char), size, f);
    fclose(f);

    return content;
}

bool write_file(const char* path, char *buffer, int buffer_size) {
    FILE *output = fopen(path, "wb");

    fwrite(buffer, sizeof(buffer), buffer_size, output);
    fclose(output);
}

#endif
