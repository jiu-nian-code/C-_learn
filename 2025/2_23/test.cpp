#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<vector>

using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int Xor = 0;
        for (auto& e : nums)
        {
            Xor ^= e;
        }
        int distinguish = Xor & ((-1) * Xor);
        vector<int> a;
        vector<int> b;
        for (auto e : nums)
        {
            if (e & distinguish)
            {
                a.push_back(e);
            }
            else
            {
                b.push_back(e);
            }
        }
        vector<int> ret;
        Xor = 0;
        for (auto& e : a)
        {
            Xor ^= e;
        }
        ret.push_back(Xor);
        Xor = 0;
        for (auto& e : b)
        {
            Xor ^= e;
        }
        ret.push_back(Xor);
        return ret;
    }
};

int main()
{
    vector<int> jiunian({ 3, 5 });
    Solution().singleNumber(jiunian);
    return 0;
}