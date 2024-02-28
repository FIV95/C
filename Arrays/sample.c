#include <stdio.h>

int main(void)
{
    int average;
    int grades[3];

    grades[0] = 80;
    grades[1];
    grades[2] = 90;

    int size = sizeof(grades) / sizeof(grades[0]);

    grades[1] = (size*85) - grades[0] - grades[2];

    printf("The size of the grades array is: %i\n", size);
    printf("To have the average be 85%% the missing grade must be %i\n", grades[1]);
    printf("The value stored at grades index 1 is %i\n", grades[1]);
}
