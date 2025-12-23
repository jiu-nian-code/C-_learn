#define _CRT_SECURE_NO_WARNINGS 1

#define length 9

#define lengths length + 2

#define mine 10

#include<stdio.h>

#include<stdlib.h>

#include<time.h>

void game();

void print();

void chushi(char a[][lengths], int wide, char filler);

void display(char a[][lengths], int wide);

void insert(char a[][lengths], int wide, int total);

int summing(char a[][lengths], char b[][lengths], int x, int y);

int detection(char a[][lengths], char b[][lengths], int wides, int x, int y);

void wait();