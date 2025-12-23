#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<string>

#include<set>

#include<vector>

#include<algorithm>

#include<unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
        int hash_t[128] = { 0 };
        int hash_s[128] = { 0 };
        int kinds = 0;
        for (auto& e : t)
            if (hash_t[e]++ == 0) ++kinds;
        int sz_s = s.size();
        // int sz_t = t.size();
        int re[3] = { INT_MAX, INT_MAX, INT_MAX };
        for (int right = 0, left = 0, count = 0; right < sz_s; ++right)
        {
            char in = s[right];
            if (++hash_s[in] == hash_t[in]) ++count;
            while (count == kinds)
            {
                if (right - left < re[0]) re[0] = right - left, re[1] = left, re[2] = right;
                char out = s[left++];
                if (hash_s[out]-- == hash_t[out]) --count;
            }
        }
        if (re[1] == INT_MAX && re[2] == INT_MAX) return string();
        return s.substr(re[1], re[2] - re[1] + 1);
    }
};

int main()
{
    vector<string> vec{"dddd","dddd"};
    Solution().minWindow("bba", "ab");
    return 0;
}