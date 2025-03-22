#include <stdio.h>
#include <time.h>
int main()
{
time_t TarihSaat;
// Declare variable as time_t data type (long number)
// Capture the current date and time as a long number
time( &TarihSaat );
printf("%lld \n\n", TarihSaat); // Display as a long number
// Convert the long number to a string definition and display it
printf("%s \n", ctime( &TarihSaat ) );
}