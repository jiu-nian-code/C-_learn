#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<stdlib.h>

int main()
{
	int a;
	scanf("%d", &a);
	int* ptr = (int*)malloc(a * sizeof(int));
	if (ptr == NULL)
	{
		perror("malloc");
		return 0;
	}
	for (int i = 0; i < a; i++)
	{
		ptr[i] = i + 1;
	}
	for (int i = 0; i < a; i++)
	{
		printf("%d\t", ptr[i]);
	}
	free(ptr);
	ptr = NULL;
	return 0;
}

//int main() {
//    int* arr;
//    int n, i;
//
//    printf("请输入数组的大小: ");
//    scanf("%d", &n);
//
//    // 使用 malloc 动态分配内存
//    arr = (int*)malloc(n * sizeof(int));
//
//    // 检查内存分配是否成功
//    if (arr == NULL) {
//        printf("内存分配失败!\n");
//        return 1; // 返回非零值表示错误
//    }
//
//    // 输入数组元素
//    //printf("请输入 %d 个整数:\n", n);
//    for (i = 0; i < n; i++) {
//        //scanf("%d", &arr[i]);
//        arr[i] = i;
//    }
//
//    // 输出数组元素
//    printf("您输入的数组是:\n");
//    for (i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    // 释放分配的内存
//    free(arr);
//
//    return 0;
//}