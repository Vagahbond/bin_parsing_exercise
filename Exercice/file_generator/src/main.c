#include "../include/generics.h"
#include "../include/decoding.h"

#include <stdlib.h>
#include <string.h>

#define MAIN_CHUNK_ID_END 3

#define MAIN_CHUNK_SIZE_START 4
#define MAIN_CHUNK_SIZE_END 7

#define MAIN_CHUNK_FORMAT_START 8
#define MAIN_CHUNK_FORMAT_END 11

#define INFO_CHUNK_ID_START 12
#define INFO_CHUNK_ID_END 15

#define INFO_CHUNK_SIZE_START 16
#define INFO_CHUNK_SIZE_END 19

#define INFO_CHUNK_FORMAT_START 20
#define INFO_CHUNK_FORMAT_END 21

#define INFO_CHUNK_CHANNELS_START 22
#define INFO_CHUNK_CHANNELS_END 23

#define INFO_CHUNK_SR_START 24
#define INFO_CHUNK_SR_END 27

#define INFO_CHUNK_BYTERATE_START 28
#define INFO_CHUNK_BYTERATE_END 31

#define INFO_CHUNK_BLOCK_ALIGN_START 32
#define INFO_CHUNK_BLOCK_ALIGN_END 33

#define INFO_CHUNK_BPS_START 34
#define INFO_CHUNK_BPS_END 35

#define AUDIO_CHUNK_ID_START 36
#define AUDIO_CHUNK_ID_END 39

#define AUDIO_CHUNK_SIZE_START 40
#define AUDIO_CHUNK_SIZE_END 43

#define AUDIO_CHUNK_DATA_START 44

typedef int32_t buffer_size;

bool write_exercise_file(const char *path, audio_data *data)
{
    FILE *f = fopen(path, "wb");



    size_t output_length = *data->buffer_length + 10;

    char *output = calloc(output_length, sizeof(char));
    
    


    // bits per sample
    short bps = 0x1000;
    memcpy(output, &bps, 2);
   

    // nb channels
    short nb_channels = 0x0200;
    memcpy(output + 2, &nb_channels, 2);

    // sample rate
    short sample_rate = 0x80BB;
    memcpy(output + 4, &sample_rate, 2);

    // buffer size
    buffer_size buffer_size = 0x68646300;
    memcpy(output + 6, &buffer_size, 4);

    // PCM buffer itself
    memcpy(output + 10, data->audio_buffer, *data->buffer_length);


    fwrite(output, sizeof(char), output_length, f);

    fclose(f);
}

int main(int argc, char *argv)
{
    char *buffer = readfile("../../assets/Extract.wav");

    if (buffer == NULL)
    {
        puts("RIP FDP");
    }

    audio_data *data = calloc(1, sizeof(audio_data));

    //format
    data->audio_format = calloc(5, sizeof(char));
    memcpy(data->audio_format, buffer + MAIN_CHUNK_FORMAT_START, 4);
    puts(data->audio_format);

    data->byte_rate = calloc(1, sizeof(int));
    memcpy(data->byte_rate, buffer + INFO_CHUNK_BYTERATE_START, 4);
    printf("byte rate : %d\n", *data->byte_rate);

    data->sample_rate = calloc(1, sizeof(int));
    memcpy(data->sample_rate, buffer + INFO_CHUNK_SR_START, 4);
    printf("sample rate : %d\n", *data->sample_rate);

    data->block_align = calloc(1, sizeof(short));
    memcpy(data->block_align, buffer + INFO_CHUNK_BLOCK_ALIGN_START, 2);
    printf("block align : %d\n", *data->block_align);

    data->bits_per_sample = calloc(1, sizeof(short));
    memcpy(data->bits_per_sample, buffer + INFO_CHUNK_BPS_START, 2);
    printf("bits per sample : %d\n", *data->bits_per_sample);

    data->buffer_length = calloc(1, sizeof(int));
    memcpy(data->buffer_length, buffer + AUDIO_CHUNK_SIZE_START, 4);
    printf("buffer length: %d\n", *data->buffer_length);

    data->audio_buffer = calloc(*data->buffer_length, sizeof(char));
    memcpy(data->audio_buffer, buffer + AUDIO_CHUNK_DATA_START, *data->buffer_length);
    printf("buffer: %x\n", *data->audio_buffer);

    free(buffer);

    write_exercise_file("../../assets/custom.bin", data);

    free(data->audio_format);
    free(data->byte_rate);
    free(data->sample_rate);
    free(data->block_align);
    free(data->bits_per_sample);
    free(data->buffer_length);
    free(data->audio_buffer);
    free(data);



    return 0;
}