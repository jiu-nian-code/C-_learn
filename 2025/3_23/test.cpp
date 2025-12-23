#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;

class Solution
{
public:
    vector<int> tmp;
    int ret = 0;
    void _reversePairs(vector<int>& nums, int l, int r)
    {
        if (l + 1 >= r) return;
        int mid = (l + r) / 2;
        _reversePairs(nums, l, mid);
        _reversePairs(nums, mid, r);
        int i = l, j = mid;
        int cnt = 0;
        while (i < mid && j < r)
        {
            if (nums[i] > (2 * nums[j])) ret += r - j;
            if (nums[i] > nums[j]) tmp[cnt++] = nums[i++];
            else tmp[cnt++] = nums[j++];
        }
        while (i < mid)
            tmp[cnt++] = nums[i++];
        while (j < r)
            tmp[cnt++] = nums[j++];
        for (int i = 0; i < r - l; ++i)
            nums[i + l] = tmp[i];
    }

    int reversePairs(vector<int>& nums)
    {
        tmp.resize((int)nums.size(), 0);
        _reversePairs(nums, 0, nums.size());
        return ret;
    }
};

int main()
{
    vector<int> nums{1,3,2,3,1};
    Solution().reversePairs(nums);
    return 0;
}