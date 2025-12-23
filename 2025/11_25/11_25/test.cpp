#include <iostream>

#include<algorithm>

using namespace std;

int main()
{
    int a, b;
    std::cin >> a >> b;
    int right = a * b;
    int left = max(a, b);
    for (int i = left; i <= right; ++i)
    {
        if (i % a == 0 && i % b == 0)
        {
            std::cout << i << std::endl;
            break;
        }
    }
    return 0;
}

class Solution {
public:

    int MLS(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        int left = 0;
        int right = 1;
        int ret = 1;
        while (right < arr.size())
        {
            int cur = arr[left];
            int num = 1;
            while (cur + 1 == arr[right] && right < arr.size())
            {
                ++right;
                ++cur;
                ++num;
            }
            ret = max(ret, num);
            left = right;
            ++right;
        }
        return ret;
    }
};

#include <iostream>

#include<vector>

#include<algorithm>

using namespace std;

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> arr(n + 1, std::vector<int>(m + 1));
    int re = 0;
    for (int i = 1; i < n + 1; ++i)
    {
        std::string str;
        std::cin >> str;
        for (int j = 1; j < m + 1; ++j)
        {
            char tmp = str[j - 1];
            int num;
            if (tmp == 'l') num = 4;
            else if (tmp == 'o') num = 3;
            else if (tmp == 'v') num = 2;
            else if (tmp == 'e') num = 1;
            else num = 0;
            // std::cout << num << " ";
            arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]) + num;
            re = max(arr[i][j], re);
        }
        // std::cout << std::endl;
    }
    std::cout << re << std::endl;

    return 0;
}