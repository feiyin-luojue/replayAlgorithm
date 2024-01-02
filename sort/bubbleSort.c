#include <stdio.h>


/* 交换两个整数 */
int swap(int *val1, int *val2)
{
    int ret = 0;
    int temp = 0;
    temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    return ret;
}

int printArray(int *array, int arraySize)
{
    int ret = 0;
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
    return ret;
}

/* 时间复杂度: O(n^2) */
void bubbleSort01(int *array, int lenth)
{
    for (int end = lenth; end > 1; end--)
    {
        for (int begin = 1; begin < end; begin++)
        {
            /* 后面的数 比 前面的数要小 就交换*/
            if (array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
            }
        }
    }
}

void bubbleSort02(int *array, int lenth)
{
    for (int end = lenth; end > 1; end--)
    {
        /* 已经排好序的标志 */
        int sorted = 1;
        for (int begin = 1; begin < end; begin++)
        {
            /* 后面的数 比 前面的数要小 就交换*/
            if (array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
                /* 数据是没有排好序的 */
                sorted = 0;
            }
        }
        if (sorted == 1)
        {
            break;
        }
    }
}


int main(int argc, char const *argv[])
{
    int array[] = {54, 78, 89, 100, 127, 128};

    int lenth = sizeof(array) / sizeof(array[0]);
    
    bubbleSort02(array, lenth);
    printArray(array, lenth);
    return 0;
}
