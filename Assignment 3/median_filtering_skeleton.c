#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define WIDTH 384
#define HEIGHT 256
#define WINDOW_SIZE 3

// Defined in bmpio.c
// Just read the docstrings, not the whole code
bool write_bmp_file(const int* pixels, int width, int height, const char* filename);
bool read_bmp_file(int* pixels, int width, int height, const char* filename);


// @brief Apply the median filter to the noisy image
// @param noisy_image: The noisy image
// @param clean_image: The cleaned image
void apply_median_filter(int noisy_image[][WIDTH], int clean_image[][WIDTH - WINDOW_SIZE + 1]) {
    // FILL ME
}

int main() {
    // COMPLETE ME

    // Create a 2D array to store the noisy image
    int noisy_image[HEIGHT][WIDTH] = {0};
    int clean_image[HEIGHT - WINDOW_SIZE + 1][WIDTH - WINDOW_SIZE + 1] = {0};


    return 0;
}