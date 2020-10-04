#include <stdio.h>
#include <memory.h>
#include <stdlib.h>


void rawify(char* buffer, const char* link) {
    char whitespace = 0x20;
    for (int i = 0; i < 32; ++i) {
        if (i <= strlen(link)) {
            memcpy(buffer + i, link + i,1);
        }
        else {
            memcpy(buffer + i, &whitespace, 1);
        }

    }

}

int main(int argc, char const *argv[])
{
    FILE *output = fopen("../../assets/file.bin", "wb");

    char *buffer = calloc(32 * 5, sizeof(char));
    const char good_link[] = "https://www.shorturl.at/iopz6";
    const char link2[] = "https://www.shorturl.at/ajpST";
    const char link3[] = "https://www.shorturl.at/jmKV1";
    const char link4[] = "https://www.shorturl.at/zHXZ5";
    const char link5[] = "https://www.shorturl.at/rQ156";

    rawify(buffer, link5);
    rawify(buffer + 32, link3);
    rawify(buffer + 32 * 2, link4);
    rawify(buffer + 32 * 3, good_link);
    rawify(buffer + 32 * 4, link2); 

    
    fwrite(buffer, 32 * 5, sizeof(char), output);
    

    free(buffer);
    puts("went there");
    fclose(output);
    
    return 0;
}


