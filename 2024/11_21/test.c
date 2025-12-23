#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<stdlib.h>

#include<stdbool.h>

typedef struct stack
{
    char* a;
    int size;
    int top;
}stack;

bool isValid(char* s) {
    stack ps = { 0 };
    ps.a = (char*)calloc(10, sizeof(char));
    ps.size = 10;
    ps.top = 0;
    while (*s)
    {
        if (*s == '(' || *s == '{' || *s == '[')
        {
            if (ps.size == ps.top)
            {
                char* ptr = realloc(ps.a, 2 * (ps.size) * sizeof(char));
                ps.a = ptr;
            }
            ps.a[ps.top] = *s;
            ps.top++;
        }
        else if ((*s == ')' || *s == '}' || *s == ']') && ps.top == 0)
        {
            return false;
        }
        else if (*s == ')' && ps.a[ps.top - 1] == '(')
        {
            ps.top--;
        }
        else if (*s == '}' && ps.a[ps.top - 1] == '{')
        {
            ps.top--;
        }
        else if (*s == ']' && ps.a[ps.top - 1] == '[')
        {
            ps.top--;
        }
        else
        {
            return false;
        }
        s++;
    }
    if (ps.top != 0)
    {
        return false;
    }
    return true;
}

int main()
{
    isValid("(){}[]");
	return 0;
}