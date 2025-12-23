#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<vector>

#include<string>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ret;
        while (left < right)//×ó¶Ëµã
        {
            int mid = left + (right - left) / 2;
            if (target <= nums[mid]) right = mid;
            else if (target > nums[mid]) left = mid + 1;
        }
        if (nums[left] == target) ret.push_back(left);
        left = 0;
        right = nums.size() - 1;
        while (left < right)//ÓÒ¶Ëµã
        {
            int mid = left + (right - left + 1) / 2;
            if (target < nums[mid]) right = mid - 1;
            else if (target >= nums[mid]) left = mid;
        }
        if (nums[left] == target) ret.push_back(left);
        return ret;
    }
};

int main()
{
    vector<int> a{5,7,7,8,8,10};
    Solution().searchRange(a, 8);
    return 0;
}