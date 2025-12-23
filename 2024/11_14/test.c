#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//void rotate(int* nums, int numsSize, int k) {
//    for (int i = 0; i < k; i++)
//    {
//        int ex = *(nums + numsSize - 1);
//        int* ptr = memmove(nums + 1, nums, (numsSize - 1) * sizeof(int));
//        if (ptr == NULL)
//        {
//            perror("rotate:memmove");
//            return;
//        }
//        nums = ptr - 1;
//        *nums = ex;
//    }
//}

//O(N * k)

//void rotate(int* nums, int numsSize, int k) {
//    k %= numsSize;
//    for (int i = 0; i < k; i++)
//    {
//        int ex = *(nums + numsSize - 1);
//        int* ptr = memmove(nums + 1, nums, (numsSize - 1) * sizeof(int));
//        if (ptr == NULL)
//        {
//            perror("rotate:memmove");
//            return;
//        }
//        nums = ptr - 1;
//        *nums = ex;
//    }
//}void rotate(int* nums, int numsSize, int k) {
//    k %= numsSize;
//    for (int i = 0; i < k; i++)
//    {
//        int ex = *(nums + numsSize - 1);
//        int* ptr = memmove(nums + 1, nums, (numsSize - 1) * sizeof(int));
//        if (ptr == NULL)
//        {
//            perror("rotate:memmove");
//            return;
//        }
//        nums = ptr - 1;
//        *nums = ex;
//    }
//}

//void revo(int* nums, int left, int right)
//{
//    while (left < right)
//    {
//        int ex = *(nums + right);
//        *(nums + right) = *(nums + left);
//        *(nums + left) = ex;
//        left++;
//        right--;
//    }
//}
//
//
//void rotate(int* nums, int numsSize, int k)
//{
//    k %= numsSize;
//    revo(nums, 0, numsSize - k - 1);
//    revo(nums, numsSize - k, numsSize - 1);
//    revo(nums, 0, numsSize - 1);
//}

//Õý½â
//O(N)