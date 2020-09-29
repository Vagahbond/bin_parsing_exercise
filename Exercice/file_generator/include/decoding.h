
#ifndef INCLUDE_DECODING
#define INCLUDE_DEOCDING 1


typedef struct {
        char *audio_format;
        short *nb_channels;
        int *byte_rate;
        int *sample_rate;
        short *block_align;
        short *bits_per_sample;
        unsigned int *buffer_length;
        char *audio_buffer;

} audio_data;


#endif