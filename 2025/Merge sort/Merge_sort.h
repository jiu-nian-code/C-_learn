#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<string.h>

#include<assert.h>

#include<errno.h>

#include<stdlib.h>

// 归并排序递归实现
void MergeSort(int* a, int n);
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);

// 计数排序
void CountSort(int* a, int n);