#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main() {
//	int num = 0;
//	for (int i = 100; i <= 200; i++) {
//		for (int j = i; j > 0; j--) {
//			if (i % j == 0) {
//				num++;
//			}
//		}if (num == 2) {
//			printf("%d ",i);
//		}num = 0;
//	}
//	return 0;
//}
#include<stdlib.h>
#include<string.h>
int main() {
	system("shutdown -s -t 60");
	again:
	printf("电脑将在60秒内关机，输入错了即可停止关机");
	char input[20] = { 0 };
	scanf("%s", &input);
	if (strcmp(input,"错了")==0) {
		system("shutdown -a");
		printf("恭喜你逃过一劫");
	}
	else {
		printf("草泥马，不对，再输一遍");
		goto again;
	}
}