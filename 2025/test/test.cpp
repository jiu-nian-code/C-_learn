#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<vector>

#include<map>

#include<algorithm>

using namespace std;

class Solution
{
    int hash[10];
    int ret = 0;
    int prev = INT_MIN;
public:
    int lengthOfLIS(vector<int>& nums)
    {
        memset(hash, -1, sizeof(hash));
        _lengthOfLIS(nums, 0, 0);
        return ret;
    }

    void _lengthOfLIS(vector<int>& nums, int pos, int len)
    {
        if (pos == nums.size()) return;
        if (nums[pos] > prev)
        {
            ret = max(ret, len);
            _lengthOfLIS(nums, pos + 1, len);
            if (hash[pos + 1] != -1)
            {
                ret += hash[pos + 1];
            }
            else
            {
                prev = nums[pos];
                _lengthOfLIS(nums, pos + 1, len + 1);
                hash[pos] = ret - len;
            }
        }
        else
        {
            _lengthOfLIS(nums, pos + 1, len);
        }
    }
};

int main()
{
    vector<int> tmp{ 10,9,2,5,3,7,101,18 };
    Solution().lengthOfLIS(tmp);
    return 0;
}