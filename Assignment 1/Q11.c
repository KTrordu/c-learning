#include <stdio.h>
#include <stdlib.h>

int calculate_gcd(int num1, int num2);

int main()
{
    int num1, num2, max, min, gcd;
	printf("Enter the two numbers: ");
	scanf("%d %d", &num1, &num2);

	if (num1 == (num2 == 0)) printf("GCD(0,0) is undefined.\n");

	if (num1 > num2) {
		max = num1;
		min = num2;
	} else {
		max = num2;
		min = num1;
	}
	
	gcd = calculate_gcd(max, min);
	printf("GCD(%d,%d) = %d.\n", max, min, gcd);

	return EXIT_SUCCESS;
}

int calculate_gcd(int num1, int num2) {
	if (num1 < 0) num1 *= -1;
	if (num2 < 0) num2 *= -1;

	int temp;
	while (num2 != 0) {
		temp = num1 % num2;
		num1 = num2;
		num2 = temp;
	}
	
	return num1;
}