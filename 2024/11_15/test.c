#define _CRT_SECURE_NO_WARNINGS 1


//for (int i = 0; i < n; i++)
//    for (int j = 0; j < n; j++)
//        a[i][j] = i * j;

//void fun(int n) {
//    int i = l;
//    while (i <= n)
//        i = i * 2;
//}

//4.设某算法的递推公式是T(n) = T(n - 1) + n，T(0) = 1，则求该算法中第n项的时间复杂度为（）

//int f(unsigned int n) {
//    if (n == 0 || n == 1)
//        return 1;
//    else
//        return n * f(n - 1);
//}

//6.给定一个整数sum，从有N个有序元素的数组中寻找元素a，b，使得a + b的结果最接近sum，最快的平均时间复杂度是（   ）

//1.如果一个函数的内部中只定义了一个二维数组a[3][6]，请问这个函数的空间复杂度为（   ）

//int** fun(int n) {
//    int** s = (int**)malloc(n * sizeof(int*));
//    while (n--)
//        s[n] = (int*)malloc(n * sizeof(int));
//    return s;
//}

//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
//
//假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
//
//更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
//返回 k

//int removeElement(int* nums, int numsSize, int val)
//{
//    int count = 0;
//    int* left = nums;
//    int* right = nums + numsSize - 1;
//    while (left <= right)
//    {
//        if (*left == val && *right != val)
//        {
//            *left = *right;
//            left++;
//            right--;
//            count++;
//        }
//        else if (*left != val && *right == val)
//        {
//            left++;
//            right--;
//            count++;
//        }
//        else if (*left == val && *right == val)
//        {
//            right--;
//            count++;
//        }
//        else
//        {
//            left++;
//        }
//    }
//    return numsSize - count;
//}

//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
//
//注意：本题相对书上原题稍作改动
//
//示例 1：
//
//输入：[3, 0, 1]
//输出：2
//
//
//示例 2：
//
//输入：[9, 6, 4, 2, 3, 5, 7, 0, 1]
//输出：8

//int summing(int* nums, int numsSize)
//{
//    int ret = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        ret += *(nums + i);
//    }
//    return ret;
//}
//
//int missingNumber(int* nums, int numsSize)
//{
//    int sum_of_nums = summing(nums, numsSize);
//    int sum_of_origin = ((numsSize + 1) * (0 + numsSize)) / 2;
//    int lack = sum_of_origin - sum_of_nums;
//    return lack;
//}