#include <stdio.h>

int main(int argc, char const *argv[])
{
	int num1, num2, num3, total, avg, product, min, max;
	printf("Enter three numbers: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	total = num1 + num2 + num3;
	avg = total / 3;
	product = num1 * num2 * num3;

	if (num1 > num2)
	{
		if (num2 > num3)
		{
			min = num3;
			max = num1;
		}
		else
		{
			min = num2;
			max = num1;
		}
	}
	else if (num2 > num1)
	{
		if (num1 > num3)
		{
			min = num3;
			max = num2;
		}
		else
		{
			min = num1;
			max = num2;
		}
	}
	else
	{
		if (num1 > num3)
		{
			min = num3;
			max = num1;
		}
		else
		{
			min = num1;
			max = num3;
		}
	}

	printf("Sum is: %d\n", total);
	printf("Average is: %d\n", avg);
	printf("Product is: %d\n", product);
	printf("Minimum is: %d\n", min);
	printf("Maximum is: %d\n", max);

	return 0;
}