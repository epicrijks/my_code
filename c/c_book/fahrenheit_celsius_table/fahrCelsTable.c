#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ...,300 */

int main() {
    float fahr, celsius;

    fahr = LOWER;

    printf(" F\t   C\n");
    printf("---\t------\n");

    while (fahr <= UPPER) {
        celsius = 5 * (fahr-32) / 9;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }

    printf("\n\n");

    printf(" F\t   C\n");
    printf("---\t------\n");

    for (fahr = LOWER; fahr <= UPPER; fahr+= STEP)
        printf("%3.0f\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}