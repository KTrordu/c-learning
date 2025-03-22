#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef enum {
	RED,
	GREEN,
	BLUE
} ColorChannel;

void convertRGBtoHSV(int red, int green, int blue);

int main() {
    int red, green, blue;

	while (true) {
		printf("Enter Red value (0-255) (-1 terminates): ");
		scanf("%d", &red);
		if (!red) break;

		printf("Enter Green value (0-255): ");
		scanf("%d", &green);

		printf("Enter Blue value (0-255): ");
		scanf("%d", &blue);

		if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
			printf("Invalid input. The values must be between 0-255.\n");
			continue;
		}

		convertRGBtoHSV(red, green, blue);
	}

	return EXIT_SUCCESS;
}

void convertRGBtoHSV(int red, int green, int blue) {
	double redf = red / 255.0, greenf = green / 255.0, bluef = blue / 255.0;

	double max = fmax(redf, fmax(greenf, bluef));
	double min = fmin(redf, fmin(greenf, bluef));
	double delta = max - min;

	double hue = 0, saturation = 0, value = max;

	if (delta != 0) {
		if (max = redf) {
			hue = 60 * 
		}
		
	}
	
}