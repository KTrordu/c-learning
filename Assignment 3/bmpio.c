// You don't need to understand the how these functions work, 
// but you should understand how to use them.

// This file contains the functions to read and write a grayscale BMP file.
// The BMP file is a bitmap image file that stores pixel data as a grid of pixels.
// The pixel data is stored as a 2D array of integers, where each integer represents the pixel intensity value.
// The pixel intensity value should be between 0 and 255.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure for BMP file header
// pragma directives are quite off-topic and advanced for this assignment, 
// but I must use them to ensure the BMP header is packed tightly without padding.
#pragma pack(push, 1)
typedef struct {
    char signature[2];      // "BM"
    int file_size;         // Size of the file in bytes
    int reserved;          // Reserved, must be 0
    int data_offset;       // Offset to pixel data
    int header_size;       // Size of this header (40 bytes)
    int width;            // Image width in pixels
    int height;           // Image height in pixels
    short planes;         // Number of color planes (must be 1)
    short bits_per_pixel; // Bits per pixel (8 for grayscale)
    int compression;      // Compression method (0 for uncompressed)
    int image_size;       // Size of raw bitmap data
    int x_pixels_per_meter; // Horizontal resolution
    int y_pixels_per_meter; // Vertical resolution
    int colors_used;      // Number of colors in palette
    int important_colors; // Number of important colors
} BMPHeader;
#pragma pack(pop)

// @brief Function to write a 2D array as a grayscale BMP file
// @param pixels: Address of the first element of the 2D array of grayscale values
// @param width: width of the image
// @param height: height of the image
// @param filename: name of the output BMP file
// @return true if the file was written successfully, false otherwise
bool write_bmp_file(const int* pixels, int width, int height, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Error: Could not open file %s for writing\n", filename);
        return false;
    }

    // Calculate padding for each row (BMP requires rows to be multiple of 4 bytes)
    int padding = (4 - width % 4) % 4;
    int row_size = width + padding;
    int image_size = row_size * height;
    int palette_size = 256 * 4; // 256 colors * 4 bytes per color (BGR0)

    // Create and fill BMP header
    BMPHeader header;
    memset(&header, 0, sizeof(BMPHeader));
    
    // Set header values
    header.signature[0] = 'B';
    header.signature[1] = 'M';
    header.file_size = sizeof(BMPHeader) + palette_size + image_size;
    header.data_offset = sizeof(BMPHeader) + palette_size;
    header.header_size = 40;
    header.width = width;
    header.height = height;
    header.planes = 1;
    header.bits_per_pixel = 8;
    header.image_size = image_size;
    header.x_pixels_per_meter = 2835; // 72 DPI
    header.y_pixels_per_meter = 2835; // 72 DPI
    header.colors_used = 256;
    header.important_colors = 256;

    // Write header
    fwrite(&header, sizeof(BMPHeader), 1, file);

    // Write grayscale palette (256 shades of gray)
    for (int i = 0; i < 256; i++) {
        fputc(i, file); // Blue
        fputc(i, file); // Green
        fputc(i, file); // Red
        fputc(0, file); // Reserved
    }

    // Write pixel data
    for (int y = height - 1; y >= 0; y--) { // BMP stores pixels bottom-to-top
        for (int x = 0; x < width; x++) {
            // assert the pixel value is between 0 and 255
            int pixel = pixels[y*width + x];
            if (pixel < 0 || pixel > 255) {
                printf("Error: Pixel value out of range: %d\n", pixel);
                fclose(file);
                return false;
            }

            fputc((unsigned char)pixel, file);
        }
        // Write padding
        for (int p = 0; p < padding; p++) {
            fputc(0, file);
        }
    }

    fclose(file);
    return true;
}

// @brief Function to read a grayscale BMP file
// @param pixels: Address of the first element of the 2D array to store the grayscale values
// @param width: width of the image
// @param height: height of the image
// @param filename: name of the input BMP file
// @return true if the file was read successfully, false otherwise
bool read_bmp_file(int* pixels, int width, int height, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file %s for reading\n", filename);
        return false;
    }

    // Read and verify BMP header
    BMPHeader header;
    if (fread(&header, sizeof(BMPHeader), 1, file) != 1) {
        printf("Error: Could not read BMP header\n");
        fclose(file);
        return false;
    }

    // Verify it's a BMP file
    if (header.signature[0] != 'B' || header.signature[1] != 'M') {
        printf("Error: Not a valid BMP file\n");
        fclose(file);
        return false;
    }

    // Verify it's an 8-bit grayscale image
    if (header.bits_per_pixel != 8) {
        printf("Error: Not a grayscale BMP file (must be 8-bit)\n");
        fclose(file);
        return false;
    }

    // Store width and height
    if (width != header.width || height != header.height) {
        printf("Error: Image dimensions do not match: array size: %d x %d, image size: %d x %d\n", width, height, header.width, header.height);
        fclose(file);
        return false;
    }

    // Skip the color palette
    fseek(file, header.data_offset, SEEK_SET);

    // Calculate padding
    int padding = (4 - width % 4) % 4;

    // Read pixel data
    for (int y = height - 1; y >= 0; y--) { // BMP stores pixels bottom-to-top
        for (int x = 0; x < width; x++) {
            unsigned char pixel;
            if (fread(&pixel, 1, 1, file) != 1) {
                printf("Error: Could not read pixel data\n");
                fclose(file);
                return false;
            }
            pixels[y*width + x] = pixel; // Store as int
        }
        // Skip padding
        fseek(file, padding, SEEK_CUR);
    }

    fclose(file);
    return true;
}

// // Example usage
// int main() {
//     // Create a test image
//     int pixels[100][100];
//     for (int i = 0; i < 100; i++) {
//         for (int j = 0; j < 100; j++) {
//             pixels[i][j] = i+j;
//         }
//     }

//     // Write the image to a BMP file
//     write_bmp(&pixels[0][0], 100, 100, "test.bmp");
//     printf("Grayscale BMP file created successfully!\n");

//     // Read the image back
//     int read_pixels[100][100];
//     int width, height;
//     if (read_bmp(&read_pixels[0][0], &width, &height, "test.bmp")) {
//         printf("Successfully read BMP file: %dx%d\n", width, height);
        
//         // Verify the read data matches the original
//         int matches = 1;
//         for (int i = 0; i < height; i++) {
//             for (int j = 0; j < width; j++) {
//                 if (read_pixels[i][j] != pixels[i][j]) {
//                     matches = 0;
//                     break;
//                 }
//             }
//             if (!matches) break;
//         }
//         printf("Read data %s the original data\n", matches ? "matches" : "does not match");
//     }
//     else
//     {
//         printf("Error: Could not read BMP file\n");
//     }
    
//     return 0;
// }