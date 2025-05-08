#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 20

//DO NOT MODIFY THE FUNCTION SIGNATURE.
char *nstrstr(char *str1, char *str2, int n) {
    int count = 0;
    int len_1 = strlen(str1);
    int len_2 = strlen(str2);

    for (int i = 0; i <= len_1 - len_2; i++)
    {
        int j = 0;
        while (j < len_2 && str1[i + j] == str2[j])
        {
            j++;
        }

        if (j == len_2)
        {
            count++;
            if (count == n)
            {
                return &str1[i];
            }
        }
    }
    return NULL;
    
    //Fill in the function body here
}

//DO NOT MODIFY THE MAIN FUNCTION. MODIFICATIONS ON THE FUNCTION WILL GET 0 POINT FROM THE QUESTION!
int main() {
	char str1[MAX_STR_LEN];
	char str2[MAX_STR_LEN];
	int n;

	printf("Enter str1, str2, and n: ");
	scanf("%s %s %d", str1, str2, &n);	 
	char *str3 = nstrstr(str1, str2, n);
	if(str3 == NULL){
		printf("str2 does not occur in str1 n times.\n");
		return 0;
	} 
	printf("n-th occurrence of str2 in str1 starts here: %s\n", str3);
	return 0;
}
