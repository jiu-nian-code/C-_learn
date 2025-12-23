#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

const int N = 1e7 + 10;

int arr[N];

int n, x;

int main()
{
    cin >> n >> x;
    for (int i = 1; i < n; ++i)
    {
        cin >> arr[i];
    }
    int right = 0, left = 0;
    int Rright = -1, Rleft = -1;
    int sum = 0, retlen = N;
    while (right < n)
    {
        sum += arr[right];
        while (sum >= x)
        {
            if (right - left + 1 < retlen)
            {
                Rright = right;
                Rleft = left;
                retlen = right - left + 1;
            }
            //sum -= arr[left++];
            ++left;
        }
        ++right;
    }
    cout << Rleft << " " << Rright;
    return 0;
}