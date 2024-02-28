#include <stdio.h>

int main(void)
{
    float grades[2][5] =
	{
	    {85,90,70,87,98.2},
	    {90,93,95,87,75}
	};

    int size = sizeof(grades[0]) / sizeof(grades[0][0]);

    printf("%i\n", size);

    float mathAvg;
    float phyAvg;
    float mathSum = 0;
    float phySum = 0;

    for (int i = 0; i < size; i ++)
    {
	    mathSum += grades[0][i];
    }

    mathAvg = mathSum / size;

    for (int i = 0; i < size; i ++)
    {
	    phySum += grades[1][i];
    }

    phyAvg = phySum / size;

    for (int i

    printf("The sum of the grades in the math class are %.2f\n", mathAvg);
    printf("The sum of the grades in the Physics class are %.2f\n", phyAvg);
}
