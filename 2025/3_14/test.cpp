//#include<bits/stdc++.h>

#include<iostream>

#include<vector>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr)
    {
        int head = 0;
        int end = arr.size() - 1;
        while (head < end)
        {
            if (arr[head] == 0)
            {
                --end;
            }
            ++head;
        }
        int dest = arr.size() - 1;
        int cur = end;
        while (cur >= 0)
        {
            if (arr[cur] == 0)
            {
                arr[dest] = arr[cur];
                --dest;
                arr[dest] = arr[cur];
                --dest;
                --cur;
            }
            else
            {
                arr[dest] = arr[cur];
                --dest;
                --cur;
            }
        }
    }
};

int main()
{
    vector<int> a{ 0,0,0,0,0,0,0};
    Solution().duplicateZeros(a);
    return 0;
}