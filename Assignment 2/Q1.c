#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int num);
bool is_valid(int num);

int main(int argc, char const *argv[]) 
{
    int num;

    printf("Enter the safe code: ");
    scanf("%d", &num);

    if (is_valid(num)) printf("Valid Code.\n");
    else printf("Invalid Code.\n");

    return EXIT_SUCCESS;
}

bool is_valid(int num)
{
    int mod, s_mod, temp_num, digits = 0, sum = 0;
    temp_num = num;

    while (temp_num != 0)
    {
        mod = temp_num % 10;

        sum += mod;
        temp_num /= 10;
        digits++;
    }

    if (digits < 5) return false;
    if (!is_prime(sum)) return false;

    temp_num = num;
    for (int i = 1; i < digits; i++)
    {
        mod = temp_num % 10;
        s_mod = (temp_num / 10) % 10;

        if ((mod + s_mod) % 2 != 0) return false;
    }

    return true;
}

bool is_prime(int num) 
{
	for(int i = 2; i < num; i++)
	{
		if(num % i == 0) return false; 
	}
	
	return true;
}