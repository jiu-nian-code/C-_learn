#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int* end = nums1 + nums1Size - 1;
    int* ex1 = nums1 + m - 1;
    int* ex2 = nums2 + n - 1;
    while (ex1 + 1 != nums1 && ex2 + 1 != nums2)
    {
        if (*ex1 >= *ex2)
        {
            *(end--) = *(ex1--);
        }
        else if (*ex2 > *ex1)
        {
            *(end--) = *(ex2--);
        }
    }
    if (ex1 + 1 == nums1)
    {
        while (ex2 + 1 != nums2)
        {
            *(end--) = *(ex2--);
        }
    }
}

int main()
{
    int a[10] = { 6, 7, 8, 9, 10 };//6, 7, 8, 9, 10
    int b[5] = { 1, 2, 3, 4, 5 };//1, 2, 3, 4, 5
    merge(a, 10, 5, b, 5, 5);
    return 0;
}