#include <limits.h>
#include <stdio.h>

int maximumProduct(int *nums, int numsSize);

int main(void)
{
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%i\n", maximumProduct(nums, numsSize));
    printf("expected: 24\n");
    return 0;
}

int maximumProduct(int *nums, int numsSize)
{

    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;

    if (nums == NULL || numsSize < 3)
    {
        return 0;
    }

    for (int n = 0; n < numsSize; n++)
    {
        if (nums[n] > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = nums[n];
        }
        else if (nums[n] > max2)
        {
            max3 = max2;
            max2 = nums[n];
        }
        else if (nums[n] > max3)
        {
            max3 = nums[n];
        }
    }

    printf("max1: %i, max2: %i, max3: %i\n", max1, max2, max3);

    return max1 * max2 * max3;
}
