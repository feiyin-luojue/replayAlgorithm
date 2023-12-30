#include <stdio.h>
#define BUFFER_SIZE 7

int changeAtoB(int *numA, int *numB)
{
    int temp = 0;
    temp = *numA;
    *numA = *numB;
    *numB = temp;
    return 0;
}

int printNums(int *nums, int numsLen)
{
    for (int idx = 0; idx < BUFFER_SIZE;idx++)
    {
        printf("  %d  ", nums[idx]);
    }
    return 0;
}

int selectSort(int *nums, int numsLen)      //选择排序
{
    for (int idx = 0; idx < numsLen - 1; idx++)
    {
        int temp = nums[idx + 1];
        int pos = idx + 1;
        for (int jdx = idx + 1; jdx < numsLen; jdx++)
        {
            if (nums[jdx] < temp)
            {
                temp = nums[jdx];
                pos = jdx;
            }
        }
        if (nums[pos] < nums[idx])
        {
            changeAtoB(&nums[idx], &nums[pos]);            
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int nums[BUFFER_SIZE] = {1, 30, 24, 5, 58, 12, 39};
    int numsLen = sizeof(nums) / sizeof(nums[0]);
    printf("\t排序前：");
    printNums(nums, numsLen);
    putchar(10);
    selectSort(nums, numsLen);
    printf("\t排序后：");
    printNums(nums, numsLen);
    putchar(10);
    return 0;
}
