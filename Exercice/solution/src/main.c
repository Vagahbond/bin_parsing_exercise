#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int16_t sample;

typedef struct {
    unsigned short sample_size;
    unsigned short nb_channels;
    unsigned short sample_rate;
    size_t buffer_length;
    char* audio_buffer;
} audio_data;

int little_endian_to_int(char *source, size_t length) {

    char *temp = calloc(length, sizeof(char));

    for (int i = 0; i < length; ++i) {
        memcpy(temp + i, source + ( length - (i + 1) ), 1);
    }

    int res = *(int *) temp;
    free(temp);
    return res;
}


void stereo_to_mono(FILE* file, audio_data *data) {
    // parse

    // Find file length
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate and fill buffer
    char *buffer = calloc(size, sizeof(char));
    fread(buffer, sizeof(char), size, file);

    // Parse the data
    data->sample_size = *(short *) buffer;

    data->nb_channels = *(short *) (buffer + 2);

    data->sample_rate = little_endian_to_int(buffer + 4, 2);

    data->buffer_length = little_endian_to_int(buffer + 6, 4);

    data->audio_buffer = calloc(data->buffer_length, sizeof(char));
    memcpy(data->audio_buffer, buffer + 10, data->buffer_length);


    // Merge the channels
    size_t new_length = data->buffer_length / 2;
    char * new_buffer = calloc(new_length, sizeof(char));
    char * cur = new_buffer;
    short step = sizeof(sample) * 2;
    for (int l = 0, r = 2; r < data->buffer_length ; l+=step, r+=step, cur+=sizeof(sample)) {

        sample res = 0;

        res = ( (*(sample *) (data->audio_buffer + l) ) + ( *(sample *) (data->audio_buffer + r) ) ) / 2;

        memcpy(cur, &res, 2);

    }
    
    //affect changes to the structure

    data->buffer_length = new_length;
    data->audio_buffer = (char *) new_buffer;
    data->nb_channels = 1;
    data->sample_size = 16;
    // samplerate doesnt change, or the track will be sped up or slown down.

    // print file to listen to it on Audacity
    FILE *output = fopen("../../assets/output.pcm", "wb");
    
    fwrite(data->audio_buffer, sizeof(char), data->buffer_length, output);

    fclose(output);



}



int main(int arg, char* argv) {
    FILE *input_file = fopen("../../assets/custom.bin", "rb");
    audio_data *data = malloc(sizeof(audio_data));

    stereo_to_mono(input_file, data);

    
    free(data->audio_buffer);
    free(data);
    fclose(input_file);
    return 0;
}

