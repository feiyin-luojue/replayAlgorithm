#include <stdio.h>

#define BUFFER_SIZE 6

int printNums(int *nums, int numsLen)
{
    for (int idx = 0; idx < numsLen; idx++)
    {
        printf("  %d  ", nums[idx]);
    }
    return 0;
}

int insertSort(int *nums, int numsLen)      //插入排序
{
    #if 0
    for (int begin = 1; begin < numsLen; begin++)
    {
        int insertVal = nums[begin];
        int insertPos = begin;
        for (insertPos = begin; insertPos > 0; insertPos--)
        {
            if (nums[insertPos - 1] > insertVal)
            {
                nums[insertPos] = nums[insertPos - 1];
            }
            else
            {
                break;
            }
        }
        nums[insertPos] = insertVal;
    }
    #else   //优化
    int insertVal = 0;
    int insertPos = 0;
    for (int begin = 1; begin < numsLen; begin++)
    {
        insertVal = nums[begin];
        for (insertPos = begin;insertPos > 0 && nums[insertPos - 1] > insertVal; insertPos--)
        {
            nums[insertPos] = nums[insertPos - 1];
        }
        nums[insertPos] = insertVal;
    }
    #endif
}

int main(int argc, char const *argv[])
{
    int nums[BUFFER_SIZE] = {24, 30, 5, 58, 12, 39};
    int numsLen = sizeof(nums) / sizeof(nums[0]);
    printf("\t排序前：");
    printNums(nums, numsLen);
    putchar(10);
    insertSort(nums, numsLen);
    printf("\t排序后：");
    printNums(nums, numsLen);
    putchar(10);
    return 0;
}
