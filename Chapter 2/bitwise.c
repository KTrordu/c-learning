#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 7
#define BUFFER_SIZE 20
#define BUFFER_LENGTH 9
#define RESULT_LENGTH 8
#define MAX_NUMBER 255
#define MIN_NUMBER 0

void get_binary(short number, char *result);

int main()
{
	// Bitwise AND => Compares two values and returns a result containg bits of 1 for two equal bits, 0 for not equal bits.
	char five[BUFFER_LENGTH];
	char six[BUFFER_LENGTH];
	char resultAND[BUFFER_LENGTH];

	get_binary(5, five);
	get_binary(6, six);
	get_binary(5 & 6, resultAND);

	printf("Bitwise AND \n%s | %s => %s\n\n", five, six, resultAND);

	// Bitwise OR => Compares two values and returns a result containing bits of 1 for either 1 bit, 0 for neither.
	char resultOR[BUFFER_LENGTH];

	get_binary(5 | 6, resultOR);

	printf("Bitwise OR \n%s | %s => %s\n\n", five, six, resultOR);

	// Bitwise XOR => Compares two values and returns a result containing bits of 1 for differents, 0 for the sames.
	char resultXOR[BUFFER_LENGTH];

	get_binary(5 ^ 6, resultXOR);

	printf("Bitwise XOR \n%s | %s => %s\n\n", five, six, resultXOR);

	// Bitwise NOT => Inverts all bits as 1 -> 0, 0 -> 1.
	char resultNOT[BUFFER_LENGTH];

	get_binary(250, resultNOT);

	printf("Bitwise NOT \n%s => %s\n\n", five, resultNOT);

	// Bitwise Left Shift => Shifts bits to the left, multiplying by powers of 2.
	char resultLS[BUFFER_LENGTH];

	get_binary(5 << 1, resultLS);

	printf("Bitwise LS \n%s => %s\n\n", five, resultLS);

	// Bitwise Right Shift => Shifts bits to the right, dividing by powers of 2.
	char resultRS[BUFFER_LENGTH];

	get_binary(5 >> 1, resultRS);

	printf("Bitwise RS \n%s => %s\n\n", five, resultRS);

	return EXIT_SUCCESS;
}

// Binary converter for numbers between 0 - 255
void get_binary(short number, char *result)
{
	if (number > MAX_NUMBER)
	{
		snprintf(result, BUFFER_SIZE, "Value is too big.");
		return;
	}
	else if (number < MIN_NUMBER)
	{
		snprintf(result, BUFFER_SIZE, "Value is too small.");
		return;
	}

	result[RESULT_LENGTH] = '\0';
	for (int i = 0; i <= MAX_BITS; ++i)
	{
		result[MAX_BITS - i] = (number % 2) ? '1' : '0';
		number /= 2;
	}
}