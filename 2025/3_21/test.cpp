#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<vector>

#include<unordered_map>

using namespace std;

string croak("croak");

class Solution
{
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        if (croakOfFrogs.size() % 5 != 0) return -1;
        int hash[26] = { 0 };
        int cnum = 0;
        int _max = 0;
        for (auto& e : croakOfFrogs)
        {
            if (e == 'c') ++cnum;
            if (e == 'k') _max = max(_max, cnum), cnum = 0;
            hash[e - 'a']++;
        }
        if (hash[0] + hash[2] == hash[10] == hash[14] == hash[17]) return _max;
        return -1;
    }
};

int main()
{
    //vector<vector<int>> arr{ {67,64,78}, { 99, 98, 38 }, { 82, 46, 46 }, { 6, 52, 55 }, { 55, 99, 45 }};
    Solution().minNumberOfFrogs("croakroak");
    //for (auto& e : croak)
    //{
    //    cout << e - 'a' << " ";
    //}
    return 0;
}