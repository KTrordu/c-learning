#ifndef MATH_UTILS_H

#define MATH_UTILS_H

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

#define SQUARE(X) ((X) * (X))
#define CUBE(X) ((X) * (X) * (X))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CIRCLE_AREA(r) (PI * SQUARE(r))
#define RECTANGLE_AREA(w, h) ((w) * (h))
#define DISTANCE(x1, y1, x2, y2) sqrt(SQUARE((x2 - x1)) + SQUARE((y2) - (y1)))

#endif